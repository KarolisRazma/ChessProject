#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include "Movement.h"
#include <string>
using std::string;

class Player
{
    private:
        string team;
        Board currentState;

    public:
        Player();
        ~Player();

        void setTeam(const string& team);
        void setCurrentState(const Board& currentState);

        string getTeam() const;
        Board getCurrentState() const;

        void resign();
        Board makeMove(const string& startCoordinate, const string& finishCoordinate);
};

#endif // PLAYER_H
