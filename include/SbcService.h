#ifndef SBC_SERVICE_H
#define SBC_SERVICE_H
#include <Arduino.h>

/*
 * I have a slight suspicion I'm going to hate my life here. Oh well...
 */
class SingleBoardService {
  private:
    HardwareSerial * pSerial;
  public: 
    virtual void Init() = 0;
    virtual void powerOn() = 0;
    virtual void powerOff() = 0;
    virtual void reboot() = 0;
    virtual void connectToWiFi(const String & ssid, const String & s) = 0;
    virtual void disconnectFromWiFi() = 0;
    virtual void sendCommand(const String & s) = 0;
};

class SingleBoardServiceImpl : public SingleBoardService {
  private:
    HardwareSerial * pSerial;
  public:
    void Init() override;
    void powerOn() override;
    void powerOff() override;
    void reboot() override;
    void connectToWiFi(const String & ssid, const String & s) override;
    void disconnectFromWiFi() override;
    void sendCommand(const String & s) override;
};

#endif // SBC_SERVICE_H