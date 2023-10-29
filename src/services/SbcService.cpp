#include <HardwareSerial.h>
#include "SbcService.h"
#include "constants.h"

/*
 * Hacky? Yes. Do I care? No. Now for the fun part: To get something
 * to be able to read and understand this gibberish on the other end.
 * Luckily Rust is an option there so my desire to jump off a cliff will
 * be dialed down a notch.
 */

void SingleBoardServiceImpl::Init() {
    pSerial->begin(115200, SERIAL_8N1, UART_RX, UART_TX);
    Serial.println("SbcServiceImpl::Init()");
    pinMode(MOSFET, OUTPUT);
}

/*
 * Forgive me father for I have sinned. Not really though, that's
 * a common occurence.
 */
void SingleBoardServiceImpl::powerOn() {
    Serial.println("SbcServiceImpl::powerOn()");
    digitalWrite(MOSFET, HIGH);
}

/*
 * More sins...
 */
void SingleBoardServiceImpl::powerOff()  {
    Serial.println("SbcServiceImpl::powerOn()");
    digitalWrite(MOSFET, LOW);
};

/*
 * More more sins...
 */
void SingleBoardServiceImpl::reboot() {
    Serial.println("SbcServiceImpl::reboot()");
    powerOff();
    vTaskDelay(500);
    powerOn();
};


/*
 * More more more sins...
 */
void SingleBoardServiceImpl::connectToWiFi(const String & ssid, const String & password) {
    Serial.println("SbcServiceImpl::connectToWiFi()");
    pSerial->print("wifi::connect");
    pSerial->write('\0');
    pSerial->print(ssid);
    pSerial->write('\0');
    pSerial->println(password);
}

/*
 * More more more more sins...
 */
void SingleBoardServiceImpl::disconnectFromWiFi() {
    Serial.println("SbcServiceImpl::disconnectFromWiFi()");
    pSerial->println("wifi::disconnect");
}

/*
 * More more more more more sins...
 */
void SingleBoardServiceImpl::sendCommand(const String & s) {
    Serial.println("SbcServiceImpl::sendCommand()");
    pSerial->print("cmd::");
    pSerial->println(s);
}