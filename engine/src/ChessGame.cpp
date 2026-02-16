#include "ChessGame.h"
#include <string>

/* TODO:
*  1. Init chessBoard
*  2. Temporary break before play loop.
*  3. Print/log that chess engine successfully started.
*/


ChessGame::ChessGame()
{
    chessBoard.create();
    whitePlayer.setIsWhite(true);
    blackPlayer.setIsWhite(false);
    setCurrentTurn(1);
}

ChessGame::~ChessGame()
{
    
}


void ChessGame::play()
{
    // bool exit = false;
    
    // while (1)
    // {
    //     if (chessBoard.isEndgame())
    //         break;

    //     do
    //     {
    //         while (!isMoveSelected())
    //         {
    //             if (quit)
    //             {
    //                 exit = true;
    //                 break;
    //             }
    //         }
    //         if (exit)
    //             break;
    //     }
    //     while (!whitePlayer.makeMove(chessBoard));
    //     if (exit)
    //         break;

    //     setCurrentTurn(0);

    //     if (chessBoard.isEndgame())
    //         break;

    //     do
    //     {
    //         while (!isMoveSelected())
    //         {
    //             if (quit)
    //             {
    //                 exit = true;
    //                 break;
    //             }
    //         }
    //         if (exit)
    //             break;
    //     }
    //     while (!blackPlayer.makeMove(chessBoard));
    //     if (exit)
    //         break;

    //     setCurrentTurn(1);
    // }
}

void ChessGame::setCurrentTurn(bool turn)
{
    this->turn = turn;
}

bool ChessGame::getCurrentTurn() const
{
    return turn;
}

bool ChessGame::isMoveSelected()
{
    if (getCurrentTurn())
    {
        if (whitePlayer.getStart() != "" && whitePlayer.getDestination() != "")
            return true;
        else
            return false;
    }
    else
    {
        if (blackPlayer.getStart() != "" && blackPlayer.getDestination() != "")
            return true;
        else
            return false;
    }
}

Board ChessGame::getBoard() const
{
    return chessBoard;
}

Player ChessGame::getPlayer(bool isWhite) const
{
    if(isWhite)
    {
        return whitePlayer;
    }
    else
    {
        return blackPlayer;
    }
}
