#include <EEPROM.h>


class EEPROMController {
private:
    virtual void checkState(int addr) = 0;
};