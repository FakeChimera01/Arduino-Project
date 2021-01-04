#include <WiFiManager.h> // For more information visit :https://github.com/tzapu/WiFiManager

void setup() {
    WiFi.mode(WIFI_STA);
    Serial.begin(115200);
    WiFiManager wm;
    //reset settings - wipe credentials for testing
    //wm.resetSettings();
    bool res;
    res = wm.autoConnect("AutoConnectAP","password"); // password protected ap

    if(!res) {
        Serial.println("Failed to connect");
        // ESP.restart();
    } 
    else {
        Serial.println("connected...yeey :)");
    }
}

void loop() {    
}
