#include "snek.h"
#include "direction.h"

bool SnekNode::collidesWith(int8_t testX, int8_t testY){
  if(testX == x && testY == y) return true;
  if(previousNode != NULL) return previousNode->collidesWith(testX, testY);
  return false;
}

Snek::Snek(int8_t x, int8_t y){
  //if(x >=5) throw "snek starting too far right!";
  tailNode = new SnekNode(x,y);
  headNode = tailNode;
  for(int i = 1; i < 3; i++){
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

void Snek::generateNewNode(){
  do{
    newNodeX = random(0,7);
    newNodeY = random(0,7);
  }while(headNode->collidesWith(newNodeX, newNodeY));
}

void Snek::tick(int8_t joystickDirection){
  // calculate next position based on joystick direction (wrap around if necessary)
  int8_t nextX, nextY;
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
  // check if there was a wrap-around to the previous node (if so, go other way)
  if(nextX == headNode->previousNode->x && nextY == headNode->previousNode->y){
    if(nextY == headNode->y){
      if(nextX == 7) nextX = 1;
      else if(nextX == 0) nextX = 6;
    }else if(nextX == headNode->x){
      if(nextY == 7) nextY = 1;
      else if(nextY == 0) nextY = 6;
    }else{
      //throw "this should never occur";
    }
  }
  // check if next position is a Snek node (die if so)
  if(headNode->collidesWith(nextX, nextY)){
    // TODO die
  }
  headNode = new SnekNode(nextX,nextY,headNode);
  // check if next position is a new node (snip tail otherwise)
  if(newNodeX == nextX && newNodeY == nextY){
    generateNewNode();
  }else{
    snipTail();
  }
}

void Snek::render(bool leds[8][8]){
  SnekNode *node = headNode;
  while(node != NULL){
    leds[node->x][node->y] = true;
    node = node->previousNode;
  }
  leds[newNodeX][newNodeY] = true;
}

