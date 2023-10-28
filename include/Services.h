#ifndef SERVICE_SERVICE_H
#define SERVICE_SERVICE_H

#include "DisplayService.h"
#include "BluetoothService.h"
#include "LoraService.h"

enum Mode {
  BLUETOOTH,
  WIFI,
  LORA,
  SETUP,
  NONE,
};

class Service {
    private:
        DisplayImpl display;
        BluetoothService * pBluetooth;
        LoraControllerImpl lora;
    public:
        virtual void Init() = 0;
};

class ServiceImpl: public Service {
    protected:
        DisplayImpl display;
        BluetoothService * pBluetooth;
        LoraControllerImpl lora;
        Mode mode;
  public:
    void Init() override;
};


#endif // SERVICE_SERVICE_H
