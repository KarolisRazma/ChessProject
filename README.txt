2D Chess Game made by VU MIF student Karolis Razma (2021)

--- Instructions ---

Game does not require any installations. In order to play just open ChessGame.exe. If the game turns off randomly, try to turn off antivirus software for game session.

How to play:

1) To select piece click on it with the left mouse button
2) To place piece on a square press the right mouse button

Possible endgames:

1) Black king is checkmated: White won
2) White king is checkmated: Black won
3) Black king is stalemated: draw
4) White king is stalemated: draw
5) Draw: only white and black kings left on the board

What is different from regular chess game:

My chess game doesn't have a special move called "En passant". 
This move can only be done with pawn and it requires special conditions.
En passant is a rare move, so this "feature" won't unbalance the game much.
Probably, it will be added later.

Possible bugs:

Incorrect piece selection (if player selects wrong squares/pieces many times) can cause a bug:
1) Piece disappears from the board, but it appears again after player makes a move with it. (it occurs rarely)
Recommendation: don't spam mouse buttons randomly.

To compile chess game yourself:

- Download and install SDL library: https://www.libsdl.org/download-2.0.php
- Make a project in codeblocks or visual studio
- Take out all .cpp and .h files from src folder and copy pieces.bmp
- Place them in our project folder (they must be in same folder!(.cpp/.h/.bmp files))

