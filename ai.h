#ifndef AI_H
#define AI_H
#include "game.h"

class AI {
    private:
        char player;
    public:
        int makeMove(Game * game);
        AI(char p);
        //~AI();
};
#endif