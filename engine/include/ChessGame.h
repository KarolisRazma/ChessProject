// Code author: Karolis Razma 
// Main chess game header 

#ifndef CHESSGAME_H
#define CHESSGAME_H

// libraries
#include "Board.h"
#include "Player.h"

class ChessGame
{
    private:
        Board chessBoard;
        Player whitePlayer;
        Player blackPlayer;
        bool turn;
        bool quit;
        
    public:
        // default constructor creates board and players
        ChessGame();
        ~ChessGame();

        // main game loop
        void play();
   
    private:
      
        // sets current turn to 0 or 1 (0 means 'Black', 1 means 'White')
        void setCurrentTurn(bool turn);
        // gets current turn (0 means 'Black', 1 means 'White')
        bool getCurrentTurn() const;
        // checks if both piece and its destination is selected correctly
        bool isMoveSelected();
        // get chess board
        Board getBoard() const;
        // get white or black player by passing 0 for black, 1 for white
        Player getPlayer(bool isWhite) const;
};

#endif // CHESSGAME_H
