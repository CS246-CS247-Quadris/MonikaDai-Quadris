#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "nextblock.h"
using namespace std;

NextBlock::NextBlock(std::string fname, int level): fname{fname}, level{level} {
        if (level == 0) {
            random = false;
        } else {
            random = true;
        }
        seq.open(fname);
    }

NextBlock::~NextBlock() { seq.close(); }

void NextBlock::updatelevel(int level) {
        this->level = level;
        if (this->level == 0) {
          random = false;
          seq.close();
          seq.open(fname);
        } else {
          random = true;
        }
    }

void NextBlock::levelup() {
    if (level < 4) {
        ++level;
    }
    if (this->level == 0) {
          random = false;
    } else {
          random = true;
    }
}


void NextBlock::leveldown() {
    if (level > 0) {
        --level;
    }
    if (this->level == 0) {
          random = false;
          seq.close();
          seq.open(fname);
    } else {
          random = true;
    }
}

int NextBlock::getLevel() { return level; }

char NextBlock::getCurrtype() { return currtype; }

void NextBlock::nonrandom(string f) {
        if (level >= 3) {
            random = false;
            seq.close();
            seq.open(f);
        }
    }

void NextBlock::restore() {
        if ((level >= 3) & (!random)) {
            random = true;
            seq.close();
            seq.open(fname);
        }
    }

char NextBlock::generate_next() {
        if ((level == 0) || (!random)) {
            string s;
            if (seq >> s) {
                if (s == "I") {
                    currtype = 'I';
                } else if (s == "J") {
                    currtype = 'J';
                } else if (s == "L") {
                    currtype = 'L';
                } else if (s == "O") {
                    currtype = 'O';
                } else if (s == "S") {
                    currtype = 'S';
                } else if (s == "Z") {
                    currtype = 'Z';
                } else {
                    currtype = 'T';
                }
            } else {
                seq.close();
                currtype = 'd';
            }
        } else if (level == 1) {
            int ran = rand() % 12;
            if (ran == 0 || ran == 1) {
                currtype = 'I';
            } else if (ran == 2 || ran == 3) {
                currtype = 'J';
            } else if (ran == 4 || ran == 5) {
                currtype = 'L';
            } else if (ran == 6 || ran == 7) {
                currtype = 'O';
            } else if (ran == 8) {
                currtype = 'S';
            } else if (ran == 9) {
                currtype = 'Z';
            } else {
                currtype = 'T';
            }
        } else if (level == 2) {
                int ran = rand() % 7;
                if (ran == 0) {
                    currtype = 'I';
                } else if (ran == 1) {
                    currtype = 'J';
                } else if (ran == 2) {
                    currtype = 'L';
                } else if (ran == 3) {
                    currtype = 'O';
                } else if (ran == 4) {
                    currtype = 'S';
                } else if (ran == 5) {
                    currtype = 'Z';
                } else {
                    currtype = 'T';
                }
        } else if (level == 3 || level == 4) {
                int ran = rand() % 9;
                if (ran == 0) {
                    currtype = 'I';
                } else if (ran == 1) {
                    currtype = 'J';
                } else if (ran == 2) {
                    currtype = 'L';
                } else if (ran == 3) {
                    currtype = 'O';
                } else if (ran == 4 || ran == 5) {
                    currtype = 'S';
                } else if (ran == 6 || ran == 7) {
                    currtype = 'Z';
                } else {
                    currtype = 'T';
                }
            }
            return currtype;
        }

  
