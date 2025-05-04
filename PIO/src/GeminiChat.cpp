#include "GeminiChat.h"
#include "WiFiManagerHandler.h"
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Arduino.h>
#include <lvgl.h>

GeminiChat::GeminiChat() : _apiKey("") {}

void GeminiChat::setApiKey(const String &apiKey) {
    _apiKey = apiKey;
}

void GeminiChat::initialize() {
    if (_apiKey.isEmpty()) {
        _apiKey = getStoredApiKey();
    }
}

// Static helper function for FreeRTOS task
void GeminiChat::sendMessageTask(void *param) {
    auto *taskParams = static_cast<std::pair<GeminiChat*, String>*>(param);
    GeminiChat *instance = taskParams->first;
    String message = taskParams->second;
    
    instance->sendMessage(message);

    delete taskParams;  // Free allocated memory
    vTaskDelete(NULL);   // Terminate the task
}

void GeminiChat::sendMessageAsync(const String &message) {
    auto *taskParams = new std::pair<GeminiChat*, String>(this, message);

    xTaskCreatePinnedToCore(
        sendMessageTask,
        "GeminiChatTask",
        4096,
        taskParams,
        1,
        NULL,
        1
    );
}

// Function to clean unwanted characters from response text
String cleanResponse(String responseText) {
    responseText.replace("* ", "");  // Remove all '* '
    responseText.replace("*", " ");  // Remove all '*'
    responseText.replace("**", "");  // Remove all '**'
    responseText.replace("#", "");  // Remove all '#'
    responseText.replace("  ", "");  // Remove all '  '
    return responseText;
}

String GeminiChat::sendMessage(const String &message) {
    if (_apiKey.isEmpty()) {
        return "API key not set. Restart if configured to resolve the issue.";
    }

    WiFiClientSecure client;
    client.setInsecure();

    HTTPClient https;
    https.setTimeout(10000);
    String url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash:generateContent?key=" + _apiKey;

    if (!https.begin(client, url)) {
        Serial.println("Failed to connect to Gemini API.");
        return "Failed to connect to Gemini API.";
    }

    https.addHeader("Content-Type", "application/json");

    DynamicJsonDocument jsonRequest(1024);
    JsonArray contents = jsonRequest.createNestedArray("contents");
    JsonObject content = contents.createNestedObject();
    JsonArray parts = content.createNestedArray("parts");
    JsonObject part = parts.createNestedObject();
    part["text"] = message;
    jsonRequest["generationConfig"]["maxOutputTokens"] = 100;

    String requestBody;
    serializeJson(jsonRequest, requestBody);
    jsonRequest.clear();

    int httpResponseCode = https.POST(requestBody);
    if (httpResponseCode != HTTP_CODE_OK) {
        https.end();
        return "HTTP request failed, code: " + String(httpResponseCode);
    }

    String response = https.getString();
    https.end();

    DynamicJsonDocument jsonResponse(2048);
    DeserializationError error = deserializeJson(jsonResponse, response);
    if (error) {
        return "JSON parsing failed";
    }

    if (jsonResponse.containsKey("candidates") && !jsonResponse["candidates"].isNull()) {
        JsonArray candidates = jsonResponse["candidates"];
        if (candidates.size() > 0) {
            JsonObject candidate = candidates[0];
            if (candidate.containsKey("content") && candidate["content"].containsKey("parts")) {
                JsonArray parts = candidate["content"]["parts"];
                if (parts.size() > 0) {
                    String textResponse = parts[0]["text"].as<String>();
                    
                    // Clean the response by removing unwanted characters
                    textResponse = cleanResponse(textResponse);
                    
                    const int maxResponseLength = 50000;
                    if (textResponse.length() > maxResponseLength) {
                        textResponse = textResponse.substring(0, maxResponseLength) + "...";
                    }

                    #ifdef ui_TextArea_AI_response
                        lv_textarea_set_text(ui_TextArea_AI_response, textResponse.c_str());
                    #endif

                    jsonResponse.clear();
                    return textResponse;
                }
            }
        }
    }

    jsonResponse.clear();
    return "Unexpected response format or no candidates found.";
}
