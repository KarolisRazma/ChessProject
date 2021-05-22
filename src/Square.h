#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include "Piece.h"
using namespace Pieces;
using std::string;

class Square
{
   private:
        string coordinate;
        bool isOccupied;
        Piece* piece;

    public:
        Square();
        Square(const string& coordinate);
        ~Square();

        void setPiece(Piece *piece);
        void setIsOccupied(bool isOccupied);
        string getCoordinate() const;
        bool getIsOccupied() const;
        Piece * getPiece() const;
        void destroyPiece();
};

#endif // SQUARE_H
