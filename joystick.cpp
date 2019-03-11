#include "joystick.h"
#include "direction.h"

#define DEAD_ZONE 102 // 10% of 1023

int8_t Joystick::getDirection(){
  int x = analogRead(X_PIN);
  int y = analogRead(Y_PIN);
  if(abs(x) - DEAD_ZONE < 0) x = 0;
  if(abs(y) - DEAD_ZONE < 0) y = 0;
  if(x == 0 && y == 0) return NO_DIRECTION;
  if(abs(x) > abs(y)){
    if(x < 0){
      return LEFT;
    }else{
      return RIGHT;
    }
  }else{
    if(y < 0){
      return UP;
    }else{
      return DOWN;
    }
  }
}


