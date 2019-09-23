#include "window.h"
#include "textdisplay.h"
#include "cell.h"

Cell::Cell(int ri, int ci, int width, int height, Xwindow *w, char type): ri{ri}, ci{ci}, width{width}, height{height}, w{w}, type{type}{}

void Cell::showGraphic() {
   if (w) {
    int gc = ri * width;
    int gr = ci * height;
    if (type == 'I') {
      w->fillRectangle(gr, gc, width, height, Xwindow::Red);
    } else if (type == 'J') {
        w->fillRectangle(gr, gc, width, height, Xwindow::Green);
    } else if (type == 'L') {
        w->fillRectangle(gr, gc, width, height, Xwindow::Blue);
    } else if (type == 'O') {
        w->fillRectangle(gr, gc, width, height, Xwindow::Cyan);
    } else if (type == 'S') {
        w->fillRectangle(gr, gc, width, height, Xwindow::Yellow);
    } else if (type == 'Z') {
        w->fillRectangle(gr, gc, width, height, Xwindow::Magenta);
    } else if (type == 'T') {
        w->fillRectangle(gr, gc, width, height, Xwindow::Orange);
    } else if (type == '*') {
        w->fillRectangle(gr, gc, width, height, Xwindow::Brown);
    } else {
        w->fillRectangle(gr, gc, width, height, Xwindow::White);
    }
   }
  }

void Cell::unshowGraphic() {
   if (w) {
    w->fillRectangle(ci * height, ri * width, width, height, Xwindow::White);
   }
  }

bool Cell::isempty() {return (type == ' '); }

void Cell::setType(char t){ type = t; }

char Cell::getType() { return type; }

int Cell::getR() { return ri; }

int Cell::getC() { return ci; }

Cell &Cell::operator=(Cell &other) {
      if (this  == &other) {
          return *this;
      } else {  
          ri = other.ri + 1;
          ci = other.ci;
          width = other.width;
          height = other.height;
          type = other.type;
          return *this;
      }
  }

void Cell::notifyDisplay(TextDisplay &td) {
    td.notify(ri, ci, type);
  }

