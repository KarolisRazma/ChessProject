// Code author: Karolis Razma 

#ifndef KNIGHT_H
#define KNIGHT_H

// libraries
#include "Piece.h"
#include "Square.h"
#include "Board.h"

class Knight : public Piece
{
    public:
        // main constructor to init knight
        Knight(const string& name, const string& coor, bool isWhite, bool isFirstMove);
        virtual ~Knight();

        vector<Square> getPossibleMoves(const Board &b) const override;
};

#endif // KNIGHT_H
