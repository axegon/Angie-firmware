#include <SPI.h>
#include <LoRa.h>
#include "constants.h"
#include "cryptography.h"
#include "LoraService.h"


/*
 * I'm not going to bother with anything other than 868 MHz
 * since I am located in Europe and while testing out other
 * frequencies is possible, hardware-wise, I'm somewhat limited
 * and I genuenly don't feel like waiting for another shipment
 * from aliexpress for 2 months. If anyone has a spare one to
 * give it a shot, do let me know.
 */
void LoraControllerImpl::Init() {
  crypto.Init(ENCRYPTION_KEY_ADDR);
  SPI.begin(SCK, MISO, MOSI, SS);
  LoRa.setPins(SS, RST, DI0);
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
void LoraControllerImpl::tx(const String &s) {
  unsigned int length = s.length();
  byte data[length];
  for(unsigned int i = 0; i < length; i++) {
    data[i] = (byte)s[i];
  }
  crypto.encrypt(data, length);

  String encrypted = "";
  for(unsigned int i = 0; i < length; i++) {
    encrypted += (char)data[i];
  }
  LoRa.beginPacket();
  LoRa.print(s);
  LoRa.endPacket();
}

/*
 * More lazy writing....
 */
void LoraControllerImpl::rx(String &s) {
  unsigned int length = s.length();
  byte data[length];
  for(unsigned int i = 0; i < length; i++) {
    data[i] = (byte)s[i];
  }
  crypto.decrypt(data, length);
  String decrypted = "";
  for(unsigned int i = 0; i < length; i++) {
    decrypted += (char)data[i];
  }
  s = decrypted;
}