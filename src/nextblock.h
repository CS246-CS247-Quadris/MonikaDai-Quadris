#ifndef _NEXTBOARD_H_
#define _NEXTBOARD_H_

#include <fstream>
#include <iostream>
#include <string>

class NextBlock {
    std::string fname;
    std::ifstream seq;
    int level;
    bool random;
    char currtype;

public:
    NextBlock(std::string fname, int level);

    ~NextBlock();

    void updatelevel(int level);

    void levelup();

    void leveldown();

    int getLevel();

    char getCurrtype();

    void nonrandom(std::string f);

    void restore();

    char generate_next();

};


#endif
