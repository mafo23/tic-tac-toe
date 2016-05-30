#include "game.h"

char Game::getSquare (int index) {
    if (index < 0 || index >= 9) return 'e';
    return board[index];
}

int Game::getMoveCounter() {
    return moveCounter;
}

char Game::getWinner() {
    return winner;
}

char Game::getTurn() {
    return turn;
}

int Game::makeMove(int move) {
    if (board[move] != '\0') return -1;
    board[move] = turn;
    if (turn == 'x') {
        turn = 'o';
    } else {
        turn = 'x';
    }
    ++moveCounter;
    isWon();
    return 0;
}

void Game::isWon() {
    if (board[0] == board[1] && board[1] == board[2] && board[0] != '\0') { // Top Row
        winner = board[0];
    } else if (board[3] == board[4] && board[4] == board[5] && board[3] != '\0') { // Middle Row
        winner = board[3];
    } else if (board[6] == board[7] && board[7] == board[8] && board[6] != '\0') { // Bottom Row
        winner = board[6];
    } else if (board[0] == board[3] && board[3] == board[6] && board[0] != '\0') { // First Column
        winner = board[0];
    } else if (board[1] == board[4] && board[4] == board[7] && board[1] != '\0') { // Second Column
        winner = board[1];
    } else if (board[2] == board[5] && board[5] == board[8] && board[2] != '\0') { // Third Column
        winner = board[2];
    } else if (board[0] == board[4] && board[4] == board[8] && board[0] != '\0') { // Left-Top to Right-Bottom Diagonal
        winner = board[0];
    } else if (board[2] == board[4] && board[4] == board[6] && board[2] != '\0') { // Right-Top to Left-Bottom Diagonal
        winner = board[2];
    }
}

Game::Game() {
    for (int i = 0; i < 9; ++i) {
        board[i] = '\0';
    }
    turn = 'x';
    winner = '\0';
    moveCounter = 0;
}