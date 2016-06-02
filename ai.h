#ifndef AI_H
#define AI_H
#include "game.h"
#include <vector>
#include <array>

class AI {
    private:
        char player;
        int choice;
    public:
        int makeMove(Game * game);
        AI(char p);
        int minMax(Game * game, int depth);
        //~AI();
};
#endif