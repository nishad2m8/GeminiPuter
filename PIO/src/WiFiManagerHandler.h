#ifndef WIFIMANAGERHANDLER_H
#define WIFIMANAGERHANDLER_H

#include <WiFi.h>
#include <WiFiManager.h>
#include <ESPAsyncWebServer.h>
#include <Preferences.h>
#include <Arduino.h>

enum class UIScreen {
    LOADING,
    STATUS,
    GEMINI_CHAT,
    MENU,
    NONE
};

extern UIScreen nextScreen;

// Declare the global flags as extern
extern volatile bool wifiConnectedFlag;
extern volatile bool configPortalStartedFlag;
extern Preferences preferences;
extern volatile bool apiKeySavedFlag;
extern const char* configPortalSSID;

// Use only one declaration for saveApiKey with a bool return type
bool saveApiKey(const String &apiKey);

// Declare shared functions
void setupWiFiManager();
void startWebServer();
String getStoredApiKey();
String getIPAddress();

#endif  // WIFIMANAGERHANDLER_H
