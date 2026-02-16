// Code author: Karolis Razma 

#ifndef PIECE_H
#define PIECE_H

// libraries
#include <string>
#include <vector>

// namespaces
using std::string;
using std::vector;

// class forward declaration
class Square;
class Board;

class Piece {
    private:
        string name;
        string coordinate;
        bool isWhite;
        bool isFirstMove;

    public:
        // default constructor
        Piece();
        // main constructor to init piece
        Piece(const string& name, const string& coor, bool isWhite, bool isFirstMove);
        virtual ~Piece();

        // sets piece name
        void setName(const string& name);
        // sets piece coordinate
        void setCoordinate(const string& coor);
        // sets piece color (1 is white, 0 is black)
        void setIsWhite(bool isWhite);
        // sets boolean for piece first move
        void setIsFirstMove(bool isFirstMove);
        
        // gets piece name
        string getName() const;
        // gets piece coordinate
        string getCoordinate() const;
        // gets piece color (1 is white, 0 is black)
        bool getIsWhite() const;
        // gets if piece is moved already or not
        bool getIsFirstMove() const;

        virtual vector<Square> getPossibleMoves(const Board &b) const = 0;
};

#endif // PIECE_H
