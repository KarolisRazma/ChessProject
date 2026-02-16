// Code author: Karolis Razma 

#ifndef KING_H
#define KING_H

// libraries
#include "Piece.h"
#include "Square.h"
#include "Board.h"

class King : public Piece
{
    public:
        // main constructor to init king
        King(const string& name, const string& coor, bool isWhite, bool isFirstMove);
        virtual ~King();

        vector<Square> getPossibleMoves(const Board &b) const override;
};

#endif // KING_H
