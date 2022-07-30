/*
Piece.h
*/
#ifndef PIECE_h
#define PIECE_h
#include <string>
using namespace std;

class Piece
{
    //PUBLIC MEMBERS
public:
    Piece();     //constructor

    //member variables
    int initialRow;
    int initialColumn;
    char nameOf;

    //member functions
    int legalMove(int x, int y);
    int getLegalMoves();                //retrieves the legal moves
    void setLegalMovesCount(int x);     //sets the legal move count
    void Movement(int iRow, int iCol);

    //member variables
    static const int iROW = 8;  //initalizes board width
    static const int iCOL = 8;  //initalizes board height
    int iRow;
    int iCol;
    int legalMovesCount;
    int board[iROW][iCOL];  //the playing board
    int countLegalMoves;

    static const int MOVES = 8;  //initalizes possible moves
    int offsets[MOVES][2]; //array for offset values
    int moves[MOVES];      //record legal moves
};
#endif