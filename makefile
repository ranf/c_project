CFLAGS=-std=c99 -pedantic-errors -c -Wall -g -lm
CONSOLE_OBJ=Console/Console.o Console/Settings.o Console/Board.o Console/Game.o
COMMON_OBJ=Common/Common.o Common/Board.o Common/Position.o Common/Move.o
OBJ=Main.o $(CONSOLE_OBJ) $(COMMON_OBJ) Gui/Gui.o

all: chessprog

clean:
	-rm chessprog $(OBJ)

chessprog: $(OBJ)
	gcc -o chessprog $(OBJ) -lm -std=c99 -pedantic-errors -g `sdl-config --libs`

Main.o: Main.c Main.h
	gcc $(CFLAGS) Main.c

Console/Console.o: Console/Console.c Console/Console.h
	gcc $(CFLAGS) Console/Console.c -o Console/Console.o

Console/Settings.o: Console/Settings.c Console/Settings.h
	gcc $(CFLAGS) Console/Settings.c -o Console/Settings.o

Console/Board.o: Console/Board.c Console/Board.h
	gcc $(CFLAGS) Console/Board.c -o Console/Board.o

Console/Game.o: Console/Game.c Console/Game.h
	gcc $(CFLAGS) Console/Game.c -o Console/Game.o

Common/Common.o: Common/Common.c Common/Common.h
	gcc $(CFLAGS) Common/Common.c -o Common/Common.o

Common/Board.o: Common/Board.c Common/Board.h
	gcc $(CFLAGS) Common/Board.c -o Common/Board.o

Common/Position.o: Common/Position.c Common/Position.h
	gcc $(CFLAGS) Common/Position.c -o Common/Position.o

Common/Move.o: Common/Move.c Common/Move.h
	gcc $(CFLAGS) Common/Move.c -o Common/Move.o

Gui/Gui.o: Gui/Gui.c Gui/Gui.h
	gcc $(CFLAGS) Gui/Gui.c `sdl-config --cflags` -o Gui/Gui.o