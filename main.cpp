#include <iostream>
#include "display.h"
#include "game.h"

int main(int argc, char const *argv[]) {
    Game game;
    Display d;
    char winner = '\0';
    while(1) {
        d.playTurn(&game);
        winner = game.getWinner();
        if (winner != '\0') {
            std::cout << winner << " Wins!!!" << std::endl;
            break;
        }
    }
    return 0;
}