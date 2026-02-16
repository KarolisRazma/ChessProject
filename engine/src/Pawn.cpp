#include "Pawn.h"

Pawn::Pawn(const string& name, const string& coor, bool isWhite, bool isFirstMove) : Piece(name, coor, isWhite, isFirstMove)
{

}

Pawn::~Pawn()
{
    //dtor
}

vector<Square> Pawn::getPossibleMoves(const Board &b) const
{
    vector<Square> allPossibleSquares;
    string coordinate = getCoordinate();
    int index = (int(coordinate[0]) - 97) + ((int(coordinate[1]) - 56) * -8);
    int col = index / 8;

    if(index - 8 < 0 || index + 8 > 63)
        return allPossibleSquares;
    if(getIsWhite() == false)
    {
        if((b.getSquare(index + 8)).getIsOccupied() == false)
            allPossibleSquares.push_back(b.getSquare(index + 8));
    }
    else
    {
        if((b.getSquare(index - 8)).getIsOccupied() == false)
            allPossibleSquares.push_back(b.getSquare(index - 8));
    }

    if(col == 1 && !getIsWhite())
    {
        if ((b.getSquare(index + 16)).getIsOccupied() == false) {
            if ((b.getSquare(index + 8)).getIsOccupied() == false)
                allPossibleSquares.push_back(b.getSquare(index + 16));
        }
    }
    else if(col == 6 && getIsWhite())
    {
        if ((b.getSquare(index - 16)).getIsOccupied() == false) {
            if ((b.getSquare(index - 8)).getIsOccupied() == false)
                allPossibleSquares.push_back(b.getSquare(index - 16));
        }
    }

    if(getIsWhite() == false)
    {
        if(coordinate[0] != 'h')
        {
            if((b.getSquare(index + 9)).getIsOccupied() == true)
            {
                if(((b.getSquare(index + 9)).getPiece())->getIsWhite() == true)
                    allPossibleSquares.push_back(b.getSquare(index + 9));
            }
        }
        if(coordinate[0] != 'a')
        {
            if((b.getSquare(index + 7)).getIsOccupied() == true)
            {
                if(((b.getSquare(index + 7)).getPiece())->getIsWhite() == true)
                    allPossibleSquares.push_back(b.getSquare(index + 7));
            }
        }

    }
    else
    {
        if(coordinate[0] != 'h')
        {
            if((b.getSquare(index - 7)).getIsOccupied() == true)
            {
                if(((b.getSquare(index - 7)).getPiece())->getIsWhite() == false)
                    allPossibleSquares.push_back(b.getSquare(index - 7));
            }
        }
        if(coordinate[0] != 'a')
        {
            if((b.getSquare(index - 9)).getIsOccupied() == true)
            {
                if(((b.getSquare(index - 9)).getPiece())->getIsWhite() == false)
                    allPossibleSquares.push_back(b.getSquare(index - 9));
            }
        }
    }

    return allPossibleSquares;
}
