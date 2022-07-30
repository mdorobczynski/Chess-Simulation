/*
knight.CPP
*/
#include "Knight.h"
#include <iostream>
#include <string>
using namespace std;
Knight::Knight()    //default constructor
{}
//*******************************************************
//                    The constructor                   *                                                   
//*******************************************************
Knight::Knight(int x, int y)
{
    initialRow = x - 1;
    initialColumn = y - 1;
    nameOf = 'N';
    countLegalMoves = 0;
}
//********************************************************************************
//  legalMove validates that row & column piece falls within board               *                                                   
//********************************************************************************
int Knight::legalMove(int x, int y)
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
int Knight::getLegalMoves()
{
    int iCount = 0;         //initalizes starting count to 0
    int moveNum = 0;        //initalizes starting moves to 0
    int iX = initialRow;    //sets row equal to x-axis
    int iY = initialColumn; //sets column equal to y-axis
    iX = initialRow + 2;    //initalizing x & row for one of the 8 possible moves

    iY = initialColumn + 1; //initalizing y and column for one of the 8 possible moves
    offsets[iCount][0] = iX;

    offsets[iCount][1] = iY;
    if (legalMove(iX, iY))
    {
        moves[moveNum++] = iCount + 1;
    }
    iCount++; //increment variable iCount

    iX = initialRow + 2;
    iY = initialColumn - 1;
    offsets[iCount][0] = iX;
    offsets[iCount][1] = iY;
    if (legalMove(iX, iY))
    {
        moves[moveNum++] = iCount + 1;
    }
    iCount++;

    iX = initialRow + 1;
    iY = initialColumn + 2;
    offsets[iCount][0] = iX;
    offsets[iCount][1] = iY;
    if (legalMove(iX, iY))
    {
        moves[moveNum++] = iCount + 1;
    }
    iCount++;

    iX = initialRow + 1;
    iY = initialColumn - 2;
    offsets[iCount][0] = iX;
    offsets[iCount][1] = iY;
    if (legalMove(iX, iY))
    {
        moves[moveNum++] = iCount + 1;
    }
    iCount++;

    iX = initialRow - 2;
    iY = initialColumn + 1;
    offsets[iCount][0] = iX;
    offsets[iCount][1] = iY;
    if (legalMove(iX, iY))
    {
        moves[moveNum++] = iCount + 1;
    }
    iCount++;

    iX = initialRow - 2;
    iY = initialColumn - 1;
    offsets[iCount][0] = iX;
    offsets[iCount][1] = iY;
    if (legalMove(iY, iX))
    {
        moves[moveNum++] = iCount + 1;
    }
    iCount++;

    iX = initialRow - 1;
    iY = initialColumn + 2;
    offsets[iCount][0] = iX;
    offsets[iCount][1] = iY;
    if (legalMove(iX, iY))
    {
        moves[moveNum++] = iCount + 1;
    }
    iCount++;

    iX = initialRow - 1;
    iY = initialColumn - 2;
    offsets[iCount][0] = iX;
    offsets[iCount][1] = iY;
    if (legalMove(iX, iY))
    {
        moves[moveNum++] = iCount + 1;
    }
    iCount++;

    countLegalMoves = moveNum; //Number of moves now equals variable countLegalMoves
    return moveNum;            //Number of moves value is returned
}
//***************************************************
//  getCountLegalMoves returns countLegalMoves      *                                                   
//***************************************************
int Knight::getCountLegalMoves()
{
    return countLegalMoves;
}
//*************************************************************
//  choices calls function getLegalMoves returning moveNum    *
//  outputs number of legal moves and legal move number       *                                                  
//*************************************************************
int Knight::choices()
{
    getLegalMoves();    //access attributes

    //cout for the number of legal moves for instance "board"
    cout << "The number of legal moves is: " << getCountLegalMoves() << endl;
    cout << endl;

    //for loop
    //cout move location
    for (int i = 0; i < 8; i++)
    {
        cout << (i + 1) << ": " << offsets[i][0] + 1 << "," << offsets[i][1] + 1 << endl;
    }
    cout << endl;

    //for loop
    //cout the legal move number
    for (int i = 0; i < getCountLegalMoves(); i++)
    {
        cout << "The legal move number is: " << moves[i] << endl;
    }
    cout << endl
        << endl;

    return getCountLegalMoves();
}