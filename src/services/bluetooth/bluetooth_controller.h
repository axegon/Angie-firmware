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
  private: BLEScan * pBLEScan;
  int scanTime;
  public: BluetoothImpl(int scanTime): scanTime(scanTime) {
    BLEDevice::init("");
    pBLEScan = BLEDevice::getScan();
  }

  void Init() override {
    pBLEScan -> setActiveScan(true);
    pBLEScan -> setInterval(100);
    pBLEScan -> setWindow(99);
  }

  int scan() override {
    int nearby_devices = 0;
    BLEScanResults foundDevices = pBLEScan -> start(scanTime, false);
    Serial.print("Devices found: ");
    Serial.println(foundDevices.getCount());

    for (int i = 0; i < foundDevices.getCount(); i++) {
      nearby_devices++;
      BLEAdvertisedDevice advertisedDevice = foundDevices.getDevice(i);

      Serial.printf("Advertised Device: %s;\n", advertisedDevice.toString().c_str());
    }
    return nearby_devices;
  }
};