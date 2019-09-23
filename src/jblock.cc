#include <iostream>
#include "jblock.h"

using namespace std;

void JBlock::updateBcells(Board *b) {
        bcells.clear();
        if (currshape == 0) {
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x + 1));
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x + 2));
        } else if (currshape == 1) {
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y - 2, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y - 2, leftbot.x + 1));
        } else if (currshape == 2) {
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x + 1));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x + 2));
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x + 2));
        } else {
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x));
            bcells.emplace_back(b->getCell(leftbot.y, leftbot.x + 1));
            bcells.emplace_back(b->getCell(leftbot.y - 1, leftbot.x + 1));
            bcells.emplace_back(b->getCell(leftbot.y - 2, leftbot.x + 1));
        }
        tmpPos(leftbot, pos);
    }

void JBlock::tmpPos(Position &ref, vector<Position> &tmp) {
        tmp.clear();
        if (currshape == 0) {
            tmp.emplace_back(Position(ref.x, ref.y));
            tmp.emplace_back(Position(ref.x, ref.y - 1));
            tmp.emplace_back(Position(ref.x + 1, ref.y));
            tmp.emplace_back(Position(ref.x + 2, ref.y));
        } else if (currshape == 1) {
            tmp.emplace_back(Position(ref.x, ref.y));
            tmp.emplace_back(Position(ref.x, ref.y - 1));
            tmp.emplace_back(Position(ref.x, ref.y - 2));
            tmp.emplace_back(Position(ref.x + 1, ref.y - 2));
        }  else if (currshape == 2) {
            tmp.emplace_back(Position(ref.x, ref.y - 1));
            tmp.emplace_back(Position(ref.x + 1, ref.y - 1));
            tmp.emplace_back(Position(ref.x + 2, ref.y - 1));
            tmp.emplace_back(Position(ref.x + 2, ref.y));
        } else {
            tmp.emplace_back(Position(ref.x, ref.y));
            tmp.emplace_back(Position(ref.x + 1, ref.y));
            tmp.emplace_back(Position(ref.x + 1, ref.y - 1));
            tmp.emplace_back(Position(ref.x + 1, ref.y - 2));
        }
    }

JBlock::JBlock(Board *b, int selflevel, int x, int y): Block(selflevel, 4) {
   type = 'J';
   currshape = 0;
   leftbot.x = x;
   leftbot.y = y;
   updateBcells(b);
   tgdisplay(b);
  }

void JBlock::clockwise(Board *b) {
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

void JBlock::counterclockwise(Board *b) {
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


