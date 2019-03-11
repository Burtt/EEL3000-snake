#include "snek.h"
#include "driver.h"

const int tickTime = 300; //ms
unsigned long lastTick = 0;

Snek snek;
Joystick joystick;
bool sprite[8][8];
Driver driver;

void renderDiag(bool sprite[8][8]){
  for(int i = 0; i < 8; i++){
    sprite[i][i] = true;
  }
}

void clearSprite(bool sprite[8][8]){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      sprite[i][j] = false;
    }
  }
}

void setup() {
  driver.init();
}

void loop() {
  // do logic
  if(millis() - lastTick > tickTime){
    lastTick = millis();
    snek.tick(joystick.getDirection());
    clearSprite(sprite);
    snek.render(sprite);
  }
  // do graphics
  driver.draw(sprite);
}
