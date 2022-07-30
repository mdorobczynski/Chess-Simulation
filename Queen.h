/*
queen.h
*/
#ifndef QUEEN_h
#define QUEEN_h
#include "Piece.h"
#include <string>
using namespace std;

class Queen : public Piece //Queen inherits from class Piece
{
	//PUBLIC MEMBERS
public:
	Queen(int, int);	//constructor

	//member functions
	int getLegalMoves();
	int choices();
	int getCountLegalMoves();
	int legalMove(int, int);
	static const int MOVEQ = 45;  //special Array for Biship
	int offsetQ[MOVEQ][2];
	int moveQ[MOVEQ];
};
#endif