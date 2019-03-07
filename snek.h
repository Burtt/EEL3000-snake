#pragma once

#include "Arduino.h"

#define NO_DIRECTION 0
#define RIGHT 1
#define UP 2
#define LEFT 3
#define DOWN 4

byte getJoystickDirection();

class SnekNode{
  public:
    SnekNode *previousNode;
    const byte x,y;
    SnekNode(byte x, byte y, SnekNode *previous = NULL): x(x), y(y), previousNode(previous) {}
};

class Snek{
  private:
    SnekNode *tailNode;
    SnekNode *headNode;
    //byte newNodeX, newNodeY;
  public:
    Snek(byte x = 0, byte y = 0);
    //Snek(Snek &) { return this; }
    //Snek & operator=(Snek &) { return this; }
    ~Snek();

    void snipTail();
    void tick();
    void render(bool[8][8]);
};

