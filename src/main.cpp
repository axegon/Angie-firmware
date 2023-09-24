#include <Arduino.h>

#include <Adafruit_SSD1306.h>

#include "constants.h"

#include "services/services.h"

DisplayImpl display;
BluetoothController * pBluetooth;

void hardwareInit() {
  vTaskDelay(100);
  Serial.begin(115200);
  display = DisplayImpl();
  Adafruit_SSD1306 disp = Adafruit_SSD1306(128, 64, & WIRE);
  display.Init(disp);
  vTaskDelay(2000);
  pBluetooth = new BluetoothImpl(5);
}

void setup() {
  hardwareInit();
}

void loop() {
  int nearby = pBluetooth -> scan();
  display.clearPrint("Nearby bt devices " + String(nearby));
  vTaskDelay(10000);
}
