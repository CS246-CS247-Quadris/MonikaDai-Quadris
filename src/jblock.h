#ifndef _JBLOCK_H_
#define _JBLOCK_H_

#include <iostream>
#include "block.h"
#include "board.h"

class JBlock: public Block{
    void updateBcells(Board *b);

 public:
  JBlock(Board *b, int selflevel, int x, int y);
  void tmpPos(Position &ref, std::vector<Position> &tmp);
  void clockwise(Board *b);
  void counterclockwise(Board *b);

};

#endif
