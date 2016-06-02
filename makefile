uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')

CC = g++
CFLAGS = -Wall -Werror -std=c++11

ifeq ($(uname_S),Darwin)
	CC = clang++
endif

all: tictactoe

tictactoe: build/main.o build/ai.o build/display.o build/game.o
	$(CC) $(CFLAGS) build/*.o -o a.out

build/main.o: main.cpp game.h display.h ai.h
	$(CC) $(CFLAGS) -c main.cpp -o build/main.o

build/display.o: display.cpp display.h game.h
	$(CC) $(CFLAGS) -c display.cpp -o build/display.o

build/game.o: game.cpp game.h
	$(CC) $(CFLAGS) -c game.cpp -o build/game.o

build/ai.o: ai.cpp ai.h game.h
	$(CC) $(CFLAGS) -c ai.cpp -o build/ai.o

clean:
	rm -rf build/*
	rm -rf a.out

