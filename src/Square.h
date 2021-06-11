// Code author: Karolis Razma 

#ifndef SQUARE_H
#define SQUARE_H

// libraries
#include <string>
#include "Piece.h"
// namespaces
using std::string;

const int SQUARE_HEIGHT = 100;
const int SQUARE_WIDTH = 100;

class Square
{
     private:
        string coordinate;
        bool isOccupied;
        Piece* piece;
        SDL_Rect rect;
    public:
        // default constructor
        Square();
        // copy constructor
        Square(const Square& other);
        // main constructor for building square
        Square(const string& coordinate, SDL_Renderer * renderer);
        ~Square();
        // sets square's coordinate
        void setCoordinate(const string& coordinate);
        // sets square's piece
        void setPiece(Piece *piece);
        // sets if square is occupied or not
        void setIsOccupied(bool isOccupied);
        // sets square color to light/dark or changes it temporary for danger zone(possible attacks, moves)
        void setSquareColor(SDL_Renderer * renderer, SDL_Color danger = { 0, 0, 0, 255 });
        // gets square's coordinate
        string getCoordinate() const;
        // gets if square is occupied or not
        bool getIsOccupied() const;
        // gets square's piece, if no piece then returns NULL
        Piece * getPiece() const;
        // destroys piece
        void destroyPiece();
        // overloaded operator= for deep copy
        Square& operator=(const Square& other);
};

#endif // SQUARE_H
