#pragma once

#include "Arduino.h"

class Register{
  private:
    const uint8_t SER;
    const uint8_t SRCLK;
    const uint8_t RCLK;
    const uint8_t OE;
    void clockPin(uint8_t) const;
    void setPin(uint8_t, bool) const;
  public:
    Register(int8_t A, int8_t B, int8_t C, int8_t D): SER(A), SRCLK(B), RCLK(C), OE(D) {}
    void init() const;
    void serialClock() const;
    void registerClock() const;
    void setSerial(bool) const;
    void enableOutput(bool) const;
};

