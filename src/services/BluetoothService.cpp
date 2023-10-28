#include "BluetoothService.h"
#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

BluetoothImpl::BluetoothImpl(int scanTime) : scanTime(scanTime) {
    BLEDevice::init("");
    pBLEScan = BLEDevice::getScan();
}

void BluetoothImpl::Init() {
    pBLEScan->setActiveScan(true);
    pBLEScan->setInterval(100);
    pBLEScan->setWindow(99);
}

int BluetoothImpl::scan() {
    int nearby_devices = 0;
    BLEScanResults foundDevices = pBLEScan->start(scanTime, false);
    Serial.print("Devices found: ");
    Serial.println(foundDevices.getCount());

    for (int i = 0; i < foundDevices.getCount(); i++) {
        nearby_devices++;
        BLEAdvertisedDevice advertisedDevice = foundDevices.getDevice(i);
        Serial.printf("Advertised Device: %s;\n", advertisedDevice.toString().c_str());
    }
    return nearby_devices;
}