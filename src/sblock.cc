#include <iostream>
#include "sblock.h"

using namespace std;

void SBlock::updateBcells(Board *b) {
        bcells.clear();
        if (currshape == 0) {
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x + 1));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x + 1));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x + 2));

        } else {
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x + 1));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x + 1));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y - 2, leftbot.x));
        }
        tmpPos(leftbot, pos);
    }

void SBlock::tmpPos(Position &ref, vector<Position> &tmp) {
        tmp.clear();
        if (currshape == 0) {
            tmp.emplace_back(Position(ref.x, ref.y));
            tmp.emplace_back(Position(ref.x + 1, ref.y));
            tmp.emplace_back(Position(ref.x + 1, ref.y - 1));
            tmp.emplace_back(Position(ref.x + 2, ref.y - 1));
        } else {
            tmp.emplace_back(Position(ref.x + 1, ref.y));
            tmp.emplace_back(Position(ref.x + 1, ref.y - 1));
            tmp.emplace_back(Position(ref.x, ref.y - 1));
            tmp.emplace_back(Position(ref.x, ref.y - 2));
        }
    }

SBlock::SBlock(Board *b, int selflevel, int x, int y): Block(selflevel, 2) {
   type = 'S';
   currshape = 0;
   leftbot.x = x;
   leftbot.y = y;
   updateBcells(b);
   tgdisplay(b);
  }

void SBlock::clockwise(Board *b) {
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

void SBlock::counterclockwise(Board *b) {
      clockwise(b);
    }


