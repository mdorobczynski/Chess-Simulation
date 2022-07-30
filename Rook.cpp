/*
rook.CPP
*/
#include "Rook.h"
#include <iostream>
#include <string>
using namespace std;
Rook::Rook()    //default constructor
{}
//*******************************************************
//                    The constructor                   *                                                   
//*******************************************************
Rook::Rook(int x, int y)
{
    initialRow = x - 1;
    initialColumn = y - 1;
    nameOf = 'R';
    countLegalMoves = 0;
}
//********************************************************************************
//  legalMove validates that row & column piece falls within board               *                                                   
//********************************************************************************
int Rook::legalMove(int x, int y)
{
    if ((0 <= x && x <= 7) && (0 <= y && y <= 7))
    {
        return 1;
    }
    return 0;
}
//***************************************************************************
//  getLegalMoves handles each possible piece move and returns moveNum      *                                                   
//***************************************************************************
int Rook::getLegalMoves()
{
    int iCount = 0;         //initalizes starting count to 0
    int moveNum = 0;        //initalizes starting moves to 0
    int iX = initialRow;    //sets row equal to x-axis
    int iY = initialColumn; //sets column equal to y-axis

    //NORTH
    while (iX >= 0)
    {
        iX = iX - 1; //initalizing x & row for one of the 8 possible moves
        iY = iY + 0; //initalizing y and column for one of the 8 possible moves
        offsetR[iCount][0] = iX;
        offsetR[iCount][1] = iY;
        if (legalMove(iX, iY))
        {
            moveR[moveNum++] = iCount + 1;
        }
        else
        {
            break;
        }
        iCount++; //increment variable iCount
    }
    iX = initialRow;    //sets row equal to x-axis
    iY = initialColumn; //sets column equal to y-axis

    //WEST
    iCount++; //increment variable iCount
    while (iY >= 0)
    {
        iX = iX + 0; //initalizing x & row for one of the 8 possible moves
        iY = iY - 1; //initalizing y and column for one of the 8 possible moves
        offsetR[iCount][0] = iX;
        offsetR[iCount][1] = iY;
        if (legalMove(iX, iY))
        {
            moveR[moveNum++] = iCount + 1;
        }
        else
        {
            break;
        }
        iCount++; //increment variable iCount
    }
    iX = initialRow;    //sets row equal to x-axis
    iY = initialColumn; //sets column equal to y-axis

    iCount++; //increment variable iCount
    //SOUTH
    while (iX <= 7)
    {
        iX = iX + 1; //initalizing x & row for one of the 8 possible moves
        iY = iY + 0; //initalizing y and column for one of the 8 possible moves
        offsetR[iCount][0] = iX;
        offsetR[iCount][1] = iY;
        if (legalMove(iX, iY))
        {
            moveR[moveNum++] = iCount + 1;
        }
        else
        {
            break;
        }
        iCount++; //increment variable iCount
    }
    iX = initialRow;    //sets row equal to x-axis
    iY = initialColumn; //sets column equal to y-axis

    iCount++; //increment variable iCount
    //EAST
    while (iY <= 7)
    {
        iX = iX + 0; //initalizing x & row for one of the 8 possible moves
        iY = iY + 1; //initalizing y and column for one of the 8 possible moves
        offsetR[iCount][0] = iX;
        offsetR[iCount][1] = iY;
        if (legalMove(iX, iY))
        {
            moveR[moveNum++] = iCount + 1;
        }
        else
        {
            break;
        }
        iCount++; //increment variable iCount
    }
    countLegalMoves = moveNum; //Number of moves now equals variable countLegalMoves
    return moveNum;            //Number of moves value is returned
}
//***************************************************
//  getCountLegalMoves returns countLegalMoves      *                                                   
//***************************************************
int Rook::getCountLegalMoves()
{
    return countLegalMoves;
}
//*************************************************************
//  choices calls function getLegalMoves returning moveNum    *
//  outputs number of legal moves and legal move number       *                                                  
//*************************************************************
int Rook::choices()
{
    getLegalMoves();    //access attributes

    //cout for the number of legal moves for instance "board"
    cout << "The number of legal moves is: " << getCountLegalMoves() << endl;
    cout << endl;

    //for loop
    //cout move location
    for (int i = 0; i < MOVER; i++)
    {
        cout << (i + 1) << ": " << offsetR[i][0] + 1 << "," << offsetR[i][1] + 1 << endl;
    }
    cout << endl;

    //for loop
    //cout the legal move number
    for (int i = 0; i < getCountLegalMoves(); i++)
    {
        cout << "The legal move number is: " << moveR[i] << endl;
    }
    cout << endl
        << endl;

    return getCountLegalMoves();
}