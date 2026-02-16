// Code author: Karolis Razma 

#ifndef ROOK_H
#define ROOK_H

// libraries
#include "Piece.h"
#include "Square.h"
#include "Board.h"

class Rook : public Piece
{
    public:
        // main constructor to init rook
        Rook(const string& name, const string& coor, bool isWhite, bool isFirstMove);
        virtual ~Rook();

        vector<Square> getPossibleMoves(const Board &b) const override;
};

#endif // ROOK_H
