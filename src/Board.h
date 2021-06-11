// Code author: Karolis Razma 
// Game board header 

#ifndef BOARD_H
#define BOARD_H

// libraries
#include "Square.h"
#include <SDL.h>
#include <vector>

const int BOARD_SIZE = 8;

class Board
{
    private:
        Square squares[BOARD_SIZE][BOARD_SIZE];
        string whiteKingLocation;
        string blackKingLocation;

    public:
        Board();
        ~Board();

        // creates chess board
        void create(SDL_Renderer * renderer);
        // destroys chess board
        void destroy();
        // moves piece on the board
        void movePiece(Square startSquare, Square destSquare, bool isWhite, SDL_Renderer * renderer);
        // finds legal moves for a piece
        vector<Square> findLegalMoves(vector<Square>& possibleMoves, bool isWhite, Square startSquare);
        // sets white king coordinate
        void setWhiteKingLocation(const string& location);
        // sets black king coordinate
        void setBlackKingLocation(const string& location);
        // gets white king coordinate
        string getWhiteKingLocation() const;
        // gets white king square
        string getBlackKingLocation() const;
        // gets black king square
        Square getWhiteKingSquare() const;
        // gets black king coordinate
        Square getBlackKingSquare() const;
        // gets pieces of selected team (1 - white, 0 - black)
        vector<Piece*> getPieces(bool isWhite) const;
        // sets given square into given index
        void setSquare(const Square& square, int index);
        // gets square from given index
        Square getSquare(int index) const;
        // destroy every piece texture
        void destroyTextures();
        // renders all danger zone squares in different color and returns vector with squares that are 
        vector<Square> renderDangerZones(bool isWhite, const Square& selectedSquare, SDL_Renderer* renderer);
        // boolean to check if any endgame events occured
        bool isEndgame();

    private:
        // boolean to check if king is in check (requires enemy pieces, current board and king square)
        bool isChecked(vector<Piece*> enemyPieces, const Board& tempBoard, Square kingSquare);
        // boolean to check if king is checkmated (requires ally pieces and king square)
        bool isCheckmate(vector<Piece*> myPieces, Square kingSquare);
        // boolean to check if it is a draw
        bool isDraw();
        // boolean to check if king is in stalemate
        bool isStalemate(vector<Piece*> myPieces, Square kingSquare);
        // boolean to check if special move "castling" is legal (requires start/destination squares and current board)
        bool isItLegalToCastle(Square startSquare, Square finishSquare, Board& tempBoard);
};

#endif // BOARD_H
