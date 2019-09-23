#include <iostream>
#include "iblock.h"

using namespace std;

void IBlock::updateBcells(Board *b) {
    bcells.clear(); //here!
    if (currshape == 0) {
        bcells.emplace_back(b->getCell(leftbot.y, leftbot.x + 0));
        bcells.emplace_back(b->getCell(leftbot.y, leftbot.x + 1));
        bcells.emplace_back(b->getCell(leftbot.y, leftbot.x + 2));
        bcells.emplace_back(b->getCell(leftbot.y, leftbot.x + 3));

    } else {
        bcells.emplace_back(b->getCell(leftbot.y, leftbot.x));
        bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x));
        bcells.emplace_back(b->getCell(leftbot.y - 2, leftbot.x));
        bcells.emplace_back(b->getCell(leftbot.y - 3, leftbot.x));
    }
    tmpPos(leftbot, pos);
}

void IBlock::tmpPos(Position &ref, vector<Position> &tmp) {
    tmp.clear();
    if (currshape == 0) {
        tmp.emplace_back(Position(ref.x + 0, ref.y));
        tmp.emplace_back(Position(ref.x + 1, ref.y));
        tmp.emplace_back(Position(ref.x + 2, ref.y));
        tmp.emplace_back(Position(ref.x + 3, ref.y));
    } else {
        tmp.emplace_back(Position(ref.x, ref.y));
        tmp.emplace_back(Position(ref.x, ref.y - 1));
        tmp.emplace_back(Position(ref.x, ref.y - 2));
        tmp.emplace_back(Position(ref.x, ref.y - 3));
    }
}

IBlock::IBlock(Board *b, int selflevel, int x, int y): Block(selflevel, 2) { //x, y are ref cor
    type = 'I';
    currshape = 0;
    leftbot.x = x;
    leftbot.y = y;
    updateBcells(b);
    tgdisplay(b);
}

void IBlock::clockwise(Board *b) {
    untgdisplay(b);  //have this before can; or in block canRotate do un before can
    if (canRotateCW(b)) {
        currshape == 0 ? currshape = 1 : currshape = 0;
        updateBcells(b);
        tgdisplay(b);
    } else {    //here!
        tgdisplay(b);  //here!
    }
}

void IBlock::counterclockwise(Board *b) {
    clockwise(b);
}
