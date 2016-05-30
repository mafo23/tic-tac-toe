#include <iostream>
#include "display.h"

void Display::playTurn(Game * game) {
    char square;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            square = game->getSquare(i*3 + j);
            if (square == '\0') square = ' ';
            if (j == 0) {
                std::cout << "| " << square << " | ";
            } else if (j == 1) {
                std::cout << square << " | ";
            } else {
                std::cout << square << " |" << std::endl;
            }
        }
    }
    char turn = game->getTurn();
    std::cout << "Player " << turn << ", please make a move" << std::endl;
    int valid = 0;
    int move;
    int err = 0;
    while (!valid) {
        std::cin >> move;
        if (move < 0 || move >= 9) {
            std::cout << "Invalid move, please enter a number between 0 and 8 inclusive" << std::endl;
        } else {
            err = game->makeMove(move);
            if (err != -1) valid = 1;
        }
    }
}