#include "snek.h"
#include "driver.h"

const byte tickTime = 100; //ms
unsigned long lastTick = 0;

Snek snek;
bool sprite[8][8];
Driver driver;

void clearSprite(bool sprite[8][8]){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      sprite[i][j] = false;
    }
  }
}

byte getJoystickDirection(){
  return RIGHT;
}

void setup() {
  driver.init();
}

void loop() {
  // do logic
  if(millis() - lastTick > tickTime){
    lastTick = millis();
    snek.tick();
    clearSprite(sprite);
    snek.render(sprite);
  }
  // do graphics
  driver.draw(sprite);
}
