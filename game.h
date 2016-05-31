#ifndef GAME_H
#define GAME_H

class Game {
    private:
        char board[9];
        int moveCounter;
        char winner;
        char turn;
    public:
        char getSquare (int index);
        int getMoveCounter();
        char getWinner();
        char getTurn();
        int makeMove(int move);
        void isWon();
        Game();
        //~Game();
};

#endif