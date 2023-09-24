#include <Arduino.h>

#include "AESLib.h"

#define INPUT_BUFFER_LIMIT (128 + 1)

class CryptographyController {
  public: virtual void encrypt(const String & s, String & out) = 0;
  virtual void decrypt(const String & s, String & out) = 0;
};

class CryptographyImpl: public CryptographyController {
  private: byte encryption_key[16];
  byte aes_iv[N_BLOCK];
  AESLib aesLib;

  public: CryptographyImpl(const String & key) {
    for (int i = 0; i < 16 && i < key.length(); i++) {
      encryption_key[i] = key.charAt(i);
    }
    memset(aes_iv, 0xAA, N_BLOCK);
  }

  void encrypt(const String & s, String & out) override {
    unsigned char ciphertext[2 * INPUT_BUFFER_LIMIT] = {
      0
    };
    uint16_t encLen = aesLib.encrypt((byte * ) s.c_str(), s.length(), ciphertext, encryption_key, sizeof(encryption_key), aes_iv);
    out = String((char * ) ciphertext);
  }

  void decrypt(const String & s, String & out) override {
    unsigned char cleartext[INPUT_BUFFER_LIMIT] = {
      0
    };
    uint16_t decLen = aesLib.decrypt((byte * ) s.c_str(), s.length(), cleartext, encryption_key, sizeof(encryption_key), aes_iv);
    out = String((char * ) cleartext);
  }
};