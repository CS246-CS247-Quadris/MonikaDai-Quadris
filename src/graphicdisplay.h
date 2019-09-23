#ifndef _GRAPHICDISPLAY_H_
#define _GRAPHICDISPLAY_H_
#include <iostream>

class Xwindow;
class GraphicDisplay {
  Xwindow *w;
  int row;
  int col;
  int size;
 public: 
  GraphicDisplay(int row = 18, int col = 11, int size = 30); //three reserve rows
  void startGraphic();
  ~GraphicDisplay();
  Xwindow *getw();
  void updateLevel(int level);
  void updateHighest(int highscore);
  void updateScore(int score);
};




#endif
