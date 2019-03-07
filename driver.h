#pragma once

#include "Arduino.h"

class Driver{
  private:
    const byte SER = 2;
    const byte SRCLK = 3;
    const byte RCLK = 4; 
    const byte OE = 5; 
    const byte ROW_PINS[8] = {13,6,7,12,8,9,10,11};
    
    void clockPin(byte);
    void clock(bool);
  public:
    Driver() {}
    void init();
    void draw(bool sprite[8][8]);
};

