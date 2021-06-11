#include "King.h"
#include "Rook.h"

King::King(const string& name, const string& coor, bool isWhite, bool isFirstMove, SDL_Renderer * renderer) : Piece(name, coor, isWhite, isFirstMove)
{
    texture = NULL;
    setTexture(renderer);
}

King::~King()
{
    //dtor
}

vector<Square> King::getPossibleMoves(const Board &b)
{

    vector<Square> allPossibleSquares;
    string coordinate = getCoordinate();
    int index = (int(coordinate[0]) - 97) + ((int(coordinate[1]) - 56) * -8);
    int col = index / 8;
    int row = index % 8;

    if(col-1 >= 0)
    {
        if(b.getSquare(index - 8).getIsOccupied())
        {
            if(b.getSquare(index - 8).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(index - 8));
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(index - 8));
        }
        if(row-1 >= 0)
        {
            if(b.getSquare(index - 9).getIsOccupied())
            {
                if(b.getSquare(index - 9).getPiece()->getIsWhite() != getIsWhite())
                {
                    allPossibleSquares.push_back(b.getSquare(index - 9));
                }
            }
            else
            {
                allPossibleSquares.push_back(b.getSquare(index - 9));
            }
        }
        if(row+1 <= 7)
        {
            if(b.getSquare(index - 7).getIsOccupied())
            {
                if(b.getSquare(index - 7).getPiece()->getIsWhite() != getIsWhite())
                {
                    allPossibleSquares.push_back(b.getSquare(index - 7));
                }
            }
            else
            {
                allPossibleSquares.push_back(b.getSquare(index - 7));
            }
        }
    }
    if(col+1 <= 7)
    {
        if(b.getSquare(index + 8).getIsOccupied())
        {
            if(b.getSquare(index + 8).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(index + 8));
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(index + 8));
        }
        if(row-1 >= 0)
        {
            if(b.getSquare(index + 7).getIsOccupied())
            {
                if(b.getSquare(index + 7).getPiece()->getIsWhite() != getIsWhite())
                {
                    allPossibleSquares.push_back(b.getSquare(index + 7));
                }
            }
            else
            {
                allPossibleSquares.push_back(b.getSquare(index + 7));
            }
        }
        if(row+1 <= 7)
        {
            if(b.getSquare(index + 9).getIsOccupied())
            {
                if(b.getSquare(index + 9).getPiece()->getIsWhite() != getIsWhite())
                {
                    allPossibleSquares.push_back(b.getSquare(index + 9));
                }
            }
            else
            {
                allPossibleSquares.push_back(b.getSquare(index + 9));
            }
        }
    }
    if(row-1 >= 0)
    {
        if(b.getSquare(index - 1).getIsOccupied())
        {
            if(b.getSquare(index - 1).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(index - 1));
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(index - 1));
        }
    }
    if(row+1 <= 7)
    {
        if(b.getSquare(index + 1).getIsOccupied())
        {
            if(b.getSquare(index + 1).getPiece()->getIsWhite() != getIsWhite())
            {
                allPossibleSquares.push_back(b.getSquare(index + 1));
            }
        }
        else
        {
            allPossibleSquares.push_back(b.getSquare(index + 1));
        }
    }

    // castle
    if(getIsFirstMove())
    {
        Piece * leftRook = dynamic_cast<Rook *>(b.getSquare(index - 4).getPiece());
        Piece * rightRook = dynamic_cast<Rook *>(b.getSquare(index + 3).getPiece());
        if(leftRook != NULL)
        {
            if(leftRook->getIsFirstMove())
            {
                bool isPathClear = true;
                for(int i = index - 1; i > index - 4; --i)
                {
                    if (b.getSquare(i).getIsOccupied()) {
                        isPathClear = false;
                        break;
                    }
                }
                if(isPathClear)
                {
                    allPossibleSquares.push_back(b.getSquare(index - 4));
                }
            }
        }
        if(rightRook != NULL)
        {
            if(rightRook->getIsFirstMove())
            {
                bool isPathClear = true;
                for(int i = index + 1; i < index + 3; ++i)
                {
                    if (b.getSquare(i).getIsOccupied()) {
                        isPathClear = false;
                        break;
                    }
                }
                if(isPathClear)
                {
                    allPossibleSquares.push_back(b.getSquare(index + 3));
                }
            }
        }
    }


    return allPossibleSquares;
}

void King::setTexture(SDL_Renderer * renderer)
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
    texture_rect_crop.x = 5;  //the x coordinate
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

SDL_Texture * King::getTexture() const
{
    return texture;
}
