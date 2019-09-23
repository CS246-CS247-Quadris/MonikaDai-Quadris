#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

#include "gameplay.h"
#include "board.h"
#include "block.h"
#include "command.h"
#include "score.h"
#include "nextblock.h"
#include "graphicdisplay.h"

using namespace std;

void GamePlay::restart() {
      delete brd;
      delete nextbrd;
      delete c;
      delete nb;
      if (!textonly) {
          delete gd;
          delete nextgd;
      }
      gd = nullptr;
      nextgd = nullptr;
      for (int i = 0; i < blocks.size(); ++i) {
          delete blocks[i];
      }
      blocks.clear();
      s->clear(); //set the curr to 0 while the highest remains
      start();
  }

void GamePlay::AllTextDisplay() {
      cout << "Level: " << nb->getLevel() <<  endl;
      cout << "Score: " << s->getCurr() << endl;
      cout << "Hi Score: " << s->getHighest() << endl;
      cout << *brd;
      cout << "Next: " << endl;
      cout << *nextbrd << endl;
  }

  //void putBarrierBlock();

GamePlay::GamePlay() {}

GamePlay::~GamePlay() {
       for (int i = 0; i < blocks.size(); ++i) {
          delete blocks[i];
      }
       delete brd;
       delete nextbrd;
       if (!textonly) {
           delete gd;
           delete nextgd;
       }
       delete nb;
       delete c;
       delete s;
   }

void GamePlay::start() {
       // settings
       if (!textonly) {
           gd = new GraphicDisplay(18, 11);
           nextgd = new GraphicDisplay(2, 4);
       } else {
           gd = nullptr;
           nextgd = nullptr;
       }
       brd = new Board(18, 11, gd);
       nextbrd = new Board(2, 4, nextgd); //next board is just a board to put next
       nb = new NextBlock(script, startlevel);
       c = new Command();
       if (gd) {
          gd->updateLevel(startlevel);
       }
       if (!s) {
           s = new Score();
       }
       s->clear();
       if (gd) {
          gd->updateHighest(s->getHighest());
       }

       //set blocks
       char curr =  nb->generate_next();
       Block *currb = c->putOnboard(curr, brd, startlevel);
       blocks.emplace_back(currb);
       char next =  nb->generate_next();
       Block *nextb = c->NextonBoard(next, nextbrd, startlevel);
       //blocks.emplace_back(nextb);
       AllTextDisplay();

       //commands
       string inputcom;
       string cmdfname = "";
       int split;
       int multiplier;
       string splitedcomm;
       ifstream cmdfile;
       while (true) {   //Assume: once sequence command is issued, the program terminates when command from file exhausted
           if (cmdfname != "") {
               cmdfile >> inputcom;
               if (!cmdfile) {
                   delete nextb;
                   cout << "Command from file exhausted" << endl;
                   over = true;
                   cout << "game over" << endl;
                   return;
               }
           } else {
               cin >> inputcom;
               if (!cin) {
                   delete nextb;
                   cout << "reach EOF" << endl;
                   over = true;
                   cout << "game over" << endl;
                   return;
               }
           }
           split = 0;
           multiplier = 1;
           splitedcomm = "";
           while ((inputcom[split] >= '0') & (inputcom[split] <= '9')) {
               ++split;
           }
           if (split == 0) {
               multiplier = 1;
               splitedcomm = inputcom;
           } else {
               string multi = inputcom.substr(0, split);
               splitedcomm = inputcom.substr(split, inputcom.length() - multi.length());
               istringstream ss{multi};
               ss >> multiplier;
           }
           if (!c->valid(splitedcomm)) {
               cout << splitedcomm << " Invalid command" << endl;
           }
           if (c->isRestart(splitedcomm)) {
               delete nextb;
               restart();
               return;
           } else if (c->isNorandom(splitedcomm)) {
               string file;
               if (cmdfname != "") {
                 cmdfile >> file;
               } else {
                 cin >> file; 
               }
               nb->nonrandom(file);
           } else if (c->isRandom(splitedcomm)) {
               nb->restore();
           } else if (c->isSequence(splitedcomm)) {
               cin >> cmdfname;
               cmdfile.open(cmdfname);
           } else { 
               over = c->execute(multiplier, splitedcomm, &currb, &nextb, blocks, nb, s, brd, nextbrd, gd); //if over, return true 
           }
           AllTextDisplay();
           if (over) {
               delete nextb;
               cout << "game over" << endl;
               return;
           }
       }
 }

void GamePlay::endit() {
       delete this;
   }

void GamePlay::setTextonly() {
     textonly = true;
   }

void GamePlay::setSeed(int n) {
       seed = n;
   }

void GamePlay::setScriptfile(string fname) {
        script = fname;
   }

void GamePlay::setStartlevel(int l) {
       if (l > 4) {
           startlevel = 4;
       } else if ( l < 0 ) {
           startlevel = 0;
       } else {
           startlevel = l;
       }
   }

