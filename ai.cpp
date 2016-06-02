#include "ai.h"

int AI::makeMove(Game * game) {
    Game * g = new Game();
    memcpy(g, game, sizeof(Game));
    minMax(g, 0);
    return this->choice;
}

AI::AI(char p) {
    player = p;
    choice = -1;
}

int AI::minMax(Game * game, int depth) {
    char winner = game->getWinner();
    if (winner != '\0') {
        if (winner == this->player){
        return 10 - depth;
        } else if (winner != 'n') {
            return -10 + depth;
        } else {
            return 0 + depth;
        }
    }


    char board[9];
    std::vector<int> moves;
    std::vector<int> scores;

    for (int i = 0; i < 9; ++i) {
        board[i] = game->getSquare(i);
        if (board[i] == '\0') moves.push_back(i);
    }
    for (std::vector<int>::size_type i = 0; i < moves.size(); ++i) {
        Game * g = new Game();
        memcpy(g, game, sizeof(Game));
        g->makeMove(moves[i]);
        scores.push_back(minMax(g, depth+1));
    }

    if(game->getTurn() == this->player) {
        std::vector<int>::size_type maxScoreIndex = 0;
        for (std::vector<int>::size_type i = 0; i < scores.size(); ++i) {
            if (scores[i] > scores[maxScoreIndex]) maxScoreIndex = i;
        }
        this->choice = moves[maxScoreIndex];
        return scores[maxScoreIndex];
    } else {
        std::vector<int>::size_type minScoreIndex = 0;
        for (std::vector<int>::size_type i = 0; i < scores.size(); ++i) {
            if (scores[i] < scores[minScoreIndex]) minScoreIndex = i;
        }
        this->choice = moves[minScoreIndex];
        return scores[minScoreIndex];
    }
}