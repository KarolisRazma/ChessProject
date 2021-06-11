// Code author: Karolis Razma 
// Main chess game header 

#ifndef CHESSGAME_H
#define CHESSGAME_H

// libraries
#include "Board.h"
#include "Player.h"
#include <SDL.h>

class ChessGame
{
    private:
        Board chessBoard;
        Player whitePlayer;
        Player blackPlayer;
        bool turn;

        SDL_Window * window;
        SDL_Renderer * renderer;
        bool quit;
        vector<Square> markedSquares;
        
    public:
        // default constructor creates board and players
        ChessGame();
        ~ChessGame();

        // main game loop
        void play();
   
    private:
        // to handle left mouse input (basically to select piece)
        void controlMouseInputDownLeft(SDL_MouseButtonEvent& down);
        // to handle right mouse input (basically to select destination square)
        void controlMouseInputDownRight(SDL_MouseButtonEvent& down);
        // init SDL Window and Renderer, creates Board
        void initWindowAndRenderer();
        // to handle all events
        void handleEvents();
        // to destroy SDL Window and Renderer
        void destroyWindowAndRenderer();
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
        // clears marked squares which represents legal moves of that selected piece
        void clearMarkedSquares();
};

#endif // CHESSGAME_H
