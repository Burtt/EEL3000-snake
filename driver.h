#pragma once

#include "Arduino.h"

class Driver{
  private:
    const int8_t SER = 2;
    const int8_t SRCLK = 3;
    const int8_t RCLK = 4;
    const int8_t OE = 5;
    const int8_t ROW_PINS[8] = {1,6,11,12,7,10,8,9}; 
    
    void clockPin(int8_t);
    void clock(bool);
  public:
    Driver() {}
    void init();
    void draw(bool sprite[8][8]);
};

