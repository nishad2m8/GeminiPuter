#include <M5Cardputer.h>
#include <lvgl.h>
#include <ui.h>
#include <ArduinoJson.h>
#include <Preferences.h>
#include "WiFiManagerHandler.h"
#include "GeminiChat.h"
#include <WiFiManager.h>
#include <algorithm> 

// Preferences preferences;
GeminiChat geminiChat;

UIScreen currentScreen = UIScreen::LOADING;
UIScreen nextScreen = UIScreen::NONE;

// Global flags
volatile bool wifiConnectedFlag = false;
volatile bool configPortalStartedFlag = false;
volatile bool apiKeySavedFlag = false; 
bool wifiConfigMessagePrinted = false;

unsigned long wifiConnectStartTime = 0;
const unsigned long wifiConnectTimeout = 10000;


unsigned long screenStartTime = 0;
bool statusScreenChecked = false;
bool webServerStarted = false;

int batteryPercentage = 0;

TaskHandle_t lvglTaskHandle = NULL;

unsigned long lastStatusCheckTime = 0;  // Last time we checked status
const unsigned long statusCheckInterval = 5000; // 5 seconds interval

bool wifiConfigured = false;
bool wifiConnected = false;
bool apiKeyConfigured = false;

// Function declarations
void lv_tick_task(void *arg);
void lvgl_task(void *arg);
void switchScreen(UIScreen screen);
void updateStatus(const String &status);
void handleEnterKey();
void resetCredentialsAndRestart();
void handleScreenTransitions();
void handleGeminiChatKeyboard();
void handleMenuNavigation();
void handleStatusScreenLogic();
void updateBattery();

void wifiSetupTask(void *pvParameters) {
    WiFiManager wm;
    wm.setConfigPortalBlocking(false); // Set non-blocking mode

    // Attempt to auto-connect
    if (!wm.autoConnect(configPortalSSID)) {  // Use the global configPortalSSID
        Serial.println("Failed to connect to WiFi and starting config portal.");
    }

    // Loop to keep the task alive and periodically process WiFiManager events
    while (!wifiConnectedFlag) {
        wm.process();  // Non-blocking WiFiManager loop to handle config portal
        if (WiFi.status() == WL_CONNECTED) {
            wifiConnectedFlag = true;
            Serial.println("WiFi Connected!");
        }
        vTaskDelay(pdMS_TO_TICKS(100)); // Yield back control for 100ms
    }
    
    vTaskDelete(NULL);  // Delete this task when WiFi is connected
}

// LVGL setup for display and tick handling
void lvgl_setup() {
    lv_init();
    static lv_disp_draw_buf_t draw_buf;
    static lv_color_t buf1[240 * 5];
    static lv_color_t buf2[240 * 5];
    lv_disp_draw_buf_init(&draw_buf, buf1, buf2, 240 * 5);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.flush_cb = [](lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p) {
        uint32_t w = area->x2 - area->x1 + 1;
        uint32_t h = area->y2 - area->y1 + 1;
        M5.Display.startWrite();
        M5.Display.setAddrWindow(area->x1, area->y1, w, h);
        M5.Display.pushPixels((uint16_t *)&color_p->full, w * h, true);
        M5.Display.endWrite();
        lv_disp_flush_ready(disp_drv);
    };
    disp_drv.hor_res = 240;
    disp_drv.ver_res = 135;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);
}

// Update status display and log to Serial
void updateStatus(const String &status) {
    lv_textarea_set_text(ui_TextArea_debug_status, (status + "\n").c_str()); // lv_textarea_add_text
    Serial.println(status);
}

// Setup function
void setup() {
    Serial.begin(115200);
    auto cfg = M5.config();
    M5Cardputer.begin(cfg, true);
    M5Cardputer.Keyboard.begin();
    cfg.serial_baudrate = 115200;
    M5.begin(cfg);

    lvgl_setup();

    Serial.println("Creating LVGL tasks...");
    xTaskCreatePinnedToCore(lv_tick_task, "lv_tick_task", 4096, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(lvgl_task, "lvgl_task", 8192, NULL, 1, &lvglTaskHandle, 1);

    ui_init();
    Serial.println("UI Initialized.");

    delay(500);

    switchScreen(UIScreen::LOADING);
    xTaskCreatePinnedToCore(wifiSetupTask, "wifiSetupTask", 8192, NULL, 1, NULL, 0);

    String storedApiKey = getStoredApiKey();
    if (!storedApiKey.isEmpty()) {
        // updateStatus("Loaded API Key from NVS.");
        geminiChat.setApiKey(storedApiKey);
    } else {
        // updateStatus("No API Key stored. Connect to WebServer to configure.");
    }

    geminiChat.initialize();
}

void lv_tick_task(void *arg) {
    while (1) {
        lv_tick_inc(10);
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void lvgl_task(void *arg) {
    while (1) {
        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

// Handle screen transitions and manage nextScreen logic
void handleScreenTransitions() {
    if (nextScreen != UIScreen::NONE) {
        switchScreen(nextScreen);  // Call switchScreen with nextScreen value
        nextScreen = UIScreen::NONE;  // Reset nextScreen to avoid repeated calls
    }

    switch (currentScreen) {
        case UIScreen::LOADING:
            if (millis() - screenStartTime > 5000) {
                switchScreen(UIScreen::STATUS);  // Transition to STATUS after loading
            }
            break;
        case UIScreen::STATUS:
            handleStatusScreenLogic();  // Execute status screen logic
            break;
        default:
            break;
    }
}

void switchScreen(UIScreen screen) {
    if (currentScreen == screen) return;

    currentScreen = screen;
    screenStartTime = millis();

    String ipAddress;

    switch (screen) {
        case UIScreen::LOADING:
            lv_scr_load(ui_Screen_loading);
            break;
        case UIScreen::STATUS:
            lv_scr_load(ui_Screen_status);
            break;
        case UIScreen::GEMINI_CHAT:
            lv_scr_load(ui_Screen_AiChat);
            break;
        case UIScreen::MENU:
            lv_scr_load(ui_Screen_Menu);
                       
            ipAddress = getIPAddress();
            lv_label_set_text(ui_Label_ip, ipAddress.c_str());

            updateBattery();
            lv_bar_set_value(ui_Bar_Battery, batteryPercentage, LV_ANIM_ON);

            lv_obj_clear_state(ui_Button_reset, LV_STATE_FOCUSED);
            lv_obj_clear_state(ui_Button_back, LV_STATE_FOCUSED);
            break;
        default:
            Serial.println("Invalid screen transition requested.");
            break;
    }
}

void handleStatusScreenLogic() {
    WiFiManager wm;

    // Step 1: Check if Wi-Fi is connected
    if (WiFi.status() != WL_CONNECTED && !wifiConnectedFlag) {
        if (!wifiConfigMessagePrinted) {
            updateStatus("Connecting...");
            delay(2000);

            // Print config message and start connection attempt time
            updateStatus("Connect to \n\"" + String(configPortalSSID) + "\"\nto configure Wi-Fi.");
            wifiConfigMessagePrinted = true;
            wifiConnectStartTime = millis();
        }

        return;
    } 
    else if (WiFi.status() == WL_CONNECTED && !wifiConnected) {
        // When connected, update the status and reset relevant flags
        updateStatus("Wi-Fi connected.");
        wifiConnected = true;
        wifiConfigMessagePrinted = false;
        delay(2000);
    }

    // Step 2: Check API Key configuration only if Wi-Fi is connected
    String apiKey = getStoredApiKey();
    String ipAddress = getIPAddress(); 

    if (apiKey.isEmpty() && !apiKeyConfigured) {
        updateStatus("Set API key at\n\"" + ipAddress + "\"\nRestart if fails.");
        if (!webServerStarted) {
            startWebServer(); // Ensure routes and handlers are initialized once
            webServerStarted = true;
        }
        delay(2000);
        return;
    } else if (!apiKey.isEmpty()) {
        apiKeyConfigured = true;  // Only set true if API key is valid
    }

    // Step 3: Transition to chat screen if all checks pass
    if (wifiConnected && apiKeyConfigured) {
        updateStatus("All set. Switching to Gemini screen.");
        delay(3000);
        switchScreen(UIScreen::GEMINI_CHAT);
    }
}

// Helper function to return the correct character when Shift is pressed
char getShiftedChar(uint8_t keyCode) {
    switch (keyCode) {
        case '=': return '+';   // Shift + '=' should be '+'
        case '9': return '(';   // Shift + '9' should be '('
        case '8': return '*';   // Shift + '8' should be '*'
        // Add more cases as needed for other Shifted characters
        default: return keyCode; // Return the original character if no special Shift function
    }
}

void handleGeminiChatKeyboard() {
    if (M5Cardputer.Keyboard.isChange() && M5Cardputer.Keyboard.isPressed()) {
        Keyboard_Class::KeysState status = M5Cardputer.Keyboard.keysState();

        static bool focusChatInput = true;

        // Toggle focus between AI response and chat input using KEY_TAB
        if (M5Cardputer.Keyboard.isKeyPressed(KEY_TAB) && !status.shift) {
            Serial.println("Tab key pressed - Toggling focus.");
            if (focusChatInput) {
                lv_obj_add_state(ui_TextArea_AI_response, LV_STATE_FOCUSED);
                lv_obj_clear_state(ui_TextArea_chat_input, LV_STATE_FOCUSED);
                lv_textarea_set_cursor_pos(ui_TextArea_AI_response, 0); // Start at the top
            } else {
                lv_obj_add_state(ui_TextArea_chat_input, LV_STATE_FOCUSED);
                lv_obj_clear_state(ui_TextArea_AI_response, LV_STATE_FOCUSED);
            }
            focusChatInput = !focusChatInput;
            return;
        }

        static unsigned long lastScrollTime = 0;
        unsigned long currentTime = millis();

        // Scroll when ui_TextArea_AI_response is focused
        if (!focusChatInput && status.fn) {
            if (currentTime - lastScrollTime > 100) {
                if (std::find(status.word.begin(), status.word.end(), ';') != status.word.end()) {
                    // Scroll up
                    lv_textarea_cursor_up(ui_TextArea_AI_response);
                    Serial.println("Scrolling up in AI response textarea");

                } else if (std::find(status.word.begin(), status.word.end(), '.') != status.word.end()) {
                    // Scroll down
                    lv_textarea_cursor_down(ui_TextArea_AI_response);
                    Serial.println("Scrolling down in AI response textarea");
                }
                lastScrollTime = currentTime;
            }
        }

        // Handle typing and deletion in chat input
        else if (focusChatInput) {
            if (M5Cardputer.Keyboard.isKeyPressed(0x28) && !status.shift) {
                handleEnterKey();
            } else if (M5Cardputer.Keyboard.isKeyPressed(0x2A) && !status.shift) {
                lv_textarea_del_char(ui_TextArea_chat_input);
            } else {
                for (uint8_t keyCode = 32; keyCode <= 126; keyCode++) {
                    if (M5Cardputer.Keyboard.isKeyPressed(keyCode)) {
                        char inputChar = keyCode;
                        if (status.shift) {
                            inputChar = getShiftedChar(keyCode);
                        }
                        lv_textarea_add_char(ui_TextArea_chat_input, inputChar);
                    }
                }
            }
        }
    }
}


// Handle navigation for MENU screen
void handleMenuNavigation() {
    // Keep track of which button is currently focused
    static lv_obj_t *focusedButton = ui_Button_reset;

    // Check if there is a keyboard state change and if a key is pressed
    if (M5Cardputer.Keyboard.isChange() && M5Cardputer.Keyboard.isPressed()) {
        Keyboard_Class::KeysState status = M5Cardputer.Keyboard.keysState();

        // Handle navigation to move up or down using ';' and '.' keys with a toggle state check
        if (M5Cardputer.Keyboard.isKeyPressed(';')) { // Move up
            Serial.println("Moving focus up in menu.");
            lv_obj_clear_state(focusedButton, LV_STATE_FOCUSED);
            focusedButton = (focusedButton == ui_Button_back) ? ui_Button_reset : ui_Button_back;
            lv_obj_add_state(focusedButton, LV_STATE_FOCUSED);
        } else if (M5Cardputer.Keyboard.isKeyPressed('.')) { // Move down
            Serial.println("Moving focus down in menu.");
            lv_obj_clear_state(focusedButton, LV_STATE_FOCUSED);
            focusedButton = (focusedButton == ui_Button_reset) ? ui_Button_back : ui_Button_reset;
            lv_obj_add_state(focusedButton, LV_STATE_FOCUSED);
        } 

        // Handle the Enter key to activate the focused button
        else if (M5Cardputer.Keyboard.isKeyPressed(0x28)) { // Enter key
            Serial.println("Enter key pressed - Selecting focused button.");
            if (focusedButton == ui_Button_reset) {
                Serial.println("Reset button selected.");
                resetCredentialsAndRestart();
            } else if (focusedButton == ui_Button_back) {
                Serial.println("Back button selected.");
                nextScreen = UIScreen::GEMINI_CHAT; // Navigate back to GEMINI_CHAT screen
            }
        }
    }
}

void resetCredentialsAndRestart() {
    // Disconnect Wi-Fi and erase Wi-Fi credentials
    WiFi.disconnect(true, true);  // true, true forces credentials deletion
    delay(1000);  // Allow time for Wi-Fi stack to handle disconnection

    // Delete the API key from NVS
    preferences.begin("config", false);
    preferences.remove("apikey");
    preferences.end();
    Serial.println("API Key deleted from NVS.");

    // Provide user feedback and restart
    lv_label_set_text(ui_Label_info, "Credentials reset!");
    delay(1000);
    lv_label_set_text(ui_Label_info, "Restarting...");
    delay(2000);  // Allow message to be visible before restart
    ESP.restart();  // Restart the device
}


void handleEnterKey() {
    const char *inputText = lv_textarea_get_text(ui_TextArea_chat_input);

    if (inputText != nullptr && strlen(inputText) > 0) {
        String inputString = String(inputText);

        if (inputString.length() > 1024) {
            updateStatus("Error: Input too long!");
            Serial.println("Error: Input too long!");
            return;
        }

        Serial.println("Sending message to Gemini API...");
        lv_textarea_set_text(ui_TextArea_chat_input, "");
        lv_textarea_set_text(ui_TextArea_AI_response, "Thinking...");

        String response = geminiChat.sendMessage(inputString);
        if (response.length() > 0) {
            lv_textarea_set_text(ui_TextArea_AI_response, response.c_str());
        } else {
            updateStatus("Error: No response from Gemini API.");
            Serial.println("Error: No response received from Gemini API.");
        }
    } else {
        updateStatus("Error: Input is empty.");
        Serial.println("Error: No input to send.");
    }
}

void loop() {
    handleScreenTransitions();
    M5Cardputer.update();

    switch (currentScreen) {
        case UIScreen::GEMINI_CHAT:
            handleGeminiChatKeyboard();
            break;
        case UIScreen::MENU:
            handleMenuNavigation();
            break;
        default:
            break;
    }

    // Check if KEY_OPT is pressed and set to MENU screen if so
    if (M5Cardputer.Keyboard.isKeyPressed(KEY_OPT)) {
        delay(100);  // Add debounce delay
        nextScreen = UIScreen::MENU;  // Set for screen transition
        Serial.println("KEY_OPT pressed, switching to MENU screen");
    }

    delay(5);
    yield();
}

void updateBattery() {
    // Get the current battery voltage
    float batteryVoltage = M5.Power.getBatteryVoltage() / 1000.0; // Convert mV to V

    // Normalize the battery voltage to a percentage (assume 3.2V - 4.2V is 0% - 100%)
    batteryPercentage = (int)(((batteryVoltage - 3.3) / (4.2 - 3.3)) * 100);

    // Ensure the battery percentage is within 0-100 range
    batteryPercentage = constrain(batteryPercentage, 0, 100);

    // Update the LVGL battery bar UI with the new value
    // lv_bar_set_value(ui_Bar_Battery, batteryPercentage, LV_ANIM_ON);

    // Serial debug output
    Serial.println();
    Serial.print("Battery Voltage: ");
    Serial.print(batteryVoltage, 2);  // Print voltage in volts with 2 decimal places
    Serial.print("V, Battery Percentage: ");
    Serial.print(batteryPercentage);
    Serial.println("%");
}
