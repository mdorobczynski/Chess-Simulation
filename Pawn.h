/*
pawn.h
*/
#ifndef PAWN_h
#define PAWN_h
#include "Piece.h"
#include <string>
using namespace std;

class Pawn : public Piece //Pawn inherits from class Piece
{
	//PUBLIC MEMBERS
public:
	Pawn();		//default
	Pawn(int, int);	//constructor

	//member functions
	int getLegalMoves();
	int choices();
	int getCountLegalMoves();
	int legalMove(int, int);
};
#endif