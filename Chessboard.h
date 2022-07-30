/*
chessboard.h
*/
#ifndef Chessboard_h
#define Chessboard_h
#include "Piece.h"
#include <string>

//Board class
class Chessboard
{
	//PUBLIC MEMBERS
public:
	Chessboard();	//default constructor
	~Chessboard();	//destructor

	//member variables
	char board[8][8]; //official game board

	//member function
	void printBoard();
	bool updateBoard(int x, int y, char);
	bool isOccupied(int x, int y);

	//PRIVATE MEMBERS
private:
	int row;
	int col;
};
#endif /* Chessboard_h */