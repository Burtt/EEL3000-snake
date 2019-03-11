#pragma once

#include "Arduino.h"

class Joystick{
  private:
    const int8_t X_PIN = A0;
    const int8_t Y_PIN = A1;
  public:
    Joystick() {}
    int8_t getDirection();
};

