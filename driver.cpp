#include "driver.h"

void Driver::init(){
  colRegister.init();
  for(int i = 0; i < 8; i++){
    pinMode(ROW_PINS[i], OUTPUT);
  }
  for(int i = 0; i < 8; i++){
    digitalWrite(ROW_PINS[i], HIGH);
  }
}

void Driver::clock(bool serHigh){
  if(serHigh){
    colRegister.setSerial(true);
    colRegister.serialClock();
    colRegister.setSerial(false);
  }else{
    colRegister.serialClock();
  }
  colRegister.registerClock();
}

void Driver::draw(bool sprite[8][8]){
  for(int8_t i = 0; i < 8; i++){
    colRegister.enableOutput(false);
    for(int j = 0; j < 8; j++){
      digitalWrite(ROW_PINS[j], sprite[i][j] ? LOW : HIGH);
    }
    clock(i == 0);
    colRegister.enableOutput(true);
    delayMicroseconds(500);
  }
}

