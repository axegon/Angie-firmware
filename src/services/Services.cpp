#include "Services.h"
#include "DisplayService.h"
#include "BluetoothService.h"
#include "LoraService.h"
#include "WifiService.h"

void ServiceImpl::Init() {
    lora.Init();
    vTaskDelay(100);
    if (ENABLE_SERIAL) {
        Serial.begin(115200);
    }
    display.Init(Adafruit_SSD1306(128, 64, & WIRE));
    vTaskDelay(2000);
    display.clearDisplay();
    pBluetooth = new BluetoothImpl(5);
    pBluetooth->scan();
}