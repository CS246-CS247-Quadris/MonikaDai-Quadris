#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>
#include <vector>
#include "cell.h"
class GraphicDisplay;
class TextDisplay;
class Xwindow;
class Block;
class Score;

class Board {
  int row; 
  int col;
  int height;
  int width;
  int rowsDeleted = 0;
  int bomb = 0;
  std::vector<std::vector<Cell>> cells;
  TextDisplay *td = nullptr;
  
  bool isFullrow(int rownum);
  void deleteRow(int rownum);
 public:
  Board(int row, int col, GraphicDisplay *gd, int h = 30, int w = 30);
  ~Board();
  void startBoard(int row, int col, GraphicDisplay *gd,int h = 30, int w = 30);
  TextDisplay *getTextdisplay();
  Cell *getCell(int ri, int ci);
  int getRow();
  int getCol();
  int getBomb();
  void setBomb(int bombnum);
  bool isEmpty(int r, int c);
  int TopofCol(int r, int c);
  bool CanPlace(char type, int rownum = 4, int colnum = 0, bool changeshape = false);
  int calNumdeleted(Score *s, std::vector<Block *> &blocks);
  void clear(GraphicDisplay *gd);
 friend std::ostream &operator<<(std::ostream &out, Board &bd);
           
};
#endif

