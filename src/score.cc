#include <iostream>
#include "graphicdisplay.h"
#include "board.h"
#include "block.h"
#include "score.h"
#include "cell.h"
using namespace std;
Score::Score() {
      curr = 0;
      highest = 0;
  }

Score::~Score() {}

void Score::updateBlocks(vector<Block *> &blocks, int rownum, Board *b) {
   for (int i = 0; i < blocks.size(); ++i) {
      for(int h = 0; h < (blocks[i]->getBcells()).size(); ++h) {
        if ((blocks[i]->getBcells()[h])->getR() == rownum) {
           blocks[i]->getBcells().erase((blocks[i]->getBcells()).begin() + h);
           --h;
        } else if ((blocks[i]->getBcells()[h])->getR() < rownum) {
            blocks[i]->getBcells()[h] = b->getCell((blocks[i]->getBcells()[h])->getR() + 1, (blocks[i]->getBcells()[h])->getC());
        }
      }
      if ((blocks[i]->getBcells()).size() == 0) {
        curr = curr + (blocks[i]->getLevel() + 1) * (blocks[i]->getLevel() + 1);
        blocks.erase(blocks.begin() + i);
        --i;
      }
   }
}

void Score::updateScore(int currlevel, int rowsDeleted, GraphicDisplay *gd) {
    curr = curr + (rowsDeleted + currlevel) * (rowsDeleted + currlevel);
    if (curr > highest) {
          highest = curr;
      }
      if (gd) {
              gd->updateScore(curr);
              gd->updateHighest(highest);
      }
}
int Score::getCurr() const { return curr; }
int Score::getHighest() const { return highest; }
void Score::clear() {
      curr = 0;
  }
