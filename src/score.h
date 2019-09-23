#ifndef _SCORE_H_
#define _SCORE_H_

#include <iostream>
#include <vector>

class Block;
class Cell;
class GraphicDisplay;
class Board;

class Score {
  int curr;
  int highest;
 public:
  Score();
  ~Score();
  void updateBlocks(std::vector<Block *> &blocks, int rownum, Board *b);
  void updateScore(int currlevel, int rowsDeleted, GraphicDisplay *gd);
  int getCurr() const;
  int getHighest() const;
  void clear();

};


#endif
