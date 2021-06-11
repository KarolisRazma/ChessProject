#include "Player.h"

Player::Player()
{
    start = "";
    destination = "";
}

Player::~Player()
{
    //dtor
}

void Player::setStart(const string& start)
{
    this->start = start;
}

void Player::setDestination(const string& dest)
{
    this->destination = dest;
}

string Player::getStart() const
{
    return start;
}

string Player::getDestination() const
{
    return destination;
}

void Player::setIsWhite(bool isWhite)
{
    this->isWhite = isWhite;
}

bool Player::getIsWhite() const
{
    return isWhite;
}

bool Player::makeMove(Board &currentState, SDL_Renderer * renderer)
{
    
    int startIndex;
    int finishIndex;
    vector<Square> possibleMoves;

    // getting starting square and piece
    Square selectedSquare;
    Piece * selectedPiece;

    startIndex = (int(start[0]) - 97) + ((int(start[1]) - 56) * -8);
    selectedSquare = currentState.getSquare(startIndex);
    selectedPiece = selectedSquare.getPiece();
    // checking if that selected piece is in player team and has at least one possible move
    if(selectedPiece != NULL && selectedPiece->getIsWhite() == getIsWhite())
    {
        // calculating possible moves
        possibleMoves = selectedPiece->getPossibleMoves(currentState);
        // filtering possible moves into legal moves
        possibleMoves = currentState.findLegalMoves(possibleMoves, getIsWhite(), selectedSquare);
        
        if(int(possibleMoves.size()) == 0)
        {
            setStart("");
            setDestination("");
            return false;
        }
    }
    else
    {
        setStart("");
        setDestination("");
        return false;
    }
    
    // preparing variables to store destination square/piece
    Square destinationSquare;

    finishIndex = (int(destination[0]) - 97) + ((int(destination[1]) - 56) * -8);
    // getting destination square
    destinationSquare = currentState.getSquare(finishIndex);

    bool moveAvailable = false;
    for(int i = 0; i < int(possibleMoves.size()); ++i)
    {
        if(destinationSquare.getCoordinate() == possibleMoves[i].getCoordinate())
        {
            moveAvailable = true;
            break;
        }
    }

    setStart("");
    setDestination("");
    if(moveAvailable)
    {
        currentState.movePiece(selectedSquare, destinationSquare, getIsWhite(), renderer);
        return true;
    }
    else
    {
        return false;
    }
}
