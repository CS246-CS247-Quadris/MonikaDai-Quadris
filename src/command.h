#ifndef __COMMAND_H_
#define __COMMAND_H_
#include <vector>
#include <string>
#include <iostream>
class Block;
class NextBlock;
class Board;
class GraphicDisplay;
class Score;

class Command {
    std::string LeftCom;
    std::string RightCom;
    std::string DownCom;
    std::string ClockwiseCom;
    std::string CounterClockwiseCom;
    std::string DropCom;
    std::string LevelupCom;
    std::string LeveldownCom;
    std::string NorandomCom;
    std::string RandomCom;
    std::string SequenceCom;
    //std::string Change_I;
    //std::string Change_J;
    //std::string Change_L;
    //std::string Change_O;
    //std::string Change_S;
    //std::string Change_Z;
    //std::string Change_T;
    std::string RestartCom;
    std::string HintCom;
    std::vector<std::string> ChangeshapeCom;

    bool isLeft(std::string input);

    bool isRight(std::string input);

    bool isDown(std::string input);

    bool isClockwise(std::string input);

    bool isCountercw(std::string input);

    bool isDrop(std::string input);

    bool isLevelup(std::string input);

    bool isLeveldown(std::string input);

    bool isHint(std::string input);
    
    bool isChangeShape(std::string input);

public:
    Command();

    ~Command();

    bool isNorandom(std::string input);

    bool isRandom(std::string input);

    bool isSequence(std::string input);

    bool isRestart(std::string input);

    Block *putOnboard(char t, Board *b, int level, int rownum = 4, int colnum = 0,  bool changeshape = false);

    Block *NextonBoard(char t, Board *b, int level);

    bool execute(int time, std::string comm, Block **b, Block **nextb, std::vector<Block *> &blocks, NextBlock *nb, Score *sc, Board *brd, Board *nbrd, GraphicDisplay *gd);


    bool valid(std::string s);

};
#endif
