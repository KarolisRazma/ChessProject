#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Square.h"

namespace GameBoard
{
    class Board
    {
        private:
            std::vector<Square> squares;

        public:
            Board();
            ~Board();

            void display();
            void create();
            void destroy();
            void setSquare(Square square, int index);
            Square getSquare(int index) const;
    };
}

#endif // BOARD_H
