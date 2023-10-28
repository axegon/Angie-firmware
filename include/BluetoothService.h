#ifndef BLUETOOTH_SERVICE_H
#define BLUETOOTH_SERVICE_H

#include <BLEScan.h>

class BluetoothService {
  public:
    virtual void Init() = 0;
    virtual int scan() = 0;
};

class BluetoothImpl : public BluetoothService {
  private:
    int scanTime;
    BLEScan *pBLEScan;

  public:
    BluetoothImpl(int scanTime);
    void Init() override;
    int scan() override;
};

#endif // BLUETOOTH_SERVICE_H