#ifndef _POSITION_H_
#define _POSITION_H_

struct Position {
    int x;
    int y;
    Position(int x = 0, int y = 0): x{x}, y{y} {}
};

#endif
