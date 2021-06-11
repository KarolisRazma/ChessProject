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
        King(const string& name, const string& coor, bool isWhite, bool isFirstMove, SDL_Renderer * renderer);
        virtual ~King();
        // set texture for king
        void setTexture(SDL_Renderer * renderer);
        // get texture of king
        SDL_Texture * getTexture() const;
        // returns vector of squares in which can king be moved
        vector<Square> getPossibleMoves(const Board &b);
};

#endif // KING_H
