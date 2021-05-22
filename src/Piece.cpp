#include "Piece.h"

namespace Pieces
{
    // Base class Piece methods
    Piece::Piece(string name, int value, bool isWhite)
    {

    }

    Piece::~Piece()
    {

    }

    // setters
    void Piece::setName(string name)
    {

    }

    void Piece::setValue(int value)
    {

    }

    void Piece::setIsWhite(bool isWhite)
    {

    }

    // getters
    string Piece::getName() const
    {
        return name;
    }

    int Piece::getValue() const
    {
        return value;
    }

    bool Piece::getIsWhite() const
    {
        return isWhite;
    }
    // the end of base class Piece methods

    // Derived class Pawn methods
    Pawn::Pawn(string name, int value, bool isWhite) : Piece(name, value, isWhite)
    {

    }

    Pawn::~Pawn()
    {

    }

    void Pawn::setIsFirstMove(bool isFirstMove)
    {

    }

    bool Pawn::getIsFirstMove() const
    {
        return isFirstMove;
    }

    // the end of derived class Pawn methods

    // Derived class Knight methods
    Knight::Knight(string name, int value, bool isWhite) : Piece(name, value, isWhite)
    {

    }

    Knight::~Knight()
    {

    }
    // the end of derived class Knight methods

    // Derived class Bishop methods
    Bishop::Bishop(string name, int value, bool isWhite) : Piece(name, value, isWhite)
    {

    }

    Bishop::~Bishop()
    {

    }
    // the end of derived class Bishop methods

    // Derived class Rook methods
    Rook::Rook(string name, int value, bool isWhite) : Piece(name, value, isWhite)
    {

    }

    Rook::~Rook()
    {

    }
    // the end of derived class Rook methods

    // Derived class Queen methods
    Queen::Queen(string name, int value, bool isWhite) : Piece(name, value, isWhite)
    {

    }

    Queen::~Queen()
    {

    }
    // the end of derived class Queen methods

    // Derived class King methods
    King::King(string name, int value, bool isWhite) : Piece(name, value, isWhite)
    {

    }

    King::~King()
    {

    }
    // the end of derived class King methods
}
