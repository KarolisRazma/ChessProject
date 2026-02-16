// Code author: Karolis Razma 

#ifndef QUEEN_H
#define QUEEN_H

// libraries
#include "Piece.h"
#include "Square.h"
#include "Board.h"

class Queen : public Piece
{
    public:
        // main constructor to init queen
        Queen(const string& name, const string& coor, bool isWhite, bool isFirstMove);
        virtual ~Queen();

        vector<Square> getPossibleMoves(const Board &b) const override;
};

#endif // QUEEN_H
