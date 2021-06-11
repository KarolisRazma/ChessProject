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
        Bishop(const string& name, const string& coor, bool isWhite, bool isFirstMove, SDL_Renderer * renderer);
        virtual ~Bishop();
        // set texture for bishop
        void setTexture(SDL_Renderer * renderer);
        // get texture of bishop
        SDL_Texture * getTexture() const;
        // returns vector of squares in which can bishop be moved
        vector<Square> getPossibleMoves(const Board &b);
};

#endif // BISHOP_H
