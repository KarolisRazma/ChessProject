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
        Pawn(const string& name, const string& coor, bool isWhite, bool isFirstMove, SDL_Renderer * renderer);
        virtual ~Pawn();
        // sets texture for pawn 
        void setTexture(SDL_Renderer * renderer);
        // gets texture of pawn
        SDL_Texture * getTexture() const;
        // returns vector of squares in which can pawn be moved
        vector<Square> getPossibleMoves(const Board &b);
};

#endif // PAWN_H
