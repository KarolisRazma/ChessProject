#include "Piece.h"

Piece::Piece()
{
}

Piece::Piece(const string& name, const string& coor, bool isWhite, bool isFirstMove)
{
    setName(name);
    setCoordinate(coor);
    setIsWhite(isWhite);
    setIsFirstMove(isFirstMove);
}

Piece::~Piece()
{
    //dtor
}

void Piece::setName(const string& name)
{
    this->name = name;
}

void Piece::setCoordinate(const string& coor)
{
    this->coordinate = coor;
}

void Piece::setIsWhite(bool isWhite)
{
    this->isWhite = isWhite;
}

void Piece::setIsFirstMove(bool isFirstMove)
{
    this->isFirstMove = isFirstMove;
}

string Piece::getName() const
{
    return name;
}

string Piece::getCoordinate() const
{
    return coordinate;
}

bool Piece::getIsWhite() const
{
    return isWhite;
}

bool Piece::getIsFirstMove() const
{
    return isFirstMove;
}

void Piece::deleteTexture()
{
    SDL_DestroyTexture(texture);
}
