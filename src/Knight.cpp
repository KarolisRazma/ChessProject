#include "Knight.h"

Knight::Knight(const string& name, const string& coor, bool isWhite, bool isFirstMove, SDL_Renderer * renderer) : Piece(name, coor, isWhite, isFirstMove)
{
    texture = NULL;
    setTexture(renderer);
}

Knight::~Knight()
{
    //dtor
}

vector<Square> Knight::getPossibleMoves(const Board &b)
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

void Knight::setTexture(SDL_Renderer * renderer)
{
    int index = (int(getCoordinate()[0]) - 97) + ((int(getCoordinate()[1]) - 56) * -8);

    SDL_Rect texture_rect_place;
    texture_rect_place.x = index % 8 * 100;  //the x coordinate
    texture_rect_place.y = index / 8 * 100; // the y coordinate
    texture_rect_place.w = 100; //the width of the texture
    texture_rect_place.h = 100; //the height of the texture

    SDL_Texture* mainTexture = NULL;
    SDL_Surface* temp = NULL;
    temp = SDL_LoadBMP("pieces.bmp");
    mainTexture = SDL_CreateTextureFromSurface(renderer, temp);
    SDL_FreeSurface(temp);

    SDL_Rect texture_rect_crop;
    texture_rect_crop.x = 323;  //the x coordinate
    texture_rect_crop.w = 100; //the width of the texture
    texture_rect_crop.h = 100; //the height of the texture

    if(!getIsWhite())
        texture_rect_crop.y = 113; // the y coordinate
    else
        texture_rect_crop.y = 3; // the y coordinate

    SDL_RenderCopy(renderer, mainTexture, &texture_rect_crop, &texture_rect_place);

    if(texture != NULL)
        SDL_DestroyTexture(texture);

    texture = mainTexture;
    SDL_DestroyTexture(mainTexture);
}

SDL_Texture * Knight::getTexture() const
{
    return texture;
}
