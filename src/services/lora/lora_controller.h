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

/*
 * I'm not going to bother with anything other than 868 MHz
 * since I am located in Europe and while testing out other
 * frequencies is possible, hardware-wise, I'm somewhat limited
 * and I genuenly don't feel like waiting for another shipment
 * from aliexpress for 2 months. If anyone has a spare one to
 * give it a shot, do let me know.
 */
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

        /*
         * tx is just lazy writing at this stage but it is
         * what it is. All packages will go through the
         * Caesar cypher.
         * 
         * 
         * 
         * Ave Caesar! Morituri te salutant!
         */
        void tx(const String & s) override {
            String encrypted = s;
            crypto.encrypt(encrypted);
            LoRa.beginPacket();
            LoRa.print(encrypted);
            LoRa.endPacket();
        }

        /*
         * More lazy writing....
         */
        void rx(const String & s) override {
            String decrypted = s;
            crypto.decrypt(decrypted);
        }
    };
    