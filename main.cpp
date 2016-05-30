#include <iostream>
#include "display.h"
#include "game.h"

int main(int argc, char const *argv[]) {
    Game * g = new Game;
    Display d;
    char winner = '\0';
    while(1) {
        d.printBoard(g);
        char turn = g->getTurn();
        std::cout << "Player " << turn << ", please make a move" << std::endl;
        int valid = 0;
        int move;
        int err = 0;
        while (!valid) {
            std::cin >> move;
            if (move < 0 || move >= 9) {
                std::cout << "Invalid move, please enter a number between 0 and 8 inclusive" << std::endl;
            } else {
                err = g->makeMove(move);
                if (err != -1) valid = 1;
            }
        }
        winner = g->getWinner();
        if (winner != '\0') {
            std::cout << winner << " Wins!!!" << std::endl;
            d.printBoard(g);
            break;
        }
    }
    return 0;
}