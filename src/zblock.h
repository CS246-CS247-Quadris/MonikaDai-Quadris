#ifndef _ZBLOCK_H_
#define _ZBLOCK_H_

#include <iostream>
#include "block.h"
#include "board.h"

class ZBlock: public Block{
    void updateBcells(Board *b);

 public:
  ZBlock(Board *b, int selflevel, int x, int y);
  void tmpPos(Position &ref, std::vector<Position> &tmp);
  void clockwise(Board *b);
  void counterclockwise(Board *b);

};

#endif
