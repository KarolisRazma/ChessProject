#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "Board.h"
#include "Square.h"

using namespace GameBoard;

class Movement
{
    private:
        Square startingPoint;
    public:
        Movement(const Square& startingPoint);
        virtual ~Movement();
        void setStartingPoint(const Square& startingPoint);
        Square getStartingPoint() const;
        std::vector<Square> getPossibleMovement(Board &b);
};

#endif // MOVEMENT_H
