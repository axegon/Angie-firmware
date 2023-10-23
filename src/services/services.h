#include <EEPROM.h>
#include "display/display_controller.h"
#include "bluetooth/bluetooth_controller.h"
#include "lora/lora_controller.h"


enum Mode {
  BLUETOOTH,
  WIFI,
  LORA,
  SETUP,
  NONE,
};

class ServicesController {
  private: 
    virtual void bootsplash() = 0;
  public: 
    virtual void Init(int eeprom_addr) = 0;
    virtual void encrypt(const String & s) = 0;
    virtual void decrypt(const String & s) = 0;
};

class ServicesControllerImpl: public ServicesController {
  private:
    Mode mode;
  public:
    void Init(int eeprom_addr) override {
      EEPROM.begin(4);
        Mode mode = static_cast<Mode>(EEPROM.read(eeprom_addr));
        EEPROM.end();

        if (mode < BLUETOOTH || mode > LORA) mode = Mode::SETUP;
    }
};




void writeModeToEEPROM(Mode mode, int addr) {
  EEPROM.begin(4);
  EEPROM.write(addr, static_cast<int>(mode));
  EEPROM.commit();
  EEPROM.end();
}

Mode readModeFromEEPROM(int addr) {
  EEPROM.begin(4);
  Mode mode = static_cast<Mode>(EEPROM.read(addr));
  EEPROM.end();

  if (mode < BLUETOOTH || mode > LORA) return NONE;
  return mode;
}