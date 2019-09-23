#ifndef _BLOCK_H_
#define _BLOCK_H_

#include <iostream>
#include <vector>
#include "position.h"

class Cell;
class Board;

class Block{
 protected:
  int selflevel; 
  std::vector<Cell *> bcells;
  std::vector<Position> pos;
  Position leftbot;
  char type;
  int currshape;
  int variants;

  virtual void updateBcells(Board *b) = 0;
  bool canRotateCW(Board *b);
  bool canRotateCCW(Board *b);
  bool canDown(Board *b);
  bool canLeft(Board *b);
  bool canRight(Board *b);
 public:
  Block(int selflevel, int variants);
  virtual ~Block();
  int getLefbotx();
  int getLefboty();
  char getType();
  int getLevel();
  std::vector<Cell *> &getBcells();
  void tgdisplay(Board *b);
  void untgdisplay(Board *b);

  void left(Board *b);
  void right(Board *b);
  void down(Board *b);
  virtual void tmpPos(Position &ref, std::vector<Position> &tmp) = 0;
  virtual void drop(Board *b);
  virtual void clockwise(Board *b) = 0;
  virtual void counterclockwise(Board *b) = 0;

};
#endif
