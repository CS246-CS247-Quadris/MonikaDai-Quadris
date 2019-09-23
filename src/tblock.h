#ifndef _TBLOCK_H_
#define _TBLOCK_H_

#include <iostream>
#include "block.h"
#include "board.h"


class TBlock: public Block{
    void updateBcells(Board *b);

 public:
  TBlock(Board *b, int selflevel, int x, int y);
  void tmpPos(Position &ref, std::vector<Position> &tmp);
  void clockwise(Board *b);
  void counterclockwise(Board *b);

};

#endif
