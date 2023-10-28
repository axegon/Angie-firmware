#ifndef WIFI_SERVICE_H
#define WIFI_SERVICE_H

enum WiFiMode {
  STATION,
  ACCESS_POINT,
  STATION_AND_ACCESS_POINT,
};

class WifiService {
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

class WifiServiceImpl : public WifiService {
    protected:
        String ssid;
        String password;
        WiFiMode mode;
    
    public:
        WifiServiceImpl();
        void Init(String ssid, String password, WiFiMode mode) override;
        void Connect() override;
        void Disconnect() override;
        void Begin() override;
};




#endif // WIFI_SERVICE_H