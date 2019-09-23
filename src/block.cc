#include <vector>
#include <iostream>
#include "board.h"
#include "cell.h"
#include "block.h"

using namespace std;

bool Block::canRotateCW(Board *b) { //why undraw at the beginning
      int tmpshape = currshape; //to restore if can't
      if (variants == 1) {
          return true;
      } else if (variants == 2) {
          if (currshape == 1) { currshape = 0; }
          else {currshape = 1;}
      } else {
          if (currshape == 3) { currshape = 0; }
          else {++currshape;}
      }
      vector<Position> v;
      tmpPos(leftbot, v);
      for (int i = 0; i < 4; ++i) {
          if (v[i].x >= b->getCol()) {
              currshape = tmpshape;
              return false;
          }
          if (!((b->getCell(v[i].y, v[i].x))->isempty())) {
              currshape = tmpshape;
              return false; }
      }
      currshape = tmpshape;
      return true;
  }

bool Block::canRotateCCW(Board *b) {
      int tmpshape = currshape; //to restore if can't
      if (variants == 1) {
          return true;
      } else if (variants == 2) {
          if (currshape == 0) { currshape = 1; }
          else { currshape = 0; }
      } else {
          if (currshape == 0) { currshape = 3; }
          else { --currshape; }
      }
      vector<Position> v;
      tmpPos(leftbot, v);
      for (int i = 0; i < 4; ++i) {
          if (v[i].x >= b->getCol()) {
              currshape = tmpshape;
              return false;
          }
          if (!((b->getCell(v[i].y, v[i].x))->isempty())) {
              currshape = tmpshape;
              return false; }
      }
      currshape = tmpshape;
      return true;
  }

bool Block::canDown(Board *b) {
      Position newref{leftbot.x,leftbot.y + 1};
      vector<Position> v;
      tmpPos(newref, v);
      for (int i = 0; i < 4; ++i) {
          if (v[i].y >= b->getRow()) { return false; }
          if (!((b->getCell(v[i].y, v[i].x))->isempty())) { return false; }
      }
      return true;
   }

bool Block::canLeft(Board *b) {
       Position newref{leftbot.x - 1,leftbot.y};
       vector<Position> v;
       tmpPos(newref, v);
       for (int i = 0; i < 4; ++i) {
           if (v[i].x < 0) { return false; }
           if (!((b->getCell(v[i].y, v[i].x))->isempty())) { return false; }
       }
       return true;
  }

bool Block::canRight(Board *b) {
      Position newref{leftbot.x + 1,leftbot.y};
      vector<Position> v;
      tmpPos(newref, v);
      for (int i = 0; i < 4; ++i) {
          if (v[i].x >= b->getCol()) { 
             return false; }
          if (!((b->getCell(v[i].y, v[i].x))->isempty())) { 
             return false; }
      }
      return true;
  }
 

Block::Block(int selflevel, int variants): selflevel{selflevel}, variants{variants} {}

Block::~Block(){}

char Block::getType() { return type; }

int Block::getLevel() { return selflevel; }

int Block::getLefbotx() { return leftbot.x; }

int Block::getLefboty() { return leftbot.y; }

vector<Cell *> &Block::getBcells() {
      return bcells;
  }

void Block::tgdisplay(Board *b) {
    for (int i  = 0; i < 4; ++i) {
      bcells[i]->setType(type);
      bcells[i]->notifyDisplay(*b->getTextdisplay()); 
      bcells[i]->showGraphic();
    }
  }

void Block::untgdisplay(Board *b) {
    for (int i  = 0; i < 4; ++i) {
      bcells[i]->setType(' ');
      bcells[i]->notifyDisplay(*b->getTextdisplay());
      bcells[i]->unshowGraphic();
    }
  }

void Block::left(Board *b) {
    untgdisplay(b);
    if (canLeft(b)) {
        --leftbot.x;
        updateBcells(b);
        tgdisplay(b);
    } else {
        tgdisplay(b);
    }
    }

void Block::right(Board *b) {
    untgdisplay(b);
    if (canRight(b)) {
        ++leftbot.x;
        updateBcells(b);
        tgdisplay(b);
    } else {
        tgdisplay(b);
    }
}

void Block::down(Board *b) {
    untgdisplay(b);
    if (canDown(b)) {
        ++leftbot.y;
        updateBcells(b);
        tgdisplay(b);
    } else {
        tgdisplay(b); 
    }
}

void Block::drop(Board *b) {
    int min = b->getRow();
    int distance = b->getRow();
    bool bottom = true;
    for (int d = 0; d < 4; ++d) {
        bottom = true;
        int potentialx = pos[d].x;
        int potentialy = pos[d].y + 1;
        for (int n = 0; n < 4; ++n) {
           if ((pos[n].y == potentialy) & (pos[n].x == potentialx)) {
              bottom = false;
              
           }
        }
        if (bottom) {
          distance = b->TopofCol(pos[d].y + 1, pos[d].x) - pos[d].y;
          if (distance < min) {
            min = distance;
          }
        }
     }
     if (min > 0) {
        untgdisplay(b);
        leftbot.y = leftbot.y + min;
        updateBcells(b);
        tgdisplay(b);
     }
}   
     
        

