#include "WiFiManagerHandler.h"
#include <WiFi.h>
#include <WiFiManager.h>
#include <ESPAsyncWebServer.h>
#include <Preferences.h> 
#include <Arduino.h>
#include "ui.h"

Preferences preferences;  // Create an instance of Preferences

// Initialize WebServer and Global Variables
AsyncWebServer server(80);
String storedApiKey = "";
const char* configPortalSSID = "GeminiPuter-Setup";

// Flags for Wi-Fi and API key status
extern volatile bool wifiConnectedFlag;
extern volatile bool configPortalStartedFlag;
extern volatile bool apiKeySavedFlag;


// Initialize Wi-Fi Manager with Auto-Connect and Timeout
void setupWiFiManager() {
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("Wi-Fi already connected.");
        wifiConnectedFlag = true;
        return;
    }

    WiFiManager wifiManager;
    wifiManager.setConfigPortalTimeout(180);  // 3-minute timeout for config portal

    // Attempt to connect or start the config portal
    if (!wifiManager.autoConnect(configPortalSSID)) {
        wifiConnectedFlag = false;
        Serial.println("Config Portal timed out or no credentials found.");
    } else {
        IPAddress ip = WiFi.localIP();
        wifiConnectedFlag = true;
        Serial.println("Wi-Fi Connected: " + ip.toString());
    }
}

// Start Web Server for API Key Configuration
void startWebServer() {
    // Endpoint for serving the API Key input form
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        String html = "<!DOCTYPE html><html><head><title>Configure API Key</title>"
                      "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
                      "<style>"
                      "body { font-family: Arial, sans-serif; text-align: center; margin: 0; padding: 0; }"
                      "h3 { color: #333; margin-top: 20px; }"
                      "form { display: inline-block; max-width: 90%; width: 400px; margin-top: 20px; }"
                      "input[type='text'] { width: 100%; padding: 12px; margin-top: 10px; font-size: 16px; box-sizing: border-box; }"
                      "input[type='submit'] { width: 100%; padding: 12px; margin-top: 15px; background-color: #4CAF50; "
                      "color: white; border: none; font-size: 16px; cursor: pointer; box-sizing: border-box; }"
                      "input[type='submit']:hover { background-color: #45a049; }"
                      "p { color: #666; font-size: 14px; margin-top: 20px; }"
                      "@media (max-width: 600px) {"
                      "  h3 { font-size: 20px; }"
                      "  input[type='text'], input[type='submit'] { font-size: 14px; padding: 10px; }"
                      "  p { font-size: 12px; }"
                      "}"
                      "</style></head><body>"
                      "<h3>Configure Gemini API Key</h3>"
                      "<h4>Get <a href='https://aistudio.google.com/app/apikey' target='_blank'>API Key</a></h4>"
                      "<form action='/save' method='POST'>"
                      "<label>Enter API Key:</label><br>"
                      "<input type='text' name='apiKey' required><br><br>"
                      "<input type='submit' value='Save API Key'></form>"
                      "<p>Note: After saving, restart the device.</p>"
                      "<p>Created by <a href='https://www.youtube.com/@nishad2m8' target='_blank'>nishad2m8</a></p>"
                      "</body></html>";
        request->send(200, "text/html", html);
    });

    // Endpoint for saving API Key in SPIFFS and providing user feedback
    server.on("/save", HTTP_POST, [](AsyncWebServerRequest *request) {
        if (request->hasParam("apiKey", true)) {
            String apiKey = request->getParam("apiKey", true)->value();
            if (saveApiKey(apiKey)) {  // Check success from saveApiKey()
                request->send(200, "text/html", "<!DOCTYPE html><html><head><title>API Key Saved</title>"
                                                 "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
                                                 "<style>body { font-family: Arial, sans-serif; text-align: center; margin-top: 50px; }</style>"
                                                 "</head><body><h3>API Key saved successfully!</h3>"
                                                 "<p>You may restart the device or return to the main screen.</p></body></html>");
                apiKeySavedFlag = true;
                Serial.println("API Key saved.");
            } else {
                request->send(500, "text/html", "Error saving API Key! Please try again.");
            }
        } else {
            request->send(400, "text/html", "API Key not provided!");
        }
    });

    // Optional endpoint to view current API Key status
    server.on("/status", HTTP_GET, [](AsyncWebServerRequest *request) {
        String status = apiKeySavedFlag ? "<p>API Key is saved.</p>" : "<p>No API Key saved.</p>";
        request->send(200, "text/html", status);
    });

    // Handle undefined routes
    server.onNotFound([](AsyncWebServerRequest *request){
        request->send(404, "text/plain", "404: Not Found");
    });

    server.begin();
    Serial.println("WebServer started successfully.");
}

// Save API Key to NVS and return success status
bool saveApiKey(const String &apiKey) {
    preferences.begin("config", false); // Open "config" namespace in NVS

    bool success = preferences.putString("apikey", apiKey); // Save API key under "apikey"
    preferences.end(); // Close the NVS namespace

    if (success) {
        Serial.println("API Key saved successfully in NVS.");
    } else {
        Serial.println("Failed to save API Key in NVS.");
    }

    return success;
}

// Retrieve Stored API Key from NVS
String getStoredApiKey() {
    preferences.begin("config", true); // Open "config" namespace in read-only mode

    String apiKey = preferences.getString("apikey", ""); // Retrieve the API key, defaulting to an empty string if not found
    preferences.end(); // Close the NVS namespace

    if (apiKey.isEmpty()) {
        Serial.println("No API Key stored in NVS.");
    } else {
        Serial.println("API Key retrieved from NVS.");
    }

    return apiKey;
}

// Retrieve Current IP Address as a String
String getIPAddress() {
    if (WiFi.status() == WL_CONNECTED) {
        return WiFi.localIP().toString();
    } else {
        return "Not Connected";
    }
}
