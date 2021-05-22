#ifndef PIECE_H
#define PIECE_H

#include <string>
using std::string;

namespace Pieces
{
    class Piece
    {
        private:
            string name;
            int value;
            bool isWhite;
        public:
            Piece(string name, int value, bool isWhite);
            virtual ~Piece();
            void setName(string name);
            void setValue(int value);
            void setIsWhite(bool isWhite);
            string getName() const;
            int getValue() const;
            bool getIsWhite() const;
    };

    class Pawn : public Piece
    {
        private:
            bool isFirstMove;
        public:
            Pawn(string name, int value, bool isWhite);
            ~Pawn();
            void setIsFirstMove(bool isFirstMove);
            bool getIsFirstMove() const;
    };

    class Knight : public Piece
    {
        public:
            Knight(string name, int value, bool isWhite);
            ~Knight();
    };

    class Bishop : public Piece
    {
        public:
            Bishop(string name, int value, bool isWhite);
            ~Bishop();
    };

    class Rook : public Piece
    {
        public:
            Rook(string name, int value, bool isWhite);
            ~Rook();
    };

    class Queen : public Piece
    {
        public:
            Queen(string name, int value, bool isWhite);
            ~Queen();
    };

    class King : public Piece
    {
        public:
            King(string name, int value, bool isWhite);
            ~King();
    };
}

#endif // PIECE_H
