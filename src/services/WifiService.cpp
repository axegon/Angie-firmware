#include <Arduino.h>
#include <WiFi.h>
#include "WifiService.h"

/*
 * I haven't fully figured out this part or what I want to do with it yet.
 * For starters, most SBC's have a built in WiFi and bluetooth for that
 * matter. It would be cool if I can figure out how to relay the traffic
 * from the SBC to the ESP32 and vice versa. I'mma cross that bridge when
 * I get there.
 */
class WifiControllerImpl: public WifiService {
  public:
    void Init(String ssid, String password, WiFiMode mode) override {
      this->ssid = ssid;
      this->password = password;
      this->mode = mode;
    }

    /*
     * This should work. Keyword: "should".
     */
    void Connect() override {
      if (mode == STATION || mode == STATION_AND_ACCESS_POINT) {
        WiFi.begin(ssid.c_str(), password.c_str());
        Serial.println("Connecting to WiFi...");
        while (WiFi.status() != WL_CONNECTED) {
          delay(1000);
          Serial.println("Connecting...");
        }
        Serial.println("Connected!");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
      }
    }

    /*
     * Same as above.
     */
    void Disconnect() override {
      WiFi.disconnect();
      Serial.println("Disconnected from WiFi");
    }

    /*
     * Same as above ++.
     */
    void Begin() override {
      if (mode == ACCESS_POINT || mode == STATION_AND_ACCESS_POINT) {
        WiFi.softAP(ssid.c_str(), password.c_str());
        Serial.println("Access Point Started");
        Serial.print("IP Address: ");
        Serial.println(WiFi.softAPIP());
      }

      if (mode == STATION || mode == STATION_AND_ACCESS_POINT) {
        Connect();
      }
    }
};