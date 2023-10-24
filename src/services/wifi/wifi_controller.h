#include <WiFi.h>

enum WiFiMode {
  STATION,
  ACCESS_POINT,
  STATION_AND_ACCESS_POINT,
};

class WifiController {
  protected:
    String ssid;
    String password;
    WiFiMode mode;
  public: 
    virtual void Init(String ssid, String password, WiFiMode mode) = 0;
    virtual void Connect() = 0;
    virtual void Disconnect() = 0;
    virtual void Begin() = 0;
};

class WifiControllerImpl: public WifiController {
  public:
    void Init(String ssid, String password, WiFiMode mode) override {
      this->ssid = ssid;
      this->password = password;
      this->mode = mode;
    }

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

    void Disconnect() override {
      WiFi.disconnect();
      Serial.println("Disconnected from WiFi");
    }

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
