#include "Rook.h"

Rook::Rook(const string& name, const string& coor, bool isWhite, bool isFirstMove) : Piece(name, coor, isWhite, isFirstMove)
{

}

Rook::~Rook()
{
    //dtor
}

vector<Square> Rook::getPossibleMoves(const Board &b) const
{
    vector<Square> allPossibleSquares;
    string coordinate = getCoordinate();
    int index = (int(coordinate[0]) - 97) + ((int(coordinate[1]) - 56) * -8);

    int tempIndex = index;
    while(tempIndex + 8 < 63)
    {
        tempIndex += 8;
        if((b.getSquare(tempIndex)).getIsOccupied() == false)
            allPossibleSquares.push_back(b.getSquare(tempIndex));
        else
        {
            if(((b.getSquare(tempIndex)).getPiece())->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(tempIndex));
                break;
            }
            else
                break;
        }
    }
    tempIndex = index;
    while(tempIndex - 8 > 0)
    {
        tempIndex -= 8;
        if((b.getSquare(tempIndex)).getIsOccupied() == false)
            allPossibleSquares.push_back(b.getSquare(tempIndex));
        else
        {
            if(((b.getSquare(tempIndex)).getPiece())->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(tempIndex));
                break;
            }
            else
                break;
        }
    }

    int leftHorizontalSquares = index % 8;
    int rightHorizontalSquares = 7 - leftHorizontalSquares;
    for(int i = index-1; i > index-leftHorizontalSquares-1; --i)
    {
        if((b.getSquare(i)).getIsOccupied() == false)
            allPossibleSquares.push_back(b.getSquare(i));
        else
        {
            if(((b.getSquare(i)).getPiece())->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(i));
                break;
            }
            else
                break;
        }
    }
    for(int i = index+1; i < index+rightHorizontalSquares+1; ++i)
    {
        if((b.getSquare(i)).getIsOccupied() == false)
            allPossibleSquares.push_back(b.getSquare(i));
        else
        {
            if(((b.getSquare(i)).getPiece())->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(i));
                break;
            }
            else
                break;
        }
    }

    return allPossibleSquares;
}
