CFLAGS=-std=c99 -pedantic-errors -c -Wall -g -lm
OBJ=Console/Console.o Gui/Gui.o Settings.o

all: chessprog 

clean:
	-rm chessprog $(OBJ)

chessprog: $(OBJ)
	gcc -o chessprog $(OBJ) -lm -std=c99 -pedantic-errors -g `sdl-config --libs`

Main.o: Main.c Main.h
	gcc $(CFLAGS) Main.c

Console/Console.o: Console/Console.c Console/Console.h
	gcc $(CFLAGS) Console/Console.c

Gui/Gui.o: Gui/Gui.c Gui/Gui.h
	gcc $(CFLAGS) Gui/Gui.c `sdl-config --cflags`

Settings.o: Settings.c Settings.h
	gcc $(CFLAGS) Settings.c