#include <Arduino.h>
#include <EEPROM.h>
#include "constants.h"


class Cryptography {
  public: 
    virtual void Init(int eepromAddr) = 0;
    virtual void encrypt(String & s) = 0;
    virtual void decrypt(String & s) = 0;
    virtual void setEncryptionKey(byte newKey) = 0;
};

/*
 * In all honesty, encryption might be a very strong statement here. 
 * In reality this is nothing more than a Ceaser cypher but the available
 * memory is a fair bit less than I would need to run something like AES
 * or better yet an asymmetric encryption(which I'd love to in an ideal
 * world but for the purpose this will have to do). I am considering some
 * pseudo-random algorithm based on environment sensors and some sort of
 * hash ring but that is a bit I'm kicking that can down the road to 
 * future me.
 * 
 * Future me: I'm a time traveler, I'm here to tell you to go fuck yourself.
 */
class CryptographyImpl: public Cryptography {
  private:
    byte encryptionKey;

  public: 
    void Init(int eepromAddr) override {
      encryptionKey = EEPROM.read(ENCRYPTION_KEY_ADDR);
    }
    
    /*
     * As Brian Johnson once faimously sang: 
     * "Women to the left of me."
     */
    void encrypt(String & s) override {
      Serial.println(encryptionKey);
      for (unsigned int i = 0; i < s.length(); i++) {
        s[i] = s[i] + encryptionKey;
      }
    }
    
    /*
     *  "...And women to the right"
     */
    void decrypt(String & s) override {
      for (unsigned int i = 0; i < s.length(); i++) {
        s[i] = s[i] - encryptionKey;
      }
    }

    /**
     * I'll figure this later.
     */
    void setEncryptionKey(byte newKey) {
      encryptionKey = newKey;
      EEPROM.write(ENCRYPTION_KEY_ADDR, encryptionKey);
    }
};
