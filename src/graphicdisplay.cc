#include <iostream>
#include <sstream>
#include "graphicdisplay.h"
#include "window.h"
using namespace std;

GraphicDisplay::GraphicDisplay(int row, int col, int size): row{row}, col{col}, size{size} {} 

void GraphicDisplay::startGraphic() {
        if (row == 18) {
            w = new Xwindow((col + 5) * size, row * size);
            w->fillRectangle(0, 0, col * size, row * size, Xwindow::White);
            for (int i = 0; i < 18; ++i) {
                w->fillRectangle(11 * size, i * size, 2, size, Xwindow::Black);
            }
            w->drawString(11 * size + 3, 4 * size, "Level:", Xwindow::Black);
            w->drawString(14 * size, 4 * size, "0", Xwindow::Black);
            w->drawString(11 * size + 3, 5 * size, "Score:", Xwindow::Black);
            w->drawString(14 * size, 5 * size, "0", Xwindow::Black);
            w->drawString(11 * size + 3, 6 * size, "Hi Score:", Xwindow::Black);
            w->drawString(14 * size, 6 * size, "0", Xwindow::Black);
        }
        else if (row == 2) {
            w = new Xwindow(col * size, row * size);
            w->fillRectangle(0, 0, col * size, row * size, Xwindow::White);
            w->drawString(1, size, "Next:", Xwindow::Black);
        }
}

GraphicDisplay::~GraphicDisplay() { delete w; }

Xwindow *GraphicDisplay::getw(){ return w;}

void GraphicDisplay::updateLevel(int level) { 
        ostringstream ss;
        ss << level;
        string l = ss.str();
        w->fillRectangle(14 * size - row, 3 * size, size, size,  Xwindow::White);
        
        w->drawString(14 * size, 4 * size, l, Xwindow::Black);
    }

void GraphicDisplay::updateHighest(int highscore) {
        ostringstream ss;
        ss << highscore;
        string hs = ss.str();
        w->fillRectangle(14 * size - row, 5 * size + 15, size + 20, size,  Xwindow::White);
        w->drawString(14 * size, 6 * size, hs, Xwindow::Black);
    }

void GraphicDisplay::updateScore(int score) {
        ostringstream ss;
        ss << score;
        string s = ss.str();
        w->fillRectangle(14 * size - row, 4 * size + 10, size + 20, size,  Xwindow::White);
        w->drawString(14 * size, 5 * size, s, Xwindow::Black);
    }

