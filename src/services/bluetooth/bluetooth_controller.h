#include <Arduino.h>

#include <BLEDevice.h>

#include <BLEUtils.h>

#include <BLEScan.h>

#include <BLEAdvertisedDevice.h>


class BluetoothController {
  public: 
    virtual void Init() = 0;
    virtual int scan() = 0;
};

class BluetoothImpl: public BluetoothController {
  private:
    BLEScan * pBLEScan;
    int scanTime;
  public:
    BluetoothImpl(int scanTime): scanTime(scanTime) {
      BLEDevice::init("");
      pBLEScan = BLEDevice::getScan();
    }

    void Init() override {
      pBLEScan -> setActiveScan(true);
      pBLEScan -> setInterval(100);
      pBLEScan -> setWindow(99);
    }

    int scan() override {
      BLEScanResults foundDevices = pBLEScan -> start(scanTime, false);
      int nearby_devices = foundDevices.getCount();
      Serial.print("Devices found: ");
      Serial.println(nearby_devices);

      for (int i = 0; i < foundDevices.getCount(); i++) {
        BLEAdvertisedDevice advertisedDevice = foundDevices.getDevice(i);

        Serial.printf("Advertised Device: %s;\n", advertisedDevice.toString().c_str());
      }
      return nearby_devices;
  }
};
