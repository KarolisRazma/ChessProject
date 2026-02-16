// Code author: Karolis Razma 

#ifndef PAWN_H
#define PAWN_H

// libraries
#include "Piece.h"
#include "Square.h"
#include "Board.h"

class Pawn : public Piece
{
    public:
        // main constructor to init pawn
        Pawn(const string& name, const string& coor, bool isWhite, bool isFirstMove);
        virtual ~Pawn();

        vector<Square> getPossibleMoves(const Board &b) const override;
};

#endif // PAWN_H
