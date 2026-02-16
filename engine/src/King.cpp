#include "King.h"
#include "Rook.h"

King::King(const string& name, const string& coor, bool isWhite, bool isFirstMove) : Piece(name, coor, isWhite, isFirstMove)
{

}

King::~King()
{
    //dtor
}

vector<Square> King::getPossibleMoves(const Board &b) const
{

    vector<Square> allPossibleSquares;
    string coordinate = getCoordinate();
    int index = (int(coordinate[0]) - 97) + ((int(coordinate[1]) - 56) * -8);
    int col = index / 8;
    int row = index % 8;

    if(col-1 >= 0)
    {
        if(b.getSquare(index - 8).getIsOccupied())
        {
            if(b.getSquare(index - 8).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(index - 8));
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(index - 8));
        }
        if(row-1 >= 0)
        {
            if(b.getSquare(index - 9).getIsOccupied())
            {
                if(b.getSquare(index - 9).getPiece()->getIsWhite() != getIsWhite())
                {
                    allPossibleSquares.push_back(b.getSquare(index - 9));
                }
            }
            else
            {
                allPossibleSquares.push_back(b.getSquare(index - 9));
            }
        }
        if(row+1 <= 7)
        {
            if(b.getSquare(index - 7).getIsOccupied())
            {
                if(b.getSquare(index - 7).getPiece()->getIsWhite() != getIsWhite())
                {
                    allPossibleSquares.push_back(b.getSquare(index - 7));
                }
            }
            else
            {
                allPossibleSquares.push_back(b.getSquare(index - 7));
            }
        }
    }
    if(col+1 <= 7)
    {
        if(b.getSquare(index + 8).getIsOccupied())
        {
            if(b.getSquare(index + 8).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(index + 8));
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(index + 8));
        }
        if(row-1 >= 0)
        {
            if(b.getSquare(index + 7).getIsOccupied())
            {
                if(b.getSquare(index + 7).getPiece()->getIsWhite() != getIsWhite())
                {
                    allPossibleSquares.push_back(b.getSquare(index + 7));
                }
            }
            else
            {
                allPossibleSquares.push_back(b.getSquare(index + 7));
            }
        }
        if(row+1 <= 7)
        {
            if(b.getSquare(index + 9).getIsOccupied())
            {
                if(b.getSquare(index + 9).getPiece()->getIsWhite() != getIsWhite())
                {
                    allPossibleSquares.push_back(b.getSquare(index + 9));
                }
            }
            else
            {
                allPossibleSquares.push_back(b.getSquare(index + 9));
            }
        }
    }
    if(row-1 >= 0)
    {
        if(b.getSquare(index - 1).getIsOccupied())
        {
            if(b.getSquare(index - 1).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(index - 1));
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(index - 1));
        }
    }
    if(row+1 <= 7)
    {
        if(b.getSquare(index + 1).getIsOccupied())
        {
            if(b.getSquare(index + 1).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(index + 1));
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(index + 1));
        }
    }

    // castle
    if(getIsFirstMove())
    {
        Piece * leftRook = dynamic_cast<Rook *>(b.getSquare(index - 4).getPiece());
        Piece * rightRook = dynamic_cast<Rook *>(b.getSquare(index + 3).getPiece());
        if(leftRook != NULL)
        {
            if(leftRook->getIsFirstMove())
            {
                bool isPathClear = true;
                for(int i = index - 1; i > index - 4; --i)
                {
                    if (b.getSquare(i).getIsOccupied()) {
                        isPathClear = false;
                        break;
                    }
                }
                if(isPathClear)
                {
                    allPossibleSquares.push_back(b.getSquare(index - 4));
                }
            }
        }
        if(rightRook != NULL)
        {
            if(rightRook->getIsFirstMove())
            {
                bool isPathClear = true;
                for(int i = index + 1; i < index + 3; ++i)
                {
                    if (b.getSquare(i).getIsOccupied()) {
                        isPathClear = false;
                        break;
                    }
                }
                if(isPathClear)
                {
                    allPossibleSquares.push_back(b.getSquare(index + 3));
                }
            }
        }
    }


    return allPossibleSquares;
}
