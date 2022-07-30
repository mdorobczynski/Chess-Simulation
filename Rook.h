/*
rook.h
*/
#ifndef ROOK_h
#define ROOK_h
#include "Piece.h"
#include <string>
using namespace std;

class Rook : public Piece //Rook inherits from class Piece
{
	//PUBLIC MEMBERS
public:
	Rook();			//default
	Rook(int, int);	//constructor

	//member functions
	int getLegalMoves();
	int choices();
	int getCountLegalMoves();
	int legalMove(int, int);
	static const int MOVER = 23;  //special Array for Biship
	int offsetR[MOVER][2];
	int moveR[MOVER];
};
#endif