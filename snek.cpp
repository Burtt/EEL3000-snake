#include "snek.h"

Snek::Snek(byte x, byte y){
  //if(x >=5) throw "snek starting too far right!";
  tailNode = new SnekNode(x,y);
  headNode = tailNode;
  for(int i = 1; i < 4; i++){
    headNode = new SnekNode(x+i,y, headNode);
  }
}

Snek::~Snek(){
  while(tailNode != NULL){
    snipTail();
  }
}

void Snek::snipTail(){
  SnekNode *nextTail = headNode;
  while(nextTail->previousNode != tailNode){
    nextTail = nextTail->previousNode;
  }
  delete tailNode;
  tailNode = nextTail;
}

void Snek::tick(){
  // calculate next position based on joystick direction (wrap around if necessary)
  byte nextX, nextY;
  byte joystickDirection = getJoystickDirection();
  switch(joystickDirection){
    case RIGHT:
      nextX = headNode->x + 1;
      nextY = headNode->y;
      break;
    case UP:
      nextX = headNode->x;
      nextY = headNode->y - 1;
      break;
    case LEFT:
      nextX = headNode->x - 1;
      nextY = headNode->y;
      break;
    case DOWN:
      nextX = headNode->x;
      nextY = headNode->y + 1;
      break;
  }
  // check if next direction is the previous position (if so, go forward)
    // TODO verify that this catches wrap-arounds
  if(joystickDirection == NO_DIRECTION || 
    (nextX == headNode->previousNode->x && nextY == headNode->previousNode->y)){
      nextX = (2 * headNode->x) - headNode->previousNode->x;
      nextY = (2 * headNode->y) - headNode->previousNode->y;
  }
  // check if wrap around is needed
  if(nextX > 7) nextX = 0;
  if(nextX < 0) nextX = 7;
  if(nextY > 7) nextY = 0;
  if(nextY < 0) nextY = 7;
  // check if next position is a Snek node (die if so)
  bool collision = false;
  SnekNode *previous = headNode->previousNode;
  while(previous != NULL){
    if(nextX == previous->x && nextY == previous->y){
      collision = true;
      break;
    }
    previous = previous->previousNode;
  }
  if(collision){
    // TODO die
  }
  // check if next position is a new node (new head without snipping tail if so)
    // TODO add this once new nodes exist
  // otherwise, add new head and snip tail
  headNode = new SnekNode(nextX,nextY,headNode);
  snipTail();
}

void Snek::render(bool leds[8][8]){
  SnekNode *node = headNode;
  while(node != NULL){
    leds[node->x][node->y] = true;
    node = node->previousNode;
  }
  // TODO render newNode here
}

