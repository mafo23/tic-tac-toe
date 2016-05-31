#include <iostream>
#include <limits>
#include "display.h"
#include "game.h"
#include "ai.h"

void twoPlayer();
void singlePlayer();

int main(int argc, char const *argv[]) {
    int v;
    std::cout << "If you would like to play vs a computer, enter 1, otherwise, enter 2" << std::endl;
    while (!(std::cin >> v && (v == 1 || v == 2))) {
        std::cout << "If you would like to play vs a computer, enter 1, otherwise, enter 2" << std::endl;
        std::cout << "Version is " << v << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (v == 1) {
        singlePlayer();
    } else {
        twoPlayer();
    }
    return 0;
}

void singlePlayer() {
    Game * g = new Game;
    Display d;
    char winner = '\0';
    char playerTurn;
    char pcTurn;

    std::cout << "Please either choose x/X or o/O" << std::endl;
    while (!(std::cin >> playerTurn && (playerTurn == 'x' || playerTurn == 'X' || playerTurn == 'o' || playerTurn == 'O'))) {
        std::cout << "Please either choose x/X or o/O" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (playerTurn == 'X') {
        playerTurn = 'x';
        pcTurn = 'o';
    } else if (playerTurn == 'O') {
        playerTurn = 'o';
        pcTurn = 'x';
    } else if (playerTurn == 'x') {
        pcTurn = 'o';
    } else {
        pcTurn = 'x';
    }

    AI a(pcTurn);

    while (1) {
        int err = 0;
        d.printBoard(g);
        char turn = g->getTurn();
        if (turn == playerTurn) {
            std::cout << "Player " << turn << ", please make a move" << std::endl;
            int valid = 0;
            int move = -1;


            while (!valid) {
                while(!(std::cin >> move && (move >=0 && move < 9))){
                    std::cout << "Invalid move, please enter a number between 0 and 8 inclusive" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                err = g->makeMove(move);
                if (err != -1) {
                    valid = 1;
                } else {
                    std::cout << "Square is already taken, please choose a new square" << std::endl;
                }
            }

            winner = g->getWinner();
            if (winner != '\0') {
                if (winner == 'n') {
                    std::cout << "Noone Wins :(" << std::endl;
                } else {
                    std::cout << winner << " Wins!!!" << std::endl;
                }
                d.printBoard(g);
                break;
            }
        } else {
            int move = a.makeMove(g);
            if (move == -1) {
                std::cout << "Error" << std::endl;
                exit(0);
            }
            int err = g->makeMove(move);
            if (err == -1) {
                std::cout << "Error" << std::endl;
                std::cout << "Move " << move << std::endl;
                exit(0);
            }
            winner = g->getWinner();
            if (winner != '\0') {
                if (winner == 'n') {
                    std::cout << "Noone Wins :(" << std::endl;
                } else {
                    std::cout << winner << " Wins!!!" << std::endl;
                }
                d.printBoard(g);
                break;
            }
        }
    }
}

void twoPlayer() {
    Game * g = new Game;
    Display d;
    char winner = '\0';
    while(1) {
        d.printBoard(g);
        char turn = g->getTurn();
        std::cout << "Player " << turn << ", please make a move" << std::endl;
        int valid = 0;
        int move = -1;
        int err = 0;
        while (!valid) {
            while(!(std::cin >> move && (move >=0 && move < 9))){
                std::cout << "Invalid move, please enter a number between 0 and 8 inclusive" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            err = g->makeMove(move);
            if (err != -1) {
                valid = 1;
            } else {
                std::cout << "Square is already taken, please choose a new square" << std::endl;
            }
        }
        winner = g->getWinner();
        if (winner != '\0') {
            if (winner == 'n') {
                std::cout << "Noone Wins :(" << std::endl;
            } else {
                std::cout << winner << " Wins!!!" << std::endl;
            }
            d.printBoard(g);
            break;
        }
    }
}