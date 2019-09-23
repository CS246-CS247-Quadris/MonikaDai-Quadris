#ifndef _GAMEPLAY_H_
#define _GAMEPLAY_H_

#include <iostream>
#include <vector>

class Block;
class Board;
class Cell;
class Score;
class Command;
class NextBlock;
class GraphicDisplay;
class TextDisplay;

class GamePlay {
    bool textonly = false;
    std::string script = "sequence.txt";
    int startlevel = 0;
    int seed = 0;
    bool over = false;

    Command *c = nullptr;
    Board *brd = nullptr;
    Board *nextbrd = nullptr;
    Score *s = nullptr;
    NextBlock *nb = nullptr;
    std::vector<Block *> blocks;
    GraphicDisplay *gd = nullptr;
    GraphicDisplay *nextgd = nullptr;

    void restart();
    void AllTextDisplay();

 public:
   GamePlay();
   ~GamePlay();
   void start();
   void endit();
   void setTextonly();
   void setSeed(int n);
   void setScriptfile(std::string fname);
   void setStartlevel(int l);


};
#endif
