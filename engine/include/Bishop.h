// Code author: Karolis Razma 

#ifndef BISHOP_H
#define BISHOP_H

// libraries
#include "Piece.h"
#include "Square.h" 
#include "Board.h"

class Bishop : public Piece
{
    public:
        // main constructor to init bishop
        Bishop(const string& name, const string& coor, bool isWhite, bool isFirstMove);
        virtual ~Bishop();

        vector<Square> getPossibleMoves(const Board &b) const override;
};

#endif // BISHOP_H
