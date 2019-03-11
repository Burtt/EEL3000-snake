#include "driver.h"

void Driver::init(){
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(OE, OUTPUT);
  for(int i = 0; i < 8; i++){
    pinMode(ROW_PINS[i], OUTPUT);
  }
  digitalWrite(SER, LOW);
  digitalWrite(SRCLK, LOW);
  digitalWrite(RCLK, LOW);
  digitalWrite(OE, HIGH);
  for(int i = 0; i < 8; i++){
    digitalWrite(ROW_PINS[i], HIGH);
  }
}

void Driver::clockPin(int8_t pinNum){
  digitalWrite(pinNum, HIGH);
  digitalWrite(pinNum, LOW);
}

void Driver::clock(bool serHigh){
  if(serHigh){
    digitalWrite(SER, HIGH);
    clockPin(SRCLK);
    digitalWrite(SER, LOW);
  }else{
    clockPin(SRCLK);
  }
  clockPin(RCLK);
}

void Driver::draw(bool sprite[8][8]){
  for(int8_t i = 0; i < 8; i++){
    digitalWrite(OE, HIGH);
    for(int j = 0; j < 8; j++){
      digitalWrite(ROW_PINS[j], sprite[i][j] ? LOW : HIGH);
    }
    clock(i == 0);
    digitalWrite(OE, LOW);
    delayMicroseconds(500);
  }
}

