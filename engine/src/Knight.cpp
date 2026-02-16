#include "Knight.h"

Knight::Knight(const string& name, const string& coor, bool isWhite, bool isFirstMove) : Piece(name, coor, isWhite, isFirstMove)
{
    
}

Knight::~Knight()
{
    //dtor
}

vector<Square> Knight::getPossibleMoves(const Board &b) const
{
    vector<Square> allPossibleSquares;
    string coordinate = getCoordinate();
    int index = (int(coordinate[0]) - 97) + ((int(coordinate[1]) - 56) * -8);
    int col = index / 8;
    int row = index % 8;

    if(col-2 >= 0 && row-1 >= 0)
    {
        if(b.getSquare(index - 17).getIsOccupied())
        {
            if(b.getSquare(index - 17).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(index - 17));
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(index - 17));
        }
    }

    if(col-2 >= 0 && row+1 <= 7)
    {
        if(b.getSquare(index - 15).getIsOccupied())
        {
            if(b.getSquare(index - 15).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(index - 15));
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(index - 15));
        }
    }

    if(col-1 >= 0 && row+2 <= 7)
    {
        if(b.getSquare(index - 6).getIsOccupied())
        {
            if(b.getSquare(index - 6).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(index - 6));
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(index - 6));
        }
    }
    if(col+1 <= 7 && row+2 <= 7)
    {
        if(b.getSquare(index + 10).getIsOccupied())
        {
            if(b.getSquare(index + 10).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(index + 10));
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(index + 10));
        }
    }

    if(col+2 <= 7 && row+1 <= 7)
    {
        if(b.getSquare(index + 17).getIsOccupied())
        {
            if(b.getSquare(index + 17).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(index + 17));
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(index + 17));
        }
    }

    if(col+2 <= 7 && row-1 >= 0)
    {
        if(b.getSquare(index + 15).getIsOccupied())
        {
            if(b.getSquare(index + 15).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(index + 15));
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(index + 15));
        }
    }
    if(col+1 <= 7 && row-2 >= 0)
    {
        if(b.getSquare(index + 6).getIsOccupied())
        {
            if(b.getSquare(index + 6).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(index + 6));
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(index + 6));
        }
    }
    if(col-1 >= 0 && row-2 >= 0)
    {
        if(b.getSquare(index - 10).getIsOccupied())
        {
            if(b.getSquare(index - 10).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(index - 10));
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(index - 10));
        }
    }


    return allPossibleSquares;
}
