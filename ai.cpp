#include "ai.h"

int AI::makeMove(Game * game) {
    char board[9];
    for (int i = 0; i < 9; ++i) {
        board[i] = game->getSquare(i);
    }
    // Check Win Conditions
    if (board[0] == player) {
        if (board[0] == board[1] && board[2] == '\0') {
            return 2;
        } else if (board[0] == board[2] && board[1] == '\0') {
            return 1;
        } else if (board[0] == board[3] && board[6] == '\0') {
            return 6;
        } else if (board[0] == board[6] && board[3] == '\0') {
            return 3;
        } else if (board[0] == board[4] && board[8] == '\0') {
            return 8;
        } else if (board[0] == board[8] && board[4] == '\0') {
            return 4;
        }
    } else if (board[1] == player) {
        if (board[1] == board[2] && board[0] == '\0') {
            return 0;
        } else if (board[1] == board[4] && board[7] == '\0') {
            return 7;
        } else if (board[1] == board[7] && board[4] == '\0') {
            return 4;
        }
    } else if (board[2] == player) {
        if (board[2] == board[4] && board[6] == '\0') {
            return 6;
        } else if (board[2] == board[6] && board[4] == '\0') {
            return 4;
        } else if (board[2] == board[5] && board[8] == '\0') {
            return 8;
        } else if (board[2] == board[8] && board[5] == '\0') {
            return 5;
        }
    } else if (board[3] == player) {
        if (board[3] == board[6] && board[0] == '\0') {
            return 0;
        } else if (board[3] == board[4] && board[5] == '\0') {
            return 5;
        } else if (board[3] == board[5] && board[4] == '\0') {
            return 4;
        }
    } else if (board[4] == player) {
        if (board[4] == board[5] && board[3] == '\0') {
            return 3;
        } else if (board[4] == board[7] && board[1] == '\0') {
            return 1;
        } else if (board[4] == board[8] && board[0] == '\0') {
            return 0;
        } else if (board[4] == board[6] && board[2] == '\0') {
            return 2;
        }
    } else if (board[5] == player) {
        if (board[5] == board[8] && board[2] == '\0') {
            return 2;
        }
    } else if (board[6] == player) {
        if (board[6] == board[7] && board[8] == '\0') {
            return 8;
        } else if (board[6] == board[8] && board[7] == '\0') {
            return 7;
        }
    }

    // Otherwise
    for (int i = 0; i < 9; ++i) {
        if (board[i] == '\0') return i;
    }
    return -1;
}

AI::AI(char p) {
    player = p;
}