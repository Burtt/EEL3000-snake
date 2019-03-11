#pragma once

#include "Arduino.h"
#include "joystick.h"

class SnekNode{
  public:
    SnekNode *previousNode;
    const int8_t x,y;
    SnekNode(int8_t x, int8_t y, SnekNode *previous = NULL): x(x), y(y), previousNode(previous) {}
    bool collidesWith(int8_t, int8_t);
};

class Snek{
  private:
    SnekNode *tailNode;
    SnekNode *headNode;
    int8_t newNodeX, newNodeY;
    void generateNewNode();
  public:
    Snek(int8_t x = 0, int8_t y = 0);
    //Snek(Snek &) { return this; }
    //Snek & operator=(Snek &) { return this; }
    ~Snek();

    void snipTail();
    void tick(int8_t);
    void render(bool[8][8]);
};

