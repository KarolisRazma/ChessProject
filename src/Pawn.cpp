#include "Pawn.h"

Pawn::Pawn(const string& name, const string& coor, bool isWhite, bool isFirstMove, SDL_Renderer * renderer) : Piece(name, coor, isWhite, isFirstMove)
{
    texture = NULL;
    setTexture(renderer);
}

Pawn::~Pawn()
{
    //dtor
}

vector<Square> Pawn::getPossibleMoves(const Board &b)
{
    vector<Square> allPossibleSquares;
    string coordinate = getCoordinate();
    int index = (int(coordinate[0]) - 97) + ((int(coordinate[1]) - 56) * -8);
    int col = index / 8;

    if(index - 8 < 0 || index + 8 > 63)
        return allPossibleSquares;
    if(getIsWhite() == false)
    {
        if((b.getSquare(index + 8)).getIsOccupied() == false)
            allPossibleSquares.push_back(b.getSquare(index + 8));
    }
    else
    {
        if((b.getSquare(index - 8)).getIsOccupied() == false)
            allPossibleSquares.push_back(b.getSquare(index - 8));
    }

    if(col == 1 && !getIsWhite())
    {
        if ((b.getSquare(index + 16)).getIsOccupied() == false) {
            if ((b.getSquare(index + 8)).getIsOccupied() == false)
                allPossibleSquares.push_back(b.getSquare(index + 16));
        }
    }
    else if(col == 6 && getIsWhite())
    {
        if ((b.getSquare(index - 16)).getIsOccupied() == false) {
            if ((b.getSquare(index - 8)).getIsOccupied() == false)
                allPossibleSquares.push_back(b.getSquare(index - 16));
        }
    }

    if(getIsWhite() == false)
    {
        if(coordinate[0] != 'h')
        {
            if((b.getSquare(index + 9)).getIsOccupied() == true)
            {
                if(((b.getSquare(index + 9)).getPiece())->getIsWhite() == true)
                    allPossibleSquares.push_back(b.getSquare(index + 9));
            }
        }
        if(coordinate[0] != 'a')
        {
            if((b.getSquare(index + 7)).getIsOccupied() == true)
            {
                if(((b.getSquare(index + 7)).getPiece())->getIsWhite() == true)
                    allPossibleSquares.push_back(b.getSquare(index + 7));
            }
        }

    }
    else
    {
        if(coordinate[0] != 'h')
        {
            if((b.getSquare(index - 7)).getIsOccupied() == true)
            {
                if(((b.getSquare(index - 7)).getPiece())->getIsWhite() == false)
                    allPossibleSquares.push_back(b.getSquare(index - 7));
            }
        }
        if(coordinate[0] != 'a')
        {
            if((b.getSquare(index - 9)).getIsOccupied() == true)
            {
                if(((b.getSquare(index - 9)).getPiece())->getIsWhite() == false)
                    allPossibleSquares.push_back(b.getSquare(index - 9));
            }
        }
    }

    return allPossibleSquares;
}

void Pawn::setTexture(SDL_Renderer * renderer)
{
    string coor = getCoordinate();
    int index = (int(coor[0]) - 97) + ((int(coor[1]) - 56) * -8);

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
    texture_rect_crop.x = 535;  //the x coordinate
    texture_rect_crop.w = 100; //the width of the texture
    texture_rect_crop.h = 100; //the height of the texture

    if(!getIsWhite())
        texture_rect_crop.y = 113; // the y coordinate
    else
        texture_rect_crop.y = 3; // the y coordinate

    SDL_RenderCopy(renderer, mainTexture, &texture_rect_crop, &texture_rect_place);

    if (texture != NULL)
        SDL_DestroyTexture(texture);

    texture = mainTexture;
    SDL_DestroyTexture(mainTexture);
}

SDL_Texture * Pawn::getTexture() const
{
    return texture;
}
