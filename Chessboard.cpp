/*
chessboard.CPP
*/
#include "Chessboard.h"       //include header file
#include "Piece.h"
#include <iostream>
#include <string>
using namespace std;

//*******************************************************
//                    The constructor                   *                                                   
//*******************************************************
Chessboard::Chessboard()
{
    //default access to char board[][]
    row = 8; //hard coded for this Chessboard object
    col = 8;

    for (int i = 0; i < row; i++)
        //outer for loop, populates the rows
        //"i" initalized to zero
        //loop will execute as long as "i" is less than variable row
        //then "i" increments by 1
    {
        for (int j = 0; j < col; j++)
            //inner for loop, populates the columns
            //"i" initalized to zero
            //loop will execute as long as "i" is less than variable row
            //then "i" increments by 1
        {
            board[i][j] = '.';
            //By default before being replaced by specific ships,
            //     each spot on the Chessboard is represented by a dot
        }
    }
}
//*******************************************************
//                    The destructor                    *                                                   
//*******************************************************
Chessboard::~Chessboard()
{
}
/**
 *      Displays a 10x10 box of characters illustrating a Chessboard
 *
 *      @param array type char, row variable type int and col variable type int
 *      @ return void
 */

 //********************************************************************************
 //  printBoard populates and outputs each row and column of the Chessboard       *                                                   
 //********************************************************************************
void Chessboard::printBoard()
{
    for (int i = 0; i < row; i++)
        //outer for loop, populates the rows
        //"i" initalized to zero
        //loop will execute as long as "i" is less than variable row
        //then "i" increments by 1
    {
        for (int j = 0; j < col; j++)
            //inner loop, populates the columns
            //"i" initalized to zero
            //loop will execute as long as "i" is less than variable col
            //then "i" increments by 1
        {
            cout << board[i][j] << "  ";
            //displays a space inbetween the rows & columns
            //simply for aesthics
        }
        cout << endl;
        //forces a new line after the 10th column is populated
    }
}

//****************************************************************
//  updateBoard populates the Chessboard with pieces             *                                                   
//****************************************************************
bool Chessboard::updateBoard(int tempX, int tempY, char tempName)
{
    if (!isOccupied(tempX, tempY))   //if spot open
    {
        board[tempX][tempY] = tempName; //char name populates object array

        return true;
    }
    return false;
}
//*************************************************************************
//  isOccupied decides if potential move is open, signified with '.'      *   
//*************************************************************************
bool Chessboard::isOccupied(int x, int y)
{
    //retrieve value
    //then compare
    if (board[x][y] == '.') //'.' represents an open spot
    {
        return false;
    }
    else
    {
        return true;
    }
}
