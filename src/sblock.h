#ifndef _SBLOCK_H_
#define _SBLOCK_H_

#include <iostream>
#include "block.h"
#include "board.h"

class SBlock: public Block{
    void updateBcells(Board *b);

 public:
  SBlock(Board *b, int selflevel, int x, int y);
  void tmpPos(Position &ref, std::vector<Position> &tmp);
  void clockwise(Board *b);
  void counterclockwise(Board *b);

};

#endif
