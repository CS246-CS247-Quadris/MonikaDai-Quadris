#include <iostream>
#include <vector>
#include "textdisplay.h"
#include "graphicdisplay.h"
#include "score.h"
#include "board.h"
#include "window.h"
using namespace std;

bool Board::isFullrow(int rownum) {
      for (int  i = 0; i < col; ++i) {
          if (isEmpty(rownum, i)) { return false; }
      }
      return true;
      }


Board::Board(int row, int col, GraphicDisplay *gd, int h, int w) {
      startBoard(row, col, gd, h, w);
  }

Board::~Board() { delete td; }

void Board::startBoard(int row, int col, GraphicDisplay *gd,int h, int w) {
      if (gd) {
          gd->startGraphic();
      }
      this->row = row;
      this->col = col;
      this->height = h;
      this->width = w;
      this->rowsDeleted = 0;
      this->bomb = 0;
      for (int i = 0; i < row; ++i) { //initialize <cells>
          vector<Cell> v;
          for (int j = 0; j < col; ++j) {
              if (!gd) {
                  v.emplace_back(Cell{i, j, height, width, nullptr});
              } else {
                  v.emplace_back(Cell{i, j, height, width, gd->getw()});
              }
          }
          cells.emplace_back(v);
      }
      td = new TextDisplay(row, col); //create textdisplay
  }

TextDisplay *Board::getTextdisplay() { return td; }

Cell *Board::getCell(int ri, int ci) { return &cells[ri][ci]; }

int Board::getRow() { return row; }

int Board::getCol() { return col; }

int Board::getBomb() { return bomb; }

void Board::setBomb(int bombnum) { bomb = bombnum; }

bool Board::isEmpty(int r, int c) {
      return (cells[r][c].isempty());
  }

int Board::TopofCol(int r, int c) {
      for (int i = r; i < row; ++i) {
          if (!isEmpty(i, c)) {
              return i - 1; 
          }
      }
      return row - 1;
  }

bool Board::CanPlace(char type, int rownum, int colnum, bool changeshape) {
          if (!changeshape) {
              if (type == 'I') {
                rownum = 3;
              }
          } 
          if (type == 'I') {
              if ((colnum + 3) >= col) { return false; }
              for (int i = colnum; i < colnum + 4; ++i) {
                  if (!isEmpty(rownum, i)) { return false; }
              }
              return true;
          } else if (type == 'J') {
               if ((colnum + 2) >= col) { return false; }
               if (!isEmpty(rownum, colnum)) { return false; }
               if (!isEmpty(rownum, colnum + 1)) { return false; }
               if (!isEmpty(rownum, colnum + 2)) { return false; }
               if (!isEmpty(rownum - 1, colnum)) { return false; }
               return true;
          } else if (type == 'L') {
               if ((colnum + 2) >= col) { return false; }
               if (!isEmpty(rownum, colnum)) { return false; }
               if (!isEmpty(rownum, colnum + 1)) { return false; }
               if (!isEmpty(rownum, colnum + 2)) { return false; }
               if (!isEmpty(rownum - 1, colnum + 2)) { return false; }
               return true;
          } else if (type == 'Z') {
               if ((colnum + 2) >= col) { return false; }
               if (!isEmpty(rownum, colnum + 1)) { return false; }
               if (!isEmpty(rownum, colnum + 2)) { return false; }
               if (!isEmpty(rownum - 1, colnum)) { return false; }
               if (!isEmpty(rownum - 1, colnum + 1)) { return false; }
               return true;
          } else if (type == 'O') {
               if ((colnum + 1) >= col) { return false; }
               if (!isEmpty(rownum, colnum)) { return false; }
               if (!isEmpty(rownum, colnum + 1)) { return false; }
               if (!isEmpty(rownum - 1, colnum)) { return false; }
               if (!isEmpty(rownum - 1, colnum + 1)) { return false; }
               return true;
          } else if (type == 'S') {
              if ((colnum + 2) >= col) { return false; }
              if (!isEmpty(rownum, colnum)) { return false; }
              if (!isEmpty(rownum, colnum + 1)) { return false; }
              if (!isEmpty(rownum - 1, colnum + 1)) { return false; }
              if (!isEmpty(rownum - 1, colnum + 2)) { return false; }
              return true;
          } else {
              if ((colnum + 2) >= col) { return false; }
              if (!isEmpty(rownum, colnum + 1)) { return false; }
              if (!isEmpty(rownum - 1, colnum)) { return false; }
              if (!isEmpty(rownum - 1, colnum + 1)) { return false; }
              if (!isEmpty(rownum - 1, colnum + 2)) { return false; }
              return true;
          }
        
      }

 void Board::deleteRow(int rownum){
      int torow = rownum;
      for (int h = torow - 1; h > 0; --h) {
          for (int j = 0; j < col; ++j) {
               cells[torow][j] = cells[h][j];
               cells[torow][j].notifyDisplay(*td);
               cells[torow][j].showGraphic();
           }
           torow--;
       }
       for (int j = 0; j < col; ++j) {
          cells[0][j].setType(' ');
          cells[0][j].notifyDisplay(*td);
          cells[0][j].showGraphic();
       }
       ++rowsDeleted;
}
int Board::calNumdeleted(Score *s, vector<Block *> &blocks) {
       rowsDeleted = 0;
       bool anydelete = false;
       for (int i = row - 1; i >= 0; i--) {
          while (isFullrow(i)) {
             deleteRow(i);
             anydelete = true;
             s->updateBlocks(blocks, i, this);
          }
       }
       if (anydelete) {
          bomb = 0;
       } else {
          ++bomb;
       }
       return rowsDeleted;
}

void Board::clear(GraphicDisplay *gd) {
       delete td;
       td = nullptr;
       startBoard(row, col, gd);
      }

std::ostream &operator<<(std::ostream &out, Board &bd) {
   if (bd.td) {
      out << *bd.td << endl;
   }
   return out;
 }


