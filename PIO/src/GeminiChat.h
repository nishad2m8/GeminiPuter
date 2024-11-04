#ifndef GEMINICHAT_H
#define GEMINICHAT_H

#include <Arduino.h>

class GeminiChat {
public:
    GeminiChat();
    void setApiKey(const String &apiKey);
    void initialize();
    void sendMessageAsync(const String &message);
    String sendMessage(const String &message);

private:
    String _apiKey;

    // Declare the static helper function for FreeRTOS task
    static void sendMessageTask(void *param);
};

#endif
