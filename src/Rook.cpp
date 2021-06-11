#include "Rook.h"

Rook::Rook(const string& name, const string& coor, bool isWhite, bool isFirstMove, SDL_Renderer * renderer) : Piece(name, coor, isWhite, isFirstMove)
{
    texture = NULL;
    setTexture(renderer);
}

Rook::~Rook()
{
    //dtor
}

vector<Square> Rook::getPossibleMoves(const Board &b)
{
    vector<Square> allPossibleSquares;
    string coordinate = getCoordinate();
    int index = (int(coordinate[0]) - 97) + ((int(coordinate[1]) - 56) * -8);

    int tempIndex = index;
    while(tempIndex + 8 < 63)
    {
        tempIndex += 8;
        if((b.getSquare(tempIndex)).getIsOccupied() == false)
            allPossibleSquares.push_back(b.getSquare(tempIndex));
        else
        {
            if(((b.getSquare(tempIndex)).getPiece())->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(tempIndex));
                break;
            }
            else
                break;
        }
    }
    tempIndex = index;
    while(tempIndex - 8 > 0)
    {
        tempIndex -= 8;
        if((b.getSquare(tempIndex)).getIsOccupied() == false)
            allPossibleSquares.push_back(b.getSquare(tempIndex));
        else
        {
            if(((b.getSquare(tempIndex)).getPiece())->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(tempIndex));
                break;
            }
            else
                break;
        }
    }

    int leftHorizontalSquares = index % 8;
    int rightHorizontalSquares = 7 - leftHorizontalSquares;
    for(int i = index-1; i > index-leftHorizontalSquares-1; --i)
    {
        if((b.getSquare(i)).getIsOccupied() == false)
            allPossibleSquares.push_back(b.getSquare(i));
        else
        {
            if(((b.getSquare(i)).getPiece())->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(i));
                break;
            }
            else
                break;
        }
    }
    for(int i = index+1; i < index+rightHorizontalSquares+1; ++i)
    {
        if((b.getSquare(i)).getIsOccupied() == false)
            allPossibleSquares.push_back(b.getSquare(i));
        else
        {
            if(((b.getSquare(i)).getPiece())->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(i));
                break;
            }
            else
                break;
        }
    }

    return allPossibleSquares;
}

void Rook::setTexture(SDL_Renderer * renderer)
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
    texture_rect_crop.x = 433;  //the x coordinate
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

SDL_Texture * Rook::getTexture() const
{
    return texture;
}
