#include <EEPROM.h>
#include "display/display_controller.h"
#include "bluetooth/bluetooth_controller.h"
#include "lora/lora_controller.h"
#include "wifi/wifi_controller.h"


enum Mode {
  BLUETOOTH,
  WIFI,
  LORA,
  SETUP,
  NONE,
};

class Services {
  private:
    DisplayImpl display;
    BluetoothController * pBluetooth;
    LoraControllerImpl lora;
  public: 
    virtual void Init() = 0;
};

class ServicesImpl: public Services {
protected:
    DisplayImpl display;
    BluetoothController * pBluetooth;
    LoraControllerImpl lora;
    Mode mode;
  public:
    void Init() override {
        lora.Init();
        vTaskDelay(100);
        Serial.begin(115200);
        display.Init(Adafruit_SSD1306(128, 64, & WIRE));
        vTaskDelay(2000);
        display.clearDisplay();
        pBluetooth = new BluetoothImpl(5);
    }
};