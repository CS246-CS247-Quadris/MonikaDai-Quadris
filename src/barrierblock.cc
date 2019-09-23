#include <iostream>
#include "barrierblock.h"
using namespace std;

    void BarrierBlock::updateBcells(Board *b) {
       bcells.clear();
       bcells.emplace_back(b->getCell(leftbot.y, leftbot.x));
       tmpPos(leftbot, pos);
    }

    BarrierBlock::BarrierBlock(Board *b, int selflevel, int x, int y): Block(selflevel, 1) {
       type = '*';
       currshape = 0;
       leftbot.x = x;
       leftbot.y = y;
       updateBcells(b);
       tgdisplay(b);
    }

  void BarrierBlock::tgdisplay(Board *b) {
    for (int i  = 0; i < 1; ++i) {
      bcells[i]->setType(type);
      bcells[i]->notifyDisplay(*b->getTextdisplay());
      bcells[i]->showGraphic();
    }
    }
   void BarrierBlock::untgdisplay(Board *b) {
    for (int i  = 0; i < 1; ++i) {
      bcells[i]->setType(' ');
      bcells[i]->notifyDisplay(*b->getTextdisplay());
      bcells[i]->unshowGraphic();
    }
  }
 
    void BarrierBlock::drop(Board *b) {
      int min = b->TopofCol(4, pos[0].x) - 3;
      if (min > 0) {
        untgdisplay(b);    
        leftbot.y = leftbot.y + min;
        updateBcells(b);
        tgdisplay(b);
      }
    }

    void BarrierBlock::tmpPos(Position &ref, std::vector<Position> &tmp) {
        tmp.clear();
        tmp.emplace_back(Position(ref.x, ref.y));
    }

    void BarrierBlock::clockwise(Board *b) {}
    void BarrierBlock::counterclockwise(Board *b) {}

