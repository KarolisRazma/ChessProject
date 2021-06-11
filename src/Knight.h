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
        Knight(const string& name, const string& coor, bool isWhite, bool isFirstMove, SDL_Renderer * renderer);
        virtual ~Knight();
        // set texture for knight
        void setTexture(SDL_Renderer * renderer);
        // get texture of knight
        SDL_Texture * getTexture() const;
        // returns vector of squares in which can knight be moved
        vector<Square> getPossibleMoves(const Board &b);
};

#endif // KNIGHT_H
