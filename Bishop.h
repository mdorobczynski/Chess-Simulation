/*
bishop.h
*/
#ifndef BISHOP_h
#define BISHOP_h
#include "Piece.h"
#include <string>
#include <vector>
using namespace std;

class Bishop : public Piece //Bishop inherits from class Piece
{
	//PUBLIC MEMBERS
public:
	Bishop();			//default
	Bishop(int, int);	//constructor

	//member variables
	int initialRow;
	int initialColumn;
	char nameOf;

	//member functions
	int getLegalMoves();
	int choices();
	int getCountLegalMoves();
	int legalMove(int, int);
	static const int MOVEB = 20;  //special Array for Biship
	int offsetB[MOVEB][2];
	int moveB[MOVEB];
};
#endif