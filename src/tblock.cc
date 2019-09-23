#include <iostream>
#include "tblock.h"

using namespace std;

void TBlock::updateBcells(Board *b) {
        bcells.clear();
        if (currshape == 0) {
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x + 1));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x + 2));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x + 1));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x));
        } else if (currshape == 1) {
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x + 1));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x + 1));
            bcells.emplace_back(b->getCell(leftbot.y - 2, leftbot.x + 1));
        } else if (currshape == 2) {
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x + 1));
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x + 2));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x + 1));
        } else {
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y - 2, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x + 1));
        }
        tmpPos(leftbot, pos);
    }

void TBlock::tmpPos(Position &ref, vector<Position> &tmp) {
        tmp.clear();
        if (currshape == 0) {
            tmp.emplace_back(Position(ref.x + 1, ref.y));
            tmp.emplace_back(Position(ref.x + 2, ref.y - 1));
            tmp.emplace_back(Position(ref.x + 1, ref.y - 1));
            tmp.emplace_back(Position(ref.x, ref.y - 1));
        } else if (currshape == 1) {
            tmp.emplace_back(Position(ref.x + 1, ref.y));
            tmp.emplace_back(Position(ref.x, ref.y - 1));
            tmp.emplace_back(Position(ref.x + 1, ref.y - 1));
            tmp.emplace_back(Position(ref.x + 1, ref.y - 2));
        }  else if (currshape == 2) {
            tmp.emplace_back(Position(ref.x, ref.y));
            tmp.emplace_back(Position(ref.x + 1, ref.y));
            tmp.emplace_back(Position(ref.x + 2, ref.y));
            tmp.emplace_back(Position(ref.x + 2, ref.y - 1));
        } else {
            tmp.emplace_back(Position(ref.x, ref.y));
            tmp.emplace_back(Position(ref.x, ref.y - 1));
            tmp.emplace_back(Position(ref.x, ref.y - 2));
            tmp.emplace_back(Position(ref.x + 1, ref.y - 1));
        }
    }


TBlock::TBlock(Board *b, int selflevel, int x, int y): Block(selflevel, 4) {
   type = 'T';
   currshape = 0;
   leftbot.x = x;
   leftbot.y = y;
   updateBcells(b);
   tgdisplay(b);
  }

void TBlock::clockwise(Board *b) {
        untgdisplay(b);
        if (canRotateCW(b)) {
            if (currshape == 3) {
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

void TBlock::counterclockwise(Board *b) {
      untgdisplay(b);
      if (canRotateCCW(b)) {
          if (currshape == 0) {
              currshape = 3;
          } else {
              --currshape;
          }
          updateBcells(b);
          tgdisplay(b);
      } else {
          tgdisplay(b);
      }
    }


