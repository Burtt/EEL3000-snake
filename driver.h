#pragma once

#include "Arduino.h"
#include "register.h"

class Driver{
  private:
    const Register colRegister; 
    const int8_t ROW_PINS[8] = {1,6,11,12,7,10,8,9}; 
    void clock(bool);
  public:
    Driver(): colRegister(2,3,4,5) {}
    void init();
    void draw(bool sprite[8][8]);
};

