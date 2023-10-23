#include <SPI.h>
#include <LoRa.h>
#include "constants.h"
#include "cryptography.h"

#define WIRE Wire

class LoraController {
  public: 
    virtual void Init() = 0;
    virtual void tx(const String & s) = 0;
    virtual void rx(const String & s) = 0;
};

class LoraControllerImpl: public LoraController {
    private:
        CryptographyImpl crypto;
    public:
        void Init() override {
            crypto.Init(ENCRYPTION_KEY_ADDR);
            SPI.begin(SCK,MISO,MOSI,SS);
            LoRa.setPins(SS,RST,DI0);
            if (!LoRa.begin(868E6)) {
                Serial.println("Starting LoRa failed!");
                while (1);
            }
        }

        void tx(const String & s) override {
            String encrypted = s;
            crypto.encrypt(encrypted);
            LoRa.beginPacket();
            LoRa.print(encrypted);
            LoRa.endPacket();
        }

        void rx(const String & s) override {
            String decrypted = s;
            crypto.decrypt(decrypted);
        }
    };
    