/*
knight.h
*/
#ifndef KNIGHT_h
#define KNIGHT_h
#include "Piece.h"
#include <string>
using namespace std;

class Knight : public Piece //Knight inherits from class Piece
{
	//PUBLIC MEMBERS
public:
	Knight();			//default
	Knight(int, int);	//constructor

	//member functions
	int getLegalMoves();
	int choices();
	int getCountLegalMoves();
	int legalMove(int, int);
};
#endif