#include <Arduino.h>
#include <EEPROM.h>


class CryptographyController {
  public: 
    virtual void Init(int eepromAddr) = 0;
    virtual void encrypt(String & s) = 0;
    virtual void decrypt(String & s) = 0;
    virtual void setEncryptionKey(byte newKey) = 0;
};
class CryptographyImpl: public CryptographyController {
  private:
    int EEPROM_ADDRESS = 0;
    byte encryptionKey;

  public: 
    void Init(int eepromAddr) override {
      EEPROM_ADDRESS = eepromAddr;
      encryptionKey = EEPROM.read(EEPROM_ADDRESS);
    }
    
    void encrypt(String & s) override {
      for (unsigned int i = 0; i < s.length(); i++) {
        s[i] = s[i] + encryptionKey;
      }
    }
    
    void decrypt(String & s) override {
      for (unsigned int i = 0; i < s.length(); i++) {
        s[i] = s[i] - encryptionKey;
      }
    }

    void setEncryptionKey(byte newKey) {
      encryptionKey = newKey;
      EEPROM.write(EEPROM_ADDRESS, encryptionKey);
    }
};