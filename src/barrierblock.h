#ifndef _BARRIERBLOCK_H_
#define _BARRIERBLOCK_H_

#include <iostream>
#include "block.h"
#include "board.h"

class BarrierBlock: public Block {
    void updateBcells(Board *b);
   public:
    BarrierBlock(Board *b, int selflevel, int x, int y); 
    void untgdisplay(Board *b);
    void tgdisplay(Board *b);
    void drop(Board *b) override;
    void tmpPos(Position &ref, std::vector<Position> &tmp);
    void clockwise(Board *b);
    void counterclockwise(Board *b);

};

#endif
