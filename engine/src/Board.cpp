#include "Board.h"

// extra libraries
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

// namespaces
using std::string;
using std::vector;

Board::Board()
{

}

Board::~Board()
{

}

void Board::create()
{
    int squaresCreated = 0;
    string coordinate = "aa";
    int col = 0;
    int row = 0;
    for(int i = 7; i >= 0; --i)
    {
        coordinate[1] = 49 + i;
        for(int j = 0; j < 8; ++j)
        {
            coordinate[0] = 97 + j;
            Square square(coordinate);
            if(squaresCreated >= 8 && squaresCreated <= 15)
            {
                Piece *pawn = new Pawn("p", coordinate, false, true);
                square.setPiece(pawn);
            }
            if(squaresCreated == 0 || squaresCreated == 7)
            {
                Piece *rook = new Rook("r", coordinate, false, true);
                square.setPiece(rook);
            }
            if(squaresCreated == 1 || squaresCreated == 6)
            {
                Piece *knight = new Knight("n", coordinate, false, true);
                square.setPiece(knight);
            }
            if(squaresCreated == 2 || squaresCreated == 5)
            {
                Piece *bishop = new Bishop("b", coordinate, false, true);
                square.setPiece(bishop);
            }
            if(squaresCreated == 3)
            {
                Piece *queen = new Queen("q", coordinate, false, true);
                square.setPiece(queen);
            }
            if(squaresCreated == 4)
            {
                Piece *king = new King("k", coordinate, false, true);
                setBlackKingLocation(coordinate);
                square.setPiece(king);
            }
            if(squaresCreated >= 48 && squaresCreated <= 55)
            {
                Piece *pawn = new Pawn("P", coordinate, true, true);
                square.setPiece(pawn);
            }
            if(squaresCreated == 56 || squaresCreated == 63)
            {
                Piece *rook = new Rook("R", coordinate, true, true);
                square.setPiece(rook);
            }
            if(squaresCreated == 57 || squaresCreated == 62)
            {
                Piece *knight = new Knight("N", coordinate, true, true);
                square.setPiece(knight);
            }
            if(squaresCreated == 58 || squaresCreated == 61)
            {
                Piece *bishop = new Bishop("B", coordinate, true, true);
                square.setPiece(bishop);
            }
            if(squaresCreated == 59)
            {
                Piece *queen = new Queen("Q", coordinate, true, true);
                square.setPiece(queen);
            }
            if(squaresCreated == 60)
            {
                Piece *king = new King("K", coordinate, true, true);
                setWhiteKingLocation(coordinate);
                square.setPiece(king);
            }
            squares[col][row] = square;
            ++row;
            ++squaresCreated;
        }
        ++col;
        row = 0;
    }
}

void Board::destroy()
{
    for(int i = 0; i < BOARD_SIZE; ++i)
    {
        for(int j = 0; j < BOARD_SIZE; ++j)
        {
            if(squares[i][j].getIsOccupied())
                squares[i][j].destroyPiece();
        }
    }
}

void Board::movePiece(Square startSquare, Square destSquare, bool isWhite)
{
    string startCoordinate = startSquare.getCoordinate();
    string finishCoordinate = destSquare.getCoordinate();
    int startIndex = (int(startCoordinate[0]) - 97) + ((int(startCoordinate[1]) - 56) * -8);
    int finishIndex = (int(finishCoordinate[0]) - 97) + ((int(finishCoordinate[1]) - 56) * -8);
    Piece * startPiece = startSquare.getPiece();

    // special moves (for castle)
    if(destSquare.getIsOccupied() && destSquare.getPiece()->getIsWhite() == isWhite)
    {
        Piece * destinationPiece = destSquare.getPiece();
        // if castle happens
        if(destinationPiece->getIsWhite() == isWhite)
        {

            startPiece->setIsFirstMove(false);
            destSquare.getPiece()->setIsFirstMove(false);


            // kingside
            if(finishCoordinate == "h1" || finishCoordinate == "h8")
            {
                Square kingSquare = getSquare(startIndex + 2);
                Square rookSquare = getSquare(finishIndex - 2);

                if(isWhite)
                    setWhiteKingLocation(kingSquare.getCoordinate());
                else
                    setBlackKingLocation(kingSquare.getCoordinate());

                startPiece->setCoordinate(kingSquare.getCoordinate());
                destinationPiece->setCoordinate(rookSquare.getCoordinate());
                kingSquare.setPiece(startPiece);
                rookSquare.setPiece(destinationPiece);
                setSquare(kingSquare, startIndex + 2);
                setSquare(rookSquare, finishIndex - 2);
            }
            // queenside
            if(finishCoordinate == "a1" || finishCoordinate == "a8")
            {
                Square kingSquare = getSquare(startIndex - 2);
                Square rookSquare = getSquare(finishIndex + 3);

                if (isWhite)
                    setWhiteKingLocation(kingSquare.getCoordinate());
                else
                    setBlackKingLocation(kingSquare.getCoordinate());

                startPiece->setCoordinate(kingSquare.getCoordinate());
                destinationPiece->setCoordinate(rookSquare.getCoordinate());
                kingSquare.setPiece(startPiece);
                rookSquare.setPiece(destinationPiece);
                setSquare(kingSquare, startIndex - 2);
                setSquare(rookSquare, finishIndex + 3);
            }

            destSquare.setPiece(NULL);
            startSquare.setPiece(NULL);
            setSquare(startSquare, startIndex);
            setSquare(destSquare, finishIndex);
        }
    }
    // if destination square is empty or has enemy piece
    else
    {
        int finishCol = finishIndex / 8;

        // promotion
        if(dynamic_cast<Pawn*>(startPiece) != NULL && (finishCol == 0 || finishCol == 7))
        {
            if(isWhite)
            {
                delete startPiece;
                startPiece = new Queen("Q", finishCoordinate, true, false);
            }
            else
            {
                delete startPiece;
                startPiece = new Queen("q", finishCoordinate, false, false);
            }
        }
        
        startPiece->setCoordinate(finishCoordinate);

        if(startPiece != NULL)
            if (startPiece->getIsFirstMove()) {
                {
                    startPiece->setIsFirstMove(false);
                }
            }

        if(dynamic_cast<King*>(startPiece) != NULL)
        {
            if(isWhite)
                setWhiteKingLocation(finishCoordinate);
            else
                setBlackKingLocation(finishCoordinate);
        }

        destSquare.setPiece(startPiece);
        startSquare.setPiece(NULL);
        setSquare(startSquare, startIndex);
        setSquare(destSquare, finishIndex);
    }
}

vector<Square> Board::findLegalMoves(vector<Square>& possibleMoves, bool isWhite, Square startSquare)
{
    int amountOfPossibleMoves = possibleMoves.size();
    vector<Piece*> enemyPieces;
    Square kingSquare;
    bool isAttackable;
    bool canCastle = true;
    vector<Square> legalMoves;

    if(isWhite)
    {
        kingSquare = getWhiteKingSquare();
    }
    else
    {
        kingSquare = getBlackKingSquare();
    }

    for(int i = -1; i < amountOfPossibleMoves; ++i)
    {
        Board tempBoard = *this;
        isAttackable = false;
        if(i != -1)
        {
            tempBoard.movePiece(startSquare, possibleMoves[i], isWhite);
            if(isWhite)
            {
                kingSquare = tempBoard.getWhiteKingSquare();
            }
            else
            {
                kingSquare = tempBoard.getBlackKingSquare();
            }
        }
        enemyPieces = tempBoard.getPieces(!isWhite);

        isAttackable = tempBoard.isChecked(enemyPieces, tempBoard, kingSquare);

        if(i == -1)
        {
            if(isAttackable)
            {
                canCastle = false;
            }
            continue;
        }
        // checks if selected piece is king, and if king is not in check
        if (dynamic_cast<King*>(startSquare.getPiece()) && canCastle && i != -1 && (kingSquare.getCoordinate() == "e1" || kingSquare.getCoordinate() == "e8"))
        {
            if (possibleMoves[i].getCoordinate() == "a1" || possibleMoves[i].getCoordinate() == "a8" || possibleMoves[i].getCoordinate() == "h1" || possibleMoves[i].getCoordinate() == "h8")
            {
                if (isItLegalToCastle(startSquare, possibleMoves[i], tempBoard))
                {
                    legalMoves.push_back(possibleMoves[i]);
                    continue;
                }
                else
                {
                    continue;
                }
            }
        }

        if(!isAttackable)
        {
            legalMoves.push_back(possibleMoves[i]);
        }
    }
    return legalMoves;
}

void Board::setWhiteKingLocation(const string& location)
{
    whiteKingLocation = location;
}

void Board::setBlackKingLocation(const string& location)
{
    blackKingLocation = location;
}

string Board::getWhiteKingLocation() const
{
    return whiteKingLocation;
}

string Board::getBlackKingLocation() const
{
    return blackKingLocation;
}

Square Board::getWhiteKingSquare() const
{
    string kingCoordinate = getWhiteKingLocation();
    int kingIndex = (int(kingCoordinate[0]) - 97) + ((int(kingCoordinate[1]) - 56) * -8);
    return getSquare(kingIndex);;
}

Square Board::getBlackKingSquare() const
{
    string kingCoordinate = getBlackKingLocation();
    int kingIndex = (int(kingCoordinate[0]) - 97) + ((int(kingCoordinate[1]) - 56) * -8);
    return getSquare(kingIndex);
}

vector<Piece*> Board::getPieces(bool isWhite) const
{
    vector<Piece*> pieces;
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            if(squares[i][j].getPiece() != NULL)
            {
                if(squares[i][j].getPiece()->getIsWhite() == isWhite)
                {
                    pieces.push_back(squares[i][j].getPiece());
                }
            }
        }
    }
    return pieces;
}

void Board::setSquare(const Square& square, int index)
{
    squares[index / 8][index % 8] = square;
}

Square Board::getSquare(int index) const
{
    if (index >= BOARD_SIZE * BOARD_SIZE || index < 0)
        throw;
    return squares[index / 8][index % 8];
}

bool Board::isEndgame()
{
    if (isChecked(getPieces(0), *this, getWhiteKingSquare()))
    {
        if (isCheckmate(getPieces(1), getWhiteKingSquare()))
        {
            return true;
        }
    }
    if (isChecked(getPieces(1), *this, getBlackKingSquare()))
    {
        if (isCheckmate(getPieces(0), getBlackKingSquare()))
        {
            return true;
        }
    }
    if (isDraw())
    {
        return true;
    }
    if (isStalemate(getPieces(1), getBlackKingSquare()))
    {
        return true;
    }
    if (isStalemate(getPieces(0), getWhiteKingSquare()))
    {
        return true;
    }

    return false;
}

bool Board::isChecked(vector<Piece*> enemyPieces, const Board& tempBoard, Square kingSquare)
{
    for (int j = 0; j < int(enemyPieces.size()); ++j)
    {
        vector<Square> enemyMoves = enemyPieces[j]->getPossibleMoves(tempBoard);
        for (int k = 0; k < int(enemyMoves.size()); ++k)
        {
            if (kingSquare.getCoordinate() == enemyMoves[k].getCoordinate())
            {
                return true;
            }
        }
    }
    return false;
}

bool Board::isCheckmate(vector<Piece*> myPieces, Square kingSquare)
{
    vector<Square> possibleMoves;
    for(int i = 0; i < int(myPieces.size()); ++i)
    {
        possibleMoves = myPieces[i]->getPossibleMoves(*this);
        string myPieceCoor = myPieces[i]->getCoordinate();
        int mySquareIndex = (int(myPieceCoor[0]) - 97) + ((int(myPieceCoor[1]) - 56) * -8);
        Square mySquare = getSquare(mySquareIndex);
        possibleMoves = findLegalMoves(possibleMoves, kingSquare.getPiece()->getIsWhite(), mySquare);
        if(int(possibleMoves.size()) > 0)
        {
            return false;
        }
    }
    return true;
}

bool Board::isDraw()
{
    vector<Piece*> whitePieces = getPieces(1);
    vector<Piece*> blackPieces = getPieces(0);

    if (int(whitePieces.size()) == 1 && int(blackPieces.size()) == 1)
    {
        if (dynamic_cast<King*>(whitePieces[0]) && dynamic_cast<King*>(blackPieces[0]))
        {
            return true;
        }
    }
    return false;
}

bool Board::isStalemate(vector<Piece*> enemyPieces, Square kingSquare)
{
    bool isWhite = kingSquare.getPiece()->getIsWhite();
    if (!isChecked(getPieces(!isWhite), *this, kingSquare))
    {
        // if no moves left, but no check
        if (isCheckmate(getPieces(isWhite), kingSquare))
        {
            return true;
        }
    }
    return false;
}

bool Board::isItLegalToCastle(Square startSquare, Square finishSquare, Board& tempBoard)
{
    bool isWhite = startSquare.getPiece()->getIsWhite();
    Board temp = tempBoard;
    string startCoor = startSquare.getCoordinate();
    string finishCoor = finishSquare.getCoordinate();
    int startIndex = (int(startCoor[0]) - 97) + ((int(startCoor[1]) - 56) * -8);
    int finishIndex = (int(finishCoor[0]) - 97) + ((int(finishCoor[1]) - 56) * -8);

    if (startIndex < finishIndex) {
        for (int i = startIndex; i < finishIndex-1; ++i)
        {
            temp.movePiece(temp.getSquare(i), temp.getSquare(i + 1), isWhite);
            if (isChecked(temp.getPieces(!isWhite), temp, temp.getSquare(i + 1))) 
            {
                return false;
            }
        }
    }
    else
    {
        for (int i = startIndex; i > finishIndex+1; --i)
        {
            temp.movePiece(temp.getSquare(i), temp.getSquare(i - 1), isWhite);
            if (isChecked(temp.getPieces(!isWhite), temp, temp.getSquare(i - 1))) 
            {
                return false;
            }
        }
    }
    return true;
}

