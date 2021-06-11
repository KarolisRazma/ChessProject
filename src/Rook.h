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
        Rook(const string& name, const string& coor, bool isWhite, bool isFirstMove, SDL_Renderer * renderer);
        virtual ~Rook();
        // set texture for rook
        void setTexture(SDL_Renderer * renderer);
        // get texture of rook
        SDL_Texture * getTexture() const;
        // returns vector of squares in which can rook be moved
        vector<Square> getPossibleMoves(const Board &b);
};

#endif // ROOK_H
