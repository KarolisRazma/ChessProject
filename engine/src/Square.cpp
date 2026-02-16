#include "Square.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"

Square::Square()
{
    piece = NULL;
    isOccupied = false;
}

Square::Square(const Square& other)
{
    setCoordinate(other.getCoordinate());
    setIsOccupied(other.getIsOccupied());
    Piece* temp = NULL;
    if (Pawn * p = dynamic_cast<Pawn*>(other.getPiece()))
    {
        temp = new Pawn(*p);
    }
    if (Knight * kn = dynamic_cast<Knight*>(other.getPiece()))
    {
        temp = new Knight(*kn);
    }
    if (Bishop * b = dynamic_cast<Bishop*>(other.getPiece()))
    {
        temp = new Bishop(*b);
    }
    if (Queen * q = dynamic_cast<Queen*>(other.getPiece()))
    {
        temp = new Queen(*q);
    }
    if (King * k = dynamic_cast<King*>(other.getPiece()))
    {
        temp = new King(*k);
    }
    if (Rook * r = dynamic_cast<Rook*>(other.getPiece()))
    {
        temp = new Rook(*r);
    }
    if (temp != NULL) 
        setPiece(temp);
    else
        setPiece(NULL);
}

Square::Square(const string& coordinate)
{
    setCoordinate(coordinate);
    setIsOccupied(false);
    setPiece(NULL);
}

Square::~Square()
{
    destroyPiece();
}

void Square::setCoordinate(const string& coordinate)
{
    this->coordinate = coordinate;
}

void Square::setPiece(Piece *piece)
{
    this->piece = piece;
    if(piece != NULL)
        setIsOccupied(true);
    else
        setIsOccupied(false);
}

void Square::setIsOccupied(bool isOccupied)
{
    this->isOccupied = isOccupied;
}

string Square::getCoordinate() const
{
    return coordinate;
}

bool Square::getIsOccupied() const
{
    return isOccupied;
}

Piece * Square::getPiece() const
{
    if(piece != NULL)
        return piece;
    else
        return NULL;
}

void Square::destroyPiece()
{
    if (piece != NULL) {
        delete piece;
    }
}

Square& Square::operator=(const Square& other)
{
    // Guard self assignment
    if (this == &other)
        return *this;

    Piece* temp = NULL;
    if (Pawn* p = dynamic_cast<Pawn*>(other.getPiece()))
    {
        temp = new Pawn(*p);
    }
    if (Knight* kn = dynamic_cast<Knight*>(other.getPiece()))
    {
        temp = new Knight(*kn);
    }
    if (Bishop* b = dynamic_cast<Bishop*>(other.getPiece()))
    {
        temp = new Bishop(*b);
    }
    if (Queen* q = dynamic_cast<Queen*>(other.getPiece()))
    {
        temp = new Queen(*q);
    }
    if (King* k = dynamic_cast<King*>(other.getPiece()))
    {
        temp = new King(*k);
    }
    if (Rook* r = dynamic_cast<Rook*>(other.getPiece()))
    {
        temp = new Rook(*r);
    }

    if (piece != NULL)
    {
        delete piece;
        piece = temp;
    }
    else
    {
        piece = temp;
    }

    coordinate = other.getCoordinate();
    isOccupied = other.getIsOccupied();

    return *this;
}
