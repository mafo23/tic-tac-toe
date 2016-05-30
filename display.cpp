#include <iostream>
#include "display.h"

void Display::printBoard(Game * game) {
    char square;
    for (int i = 0; i < 3; ++i) {
        std::cout << "-------------" << std::endl;
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
    std::cout << "-------------" << std::endl;
}