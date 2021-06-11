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
        Queen(const string& name, const string& coor, bool isWhite, bool isFirstMove, SDL_Renderer * renderer);
        virtual ~Queen();
        // set texture for queen
        void setTexture(SDL_Renderer * renderer);
        // get texture of queen
        SDL_Texture * getTexture() const;
        // returns vector of squares in which can queen be moved
        vector<Square> getPossibleMoves(const Board &b);
};

#endif // QUEEN_H
