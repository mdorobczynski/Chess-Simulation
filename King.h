/*
king.h
*/
#ifndef KING_h
#define KING_h
#include "Piece.h"
#include <string>
using namespace std;

class King : public Piece //King inherits from class Piece
{
	//PUBLIC MEMBERS
public:
	King(int, int);	//constructor

	//member functions
	int getLegalMoves();
	int choices();
	int getCountLegalMoves();
	int legalMove(int, int);
};
#endif