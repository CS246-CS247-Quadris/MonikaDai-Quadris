#include <iostream>
#include "oblock.h"

using namespace std;

void OBlock::updateBcells(Board *b) {
        bcells.clear();
        if (currshape == 0) {
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x + 1));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x + 1));
        }
        tmpPos(leftbot, pos);
    }

void OBlock::tmpPos(Position &ref, vector<Position> &tmp) {
        tmp.clear();
        if (currshape == 0) {
            tmp.emplace_back(Position(ref.x, ref.y));
            tmp.emplace_back(Position(ref.x, ref.y - 1));
            tmp.emplace_back(Position(ref.x + 1, ref.y));
            tmp.emplace_back(Position(ref.x + 1, ref.y - 1));
        }
    }

OBlock::OBlock(Board *b, int selflevel, int x, int y): Block(selflevel, 1) {
   type = 'O';
   currshape = 0;
   leftbot.x = x;
   leftbot.y = y;
   updateBcells(b);
   tgdisplay(b);
  }

void OBlock::clockwise(Board *b) {}

void OBlock::counterclockwise(Board *b) {}


