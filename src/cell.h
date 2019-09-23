#ifndef _CELL_H_
#define _CELL_H_

#include <iostream>

class TextDisplay;
class Xwindow;

class Cell{
  int ri, ci, width, height;
  char type;
  Xwindow *w = nullptr;
  
 public:
  Cell(int ri, int ci, int width, int height, Xwindow *w, char type = ' ');
  void showGraphic();
  void unshowGraphic();
  bool isempty();
  void setType(char t);
  char getType();
  int getR();
  int getC();
  Cell &operator=(Cell &other);
  void notifyDisplay(TextDisplay &td);

};
#endif
