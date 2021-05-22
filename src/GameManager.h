#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Board.h"
#include "Player.h"
using namespace GameBoard;

class GameManager
{
    private:
        Board board;
        Player playerOne;
        Player playerTwo;

    public:
        GameManager();
        ~GameManager();

        void start();
        void saveState();
        void loadState();
        void end();
};

#endif // GAMEMANAGER_H
