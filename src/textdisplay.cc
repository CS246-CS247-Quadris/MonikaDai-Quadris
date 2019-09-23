#include <iostream>
#include "textdisplay.h"
using namespace std;

TextDisplay::TextDisplay(int row = 18, int col = 11): row{row}, col{col} {
  for (int i = 0; i < row; ++i) {
    vector<char> r; 
    for (int j = 0; j < col; ++j) {
      r.emplace_back(' ');
    }
    c.emplace_back(r);
  }
}

TextDisplay::~TextDisplay() {}

void TextDisplay::notify(int row, int col, char type) {
  c[row][col] = type;
}

std::ostream &operator<<(std::ostream &out, TextDisplay &td) {
 for (int s = 0; s < td.col; ++s) {
   out << '-';
 } 
 out << endl;
 for (int i = 0; i < td.row; ++i) {  
    for (int h = 0; h < td.col; ++h) {
      out << td.c[i][h];
    }
    out << endl;
 }
 for (int s = 0; s < td.col; ++s) {
    out << '-';
 }
 out << endl;
 return out;
}

    
