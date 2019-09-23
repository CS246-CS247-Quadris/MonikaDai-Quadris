#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
#include <iostream>
#include <vector>
class TextDisplay {
  std::vector<std::vector <char>> c;
  const int row;
  const int col;
 public:
  TextDisplay(int row, int col);
  ~TextDisplay();
  void notify(int row, int col, char type);
  friend std::ostream &operator<<(std::ostream &out, TextDisplay &td);
};

#endif
