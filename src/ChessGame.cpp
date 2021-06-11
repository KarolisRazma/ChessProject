#include "ChessGame.h"
#include <string>

ChessGame::ChessGame()
{
    initWindowAndRenderer();
    whitePlayer.setIsWhite(true);
    blackPlayer.setIsWhite(false);
    setCurrentTurn(1);
}

ChessGame::~ChessGame()
{
    
}

void ChessGame::play()
{
    bool exit = false;
    SDL_RenderPresent(renderer);
    while (1)
    {
        if (chessBoard.isEndgame())
            break;

        do
        {
            while (!isMoveSelected())
            {
                handleEvents();
                if (quit)
                {
                    exit = true;
                    break;
                }
            }
            if (exit)
                break;
        }
        while (!whitePlayer.makeMove(chessBoard, renderer));
        if (exit)
            break;

        SDL_RenderPresent(renderer);
        setCurrentTurn(0);

        if (chessBoard.isEndgame())
            break;

        do
        {
            while (!isMoveSelected())
            {
                handleEvents();
                if (quit)
                {
                    exit = true;
                    break;
                }
            }
            if (exit)
                break;
        }
        while (!blackPlayer.makeMove(chessBoard, renderer));
        if (exit)
            break;

        SDL_RenderPresent(renderer);
        setCurrentTurn(1);
    }
    chessBoard.destroyTextures();
    destroyWindowAndRenderer();
}

void ChessGame::controlMouseInputDownLeft(SDL_MouseButtonEvent& down)
{
    clearMarkedSquares();
    string start = "a1";
    start[0] = 97 + down.x / 100;
    start[1] = 49 + abs(down.y / 100 - 7);

    if (getCurrentTurn())
    {
        whitePlayer.setStart(start);
        int index = (int(start[0]) - 97) + ((int(start[1]) - 56) * -8);
        Square temp = chessBoard.getSquare(index);

        markedSquares = chessBoard.renderDangerZones(1, temp, renderer);
    }
    else
    {
        blackPlayer.setStart(start);
        int index = (int(start[0]) - 97) + ((int(start[1]) - 56) * -8);
        Square temp = chessBoard.getSquare(index);

        markedSquares = chessBoard.renderDangerZones(0, temp, renderer);
    }
    SDL_RenderPresent(renderer);
}

void ChessGame::controlMouseInputDownRight(SDL_MouseButtonEvent& down)
{
    string dest = "a1";
    dest[0] = 97 + down.x / 100;
    dest[1] = 49 + abs(down.y / 100 - 7);

    if (getCurrentTurn())
    {
        whitePlayer.setDestination(dest);
    }
    else
    {
        blackPlayer.setDestination(dest);
    }
    clearMarkedSquares();
    markedSquares.clear();
}

void ChessGame::initWindowAndRenderer()
{
    quit = false;
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Chess game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    chessBoard.create(renderer);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}

void ChessGame::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        quit = true;
        break;
    case SDL_MOUSEBUTTONDOWN:
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            controlMouseInputDownLeft(event.button);
        }
        else if (event.button.button == SDL_BUTTON_RIGHT)
        {
            controlMouseInputDownRight(event.button);
        }
        break;
    }
}

void ChessGame::destroyWindowAndRenderer()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
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

void ChessGame::clearMarkedSquares()
{
    for (int i = 0; i < int(markedSquares.size()); ++i)
    {
        markedSquares[i].setSquareColor(renderer);
        if (markedSquares[i].getPiece())
        {
            markedSquares[i].getPiece()->deleteTexture();
            markedSquares[i].getPiece()->setTexture(renderer);
        }
    }
}