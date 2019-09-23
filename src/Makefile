CC = g++
CXXFLAGS = -Werror=vla -std=c++14
SRCS = barrierblock.cc command.cc jblock.cc oblock.cc textdisplay.cc block.cc gameplay.cc lblock.cc sblock.cc window.cc board.cc graphicdisplay.cc main.cc score.cc zblock.cc cell.cc iblock.cc nextblock.cc tblock.cc
OBJS=$(SRCS:.cc=.o)
EXE=quadris

.PHONY : clean all

all:
	$(CC) $(CXXFLAGS) -o $(EXE) $(SRCS) -lX11

clean:
	rm  $(EXE) $(OBJS)
