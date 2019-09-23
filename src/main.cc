#include <cstdlib>
#include <sstream>
#include "gameplay.h"
using namespace std;
int main(int argc, char *argv[]) {
   GamePlay *g = new GamePlay{};
   for (int i = 0; i < argc; ++i) {
     string arg = argv[i];
     if (arg == "-text") {
       g->setTextonly();
     } 
     if (arg == "-seed") {
       int n;
       ++i;
       istringstream ss{argv[i]};
       ss >> n;
       g->setSeed(n);
       srand(n);
     }
     if (arg == "-scriptfile") {
       ++i;
       g->setScriptfile(argv[i]);
     }
     if (arg == "-startlevel") {
       int n;
       ++i;
       istringstream ss{argv[i]};
       ss >> n;
       g->setStartlevel(n);
     }
   }
   g->start();
   g->endit(); //g deleted here
}
      
   
   
