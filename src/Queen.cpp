#include "Queen.h"

Queen::Queen(const string& name, const string& coor, bool isWhite, bool isFirstMove, SDL_Renderer * renderer) : Piece(name, coor, isWhite, isFirstMove)
{
    texture = NULL;
    setTexture(renderer);
}

Queen::~Queen()
{
    //dtor
}

vector<Square> Queen::getPossibleMoves(const Board &b)
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

void Queen::setTexture(SDL_Renderer * renderer)
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
    texture_rect_crop.x = 110;  //the x coordinate
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

SDL_Texture * Queen::getTexture() const
{
    return texture;
}
