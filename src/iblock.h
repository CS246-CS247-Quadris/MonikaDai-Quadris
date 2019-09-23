#ifndef _IBLOCK_H_
#define _IBLOCK_H_

#include <iostream>
#include "block.h"
#include "board.h"

class IBlock: public Block{
    void updateBcells(Board *b);

public:
    IBlock(Board *b, int selflevel, int x, int y);
    void tmpPos(Position &ref, std::vector<Position> &tmp);
    void clockwise(Board *b);
    void counterclockwise(Board *b);

};

#endif

