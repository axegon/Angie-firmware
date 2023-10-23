#include <Arduino.h>

class SingleBoardController {
  public: 
    virtual void Init() = 0;
    virtual void powerOn() = 0;
    virtual void powerOff() = 0;
    virtual void reboot() = 0;
    virtual void connectToWiFi(const String & ssid, const String & s) = 0;
    virtual void disconnectFromWiFi() = 0;
    virtual void sendCommand(const String & s) = 0;
};