// Code author: Karolis Razma 

#ifndef PLAYER_H
#define PLAYER_H

// libraries
#include "Board.h"
#include <SDL.h>

class Player
{
    private:
        bool isWhite;
        string start;
        string destination;
    public:
        Player();
        virtual ~Player();
        // sets starting position of the move
        void setStart(const string& start);
        // sets destination square
        void setDestination(const string& dest);
        // gets starting position
        string getStart() const;
        // gets destination square
        string getDestination() const;
        // sets player is in White team or in Black team
        void setIsWhite(bool isWhite);
        // gets player team
        bool getIsWhite() const;
        // tries to make a move and returns if moves was made successfully
        bool makeMove(Board &currentState, SDL_Renderer * renderer);
};

#endif // PLAYER_H
