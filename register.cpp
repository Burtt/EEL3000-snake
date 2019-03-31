#include "register.h"

void Register::clockPin(uint8_t pin) const{
  digitalWrite(pin, HIGH);
  digitalWrite(pin, LOW);
}

void Register::setPin(uint8_t pin, bool active) const{
  digitalWrite(pin, active? HIGH : LOW);
}

void Register::init() const{
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(OE, OUTPUT);
  digitalWrite(SER, LOW);
  digitalWrite(SRCLK, LOW);
  digitalWrite(RCLK, LOW);
  digitalWrite(OE, HIGH);
}

void Register::serialClock() const{
  clockPin(SRCLK);
}

void Register::registerClock() const{
  clockPin(RCLK);
}

void Register::setSerial(bool active) const{
  setPin(SER, active);
}

void Register::enableOutput(bool enabled) const{
  setPin(OE, !enabled);
}
