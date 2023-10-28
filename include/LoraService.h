#ifndef LORA_SERVICE_H
#define LORA_SERVICE_H

#include "cryptography.h"

class LoraController {
  public:
    virtual void Init() = 0;
    virtual void tx(const String &s) = 0;
    virtual void rx(String &s) = 0;
};

class LoraControllerImpl : public LoraController {
  private:
    CryptographyImpl crypto;

  public:
    void Init() override;
    void tx(const String &s) override;
    void rx(String &s) override;
};

#endif // LORA_SERVICE_H