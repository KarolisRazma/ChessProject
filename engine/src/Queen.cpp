#include "Queen.h"

Queen::Queen(const string& name, const string& coor, bool isWhite, bool isFirstMove) : Piece(name, coor, isWhite, isFirstMove)
{

}

Queen::~Queen()
{
    //dtor
}

vector<Square> Queen::getPossibleMoves(const Board &b) const
{
    vector<Square> allPossibleSquares;
    string coordinate = getCoordinate();
    int index = (int(coordinate[0]) - 97) + ((int(coordinate[1]) - 56) * -8);
    int tempIndex = index;
    int col = index / 8;
    int row = index % 8;

    while(col-1 >= 0 && row-1 >= 0)
    {
        --col;
        --row;
        if(b.getSquare(tempIndex - 9).getIsOccupied())
        {
            if(b.getSquare(tempIndex - 9).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(tempIndex - 9));
                break;
            }
            else
            {
                break;
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(tempIndex - 9));
        }
        tempIndex -= 9;
    }

    tempIndex = index;
    col = index / 8;
    row = index % 8;
    while(col+1 <= 7 && row+1 <= 7)
    {
        ++col;
        ++row;
        if(b.getSquare(tempIndex + 9).getIsOccupied())
        {
            if(b.getSquare(tempIndex + 9).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(tempIndex + 9));
                break;
            }
            else
            {
                break;
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(tempIndex + 9));
        }
        tempIndex += 9;
    }

    tempIndex = index;
    col = index / 8;
    row = index % 8;
    while(col+1 <= 7 && row-1 >= 0)
    {
        ++col;
        --row;
        if(b.getSquare(tempIndex + 7).getIsOccupied())
        {
            if(b.getSquare(tempIndex + 7).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(tempIndex + 7));
                break;
            }
            else
            {
                break;
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(tempIndex + 7));
        }
        tempIndex += 7;
    }

    tempIndex = index;
    col = index / 8;
    row = index % 8;
    while(col-1 >= 0 && row+1 <= 7)
    {
        --col;
        ++row;
        if(b.getSquare(tempIndex - 7).getIsOccupied())
        {
            if(b.getSquare(tempIndex - 7).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(tempIndex - 7));
                break;
            }
            else
            {
                break;
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(tempIndex - 7));
        }
        tempIndex -= 7;
    }

    tempIndex = index;
    col = index / 8;
    while(col-1 >= 0)
    {
        --col;
        if(b.getSquare(tempIndex - 8).getIsOccupied())
        {
            if(b.getSquare(tempIndex - 8).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(tempIndex - 8));
                break;
            }
            else
            {
                break;
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(tempIndex - 8));
        }
        tempIndex -= 8;
    }

    tempIndex = index;
    col = index / 8;
    while(col+1 <= 7)
    {
        ++col;
        if(b.getSquare(tempIndex + 8).getIsOccupied())
        {
            if(b.getSquare(tempIndex + 8).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(tempIndex + 8));
                break;
            }
            else
            {
                break;
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(tempIndex + 8));
        }
        tempIndex += 8;
    }

    tempIndex = index;
    row = index % 8;
    while(row+1 <= 7)
    {
        ++row;
        if(b.getSquare(tempIndex + 1).getIsOccupied())
        {
            if(b.getSquare(tempIndex + 1).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(tempIndex + 1));
                break;
            }
            else
            {
                break;
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(tempIndex + 1));
        }
        ++tempIndex;
    }

    tempIndex = index;
    row = index % 8;
    while(row-1 >= 0)
    {
        --row;
        if(b.getSquare(tempIndex - 1).getIsOccupied())
        {
            if(b.getSquare(tempIndex - 1).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(tempIndex - 1));
                break;
            }
            else
            {
                break;
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(tempIndex - 1));
        }
        --tempIndex;
    }

    return allPossibleSquares;
}
