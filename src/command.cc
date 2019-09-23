#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "command.h"
#include "graphicdisplay.h"
#include "board.h"
#include "block.h"
#include "score.h"
#include "nextblock.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "barrierblock.h"
using namespace std;

Command::Command() {
     LeftCom = "left";
     RightCom = "right";
     DownCom = "down";
     ClockwiseCom =  "clockwise";
     CounterClockwiseCom = "counterclockwise";
     DropCom = "drop";
     LevelupCom = "levelup";
     LeveldownCom = "leveldown";
     NorandomCom = "norandom";
     RandomCom = "random";
     SequenceCom = "sequence";
     RestartCom = "restart";
     HintCom = "hint";
     ChangeshapeCom = {"I", "J", "L", "O", "S", "Z", "T"};
 }

Command::~Command() {}

 Block *Command::putOnboard(char t, Board *b, int level, int rownum, int colnum, bool changeshape) {
    Block *bl = nullptr;
    if (!changeshape) {
     if (t == 'I') {
         bl = new IBlock(b, level, 0, 3);
     } else if (t == 'J') {
         bl = new JBlock(b, level, 0, 4);
     } else if (t == 'L') {
         bl = new LBlock(b, level, 0, 4);
     } else if (t == 'O') {
         bl = new OBlock(b, level, 0, 4);
     } else if (t == 'S') {
         bl = new SBlock(b, level, 0, 4);
     } else if (t == 'Z') {
         bl = new ZBlock(b, level, 0, 4);
     } else if (t == 'T') {
         bl = new TBlock(b, level, 0, 4);
     } else {
     }
     return bl;
    }
    else {
     if (t == 'I') {
         bl = new IBlock(b, level, colnum, rownum);
     } else if (t == 'J') {
         bl = new JBlock(b, level, colnum, rownum);
     } else if (t == 'L') {
         bl = new LBlock(b, level, colnum, rownum);
     } else if (t == 'O') {
         bl = new OBlock(b, level, colnum, rownum);
     } else if (t == 'S') {
         bl = new SBlock(b, level, colnum, rownum);
     } else if (t == 'Z') {
         bl = new ZBlock(b, level, colnum, rownum);
     } else if (t == 'T') {
         bl = new TBlock(b, level, colnum, rownum);
     } else {
     }
     return bl;
    } 
 }

 Block *Command::NextonBoard(char t, Board *b, int level) {
    Block *bl = nullptr;
    if (t == 'I') {
         bl = new IBlock(b, level, 0, 0);
     } else if (t == 'J') {
         bl = new JBlock(b, level, 0, 1);
     } else if (t == 'L') {
         bl = new LBlock(b, level, 0, 1);
     } else if (t == 'O') {
         bl = new OBlock(b, level, 0, 1);
     } else if (t == 'S') {
         bl = new SBlock(b, level, 0, 1);
     } else if (t == 'Z') {
         bl = new ZBlock(b, level, 0, 1);
     } else if (t == 'T') {
         bl = new TBlock(b, level, 0, 1);
     } else { //if t is exhaust symbol bl will be a nullptr avoid memory leak
     }
     return bl;
    }
    

 bool Command::isChangeShape(string input) {
     for (int i = 0; i < 7; ++i) {
        if (input == ChangeshapeCom[i]) {
           return true;
        }
     }
     return false;
 }

 bool Command::isLeft(string input) {
     int len = input.length();
     if ((len == 3) || (len == 4)) {
         for (int i = 0; i < len; ++i) {
             if (input[i] != LeftCom[i]) {
                 return false;
             }
         }
         return true;
     }
     return false;
 }

 bool Command::isRight(string input) {
        int len = input.length();
        if ((len >=2) & (len <= 5)) {
            for (int i = 0; i < len; ++i) {
                if (input[i] != RightCom[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool Command::isDown(string input) {
        int len = input.length();
        if ((len >=2) & (len <= 4)) {
            for (int i = 0; i < len; ++i) {
                if (input[i] != DownCom[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool Command::isClockwise(string input) {
        int len = input.length();
        if ((len >=2) & (len <= 9)) {
            for (int i = 0; i < len; ++i) {
                if (input[i] != ClockwiseCom[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool Command::isCountercw(string input) {
        int len = input.length();
        if ((len >=2) & (len <= 16)) {
            for (int i = 0; i < len; ++i) {
                if (input[i] != CounterClockwiseCom[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool Command::isDrop(string input) {
        int len = input.length();
        if ((len >=2) & (len <= 4)) {
            for (int i = 0; i < len; ++i) {
                if (input[i] != DropCom[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool Command::isLevelup(string input) {
        int len = input.length();
        if ((len >=6) & (len <= 7)) {
            for (int i = 0; i < len; ++i) {
                if (input[i] != LevelupCom[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool Command::isLeveldown(string input) {
        int len = input.length();
        if ((len >=6) & (len <= 9)) {
            for (int i = 0; i < len; ++i) {
                if (input[i] != LeveldownCom[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool Command::isNorandom(string input) {
        int len = input.length();
        if ((len >=1) & (len <= 8)) {
            for (int i = 0; i < len; ++i) {
                if (input[i] != NorandomCom[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool Command::isRandom(string input) {
        int len = input.length();
        if ((len >=2) & (len <= 6)) {
            for (int i = 0; i < len; ++i) {
                if (input[i] != RandomCom[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool Command::isSequence(string input) {
        int len = input.length();
        if ((len >=1) & (len <= 8)) {
            for (int i = 0; i < len; ++i) {
                if (input[i] != SequenceCom[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool Command::isRestart(string input) {
        int len = input.length();
        if ((len >=2) & (len <= 7)) {
            for (int i = 0; i < len; ++i) {
                if (input[i] != RestartCom[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool Command::isHint(string input) {
        int len = input.length();
        if ((len >=1) & (len <= 4)) {
            for (int i = 0; i < len; ++i) {
                if (input[i] != HintCom[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }


    bool Command::execute(int time, string comm, Block **b, Block **nextb, vector<Block *> &blocks, NextBlock *nb, Score *sc, Board *brd, Board *nbrd, GraphicDisplay *gd) {
     if (valid(comm)) {  //hint/changeshape(ignore time)
         for (int i = 0; i < time; ++i) {
             if (isLeft(comm)) {
                 (*b)->left(brd);
                 if (((nb->getLevel() == 3) || (nb->getLevel() == 4)) & (i == (time - 1))) {
                    (*b)->down(brd);
                 } 
             } else if (isRight(comm)) {
                 (*b)->right(brd);
                  if (((nb->getLevel() == 3) || (nb->getLevel() == 4)) & (i == (time - 1))) {
                    (*b)->down(brd);
                 }
             } else if (isDown(comm)) {
                 (*b)->down(brd);
                  if (((nb->getLevel() == 3) || (nb->getLevel() == 4)) & (i == (time - 1))) {
                    (*b)->down(brd);
                 }
             } else if (isClockwise(comm)) {
                 (*b)->clockwise(brd);
                  if (((nb->getLevel() == 3) || (nb->getLevel() == 4)) & (i == (time - 1))) {
                    (*b)->down(brd);
                 }
             } else if (isCountercw(comm)) {
                 (*b)->counterclockwise(brd);
                  if (((nb->getLevel() == 3) || (nb->getLevel() == 4)) & (i == (time - 1)))  {
                    (*b)->down(brd);
                 }
             } else if (isChangeShape(comm)) {
                 char towhichtype = comm[0]; 
                 (*b)->untgdisplay(brd);
                 if(brd->CanPlace(towhichtype, (*b)->getLefboty(), (*b)->getLefbotx(), true)) {
                    delete (*b);
                    (*b) = putOnboard(towhichtype, brd, (*b)->getLevel(),(*b)->getLefboty(), (*b)->getLefbotx(), true);
                    (*b)->tgdisplay(brd);
                 } else {
                    (*b)->tgdisplay(brd);
                 }   
             } else if (isLevelup(comm)) {
                 if (nb->getLevel() < 4) { brd->setBomb(0); } 
                 nb->levelup();
                 if (gd) {
                     gd->updateLevel(nb->getLevel());
                 }
             } else if (isLeveldown(comm)) { 
                 brd->setBomb(0);
                 nb->leveldown();
                 if (gd) {
                     gd->updateLevel(nb->getLevel());
                 }
             } else if (isDrop(comm)) {
                 (*b)->drop(brd);
                 int deletedrows = brd->calNumdeleted(sc, blocks);
                 if ((nb->getLevel() == 4) & (brd->getBomb() == 5)) {
                   if (brd->isEmpty(3, brd->getCol()/2)) {
                     Block *barrier = new BarrierBlock(brd, nb->getLevel(), brd->getCol()/2, 3);
                     barrier->drop(brd);   
                     brd->setBomb(0);
                     delete barrier;
                   }
                 }  
                 if (deletedrows > 0) {
                     sc->updateScore(nb->getLevel(), deletedrows, gd);
                 }
                 if (nb->getCurrtype() == 'd') {
                     return true;
                 }
                 if (!brd->CanPlace(nb->getCurrtype())) {
                     return true;
                 }
                 *b = putOnboard(nb->getCurrtype(), brd, nb->getLevel());
                 blocks.emplace_back(*b);
                 (*nextb)->untgdisplay(nbrd);
                 delete (*nextb);
                 nb->generate_next();
                 *nextb = NextonBoard(nb->getCurrtype(), nbrd, nb->getLevel());
                 }
             }
         }
        return false;
     }

     bool Command::valid(string s) {
         return (isLeft(s) || isRight(s) || isDown(s) || isClockwise(s) || isCountercw(s) ||
                 isDrop(s) || isLevelup(s) || isLeveldown(s) || isNorandom(s) || isRandom(s) ||
                 isSequence(s) || isRestart(s) || isHint(s) || isChangeShape(s));
     }


