#include <iostream>
#include "zblock.h"

using namespace std;

void ZBlock::updateBcells(Board *b) {
        bcells.clear();
        if (currshape == 0) {
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x + 1));
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x + 1));
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x + 2));

        } else {
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x + 1));
            bcells.emplace_back(b->getCell(leftbot.y - 2, leftbot.x + 1));
        }
        tmpPos(leftbot, pos);
    }

void ZBlock::tmpPos(Position &ref, vector<Position> &tmp) {
        tmp.clear();
        if (currshape == 0) {
            tmp.emplace_back(Position(ref.x, ref.y - 1));
            tmp.emplace_back(Position(ref.x + 1, ref.y - 1));
            tmp.emplace_back(Position(ref.x + 1, ref.y));
            tmp.emplace_back(Position(ref.x + 2, ref.y));
        } else {
            tmp.emplace_back(Position(ref.x, ref.y));
            tmp.emplace_back(Position(ref.x, ref.y - 1));
            tmp.emplace_back(Position(ref.x + 1, ref.y - 1));
            tmp.emplace_back(Position(ref.x + 1, ref.y - 2));
        }
    }

ZBlock::ZBlock(Board *b, int selflevel, int x, int y): Block(selflevel, 2) {
   type = 'Z';
   currshape = 0;
   leftbot.x = x;
   leftbot.y = y;
   updateBcells(b);
   tgdisplay(b);
  }

void ZBlock::clockwise(Board *b) {
        untgdisplay(b);
        if (canRotateCW(b)) {
            if (currshape == 1) {
                currshape = 0;
            } else {
                ++currshape;
            }
            updateBcells(b);
            tgdisplay(b);
        } else {
            tgdisplay(b);
        }
    }

void ZBlock::counterclockwise(Board *b) {
      clockwise(b);
    }


