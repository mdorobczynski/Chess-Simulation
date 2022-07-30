/*
bishop.CPP
*/
#include "Bishop.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Bishop::Bishop()    //default constructor
{}
//*******************************************************
//                    The constructor                   *                                                   
//*******************************************************
Bishop::Bishop(int x, int y)
{
    initialRow = x - 1;
    initialColumn = y - 1;
    nameOf = 'B';
    countLegalMoves = 0;
}
//*************************************************************************
//  legalMove validates that row & column piece falls within board        *                                                   
//*************************************************************************
int Bishop::legalMove(int x, int y)
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
int Bishop::getLegalMoves()
{
    int iCount = 0;         //initalizes starting count to 0
    int moveNum = 0;        //initalizes starting moves to 0
    int iX = initialRow;    //sets row equal to x-axis
    int iY = initialColumn; //sets column equal to y-axis

    //Quarter1
    while (iX >= 0 && iY <= 7)
    {
        iX = iX - 1; //initalizing x & row for one of the 8 possible moves
        iY = iY + 1; //initalizing y and column for one of the 8 possible moves
        offsetB[iCount][0] = iX;
        offsetB[iCount][1] = iY;
        if (legalMove(iX, iY))
        {
            moveB[moveNum++] = iCount + 1;
        }
        else
        {
            break;
        }
        iCount++; //increment variable iCount
    }
    iX = initialRow;    //sets row equal to x-axis
    iY = initialColumn; //sets column equal to y-axis

    //Quarter2
    iCount++; //increment variable iCount
    while (iX >= 0 && iY >= 0)
    {
        iX = iX - 1; //initalizing x & row for one of the 8 possible moves
        iY = iY - 1; //initalizing y and column for one of the 8 possible moves
        offsetB[iCount][0] = iX;
        offsetB[iCount][1] = iY;
        if (legalMove(iX, iY))
        {
            moveB[moveNum++] = iCount + 1;
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

    //Quarter3
    while (iX <= 7 && iY >= 0)
    {
        iX = iX + 1; //initalizing x & row for one of the 8 possible moves
        iY = iY - 1; //initalizing y and column for one of the 8 possible moves
        offsetB[iCount][0] = iX;
        offsetB[iCount][1] = iY;
        if (legalMove(iX, iY))
        {
            moveB[moveNum++] = iCount + 1;
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

    //Quarter4
    while (iX <= 7 && iY <= 7)
    {
        iX = iX + 1; //initalizing x & row for one of the 8 possible moves
        iY = iY + 1; //initalizing y and column for one of the 8 possible moves
        offsetB[iCount][0] = iX;
        offsetB[iCount][1] = iY;
        if (legalMove(iX, iY))
        {
            moveB[moveNum++] = iCount + 1;
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
int Bishop::getCountLegalMoves()
{
    return countLegalMoves;
}
//*************************************************************
//  choices calls function getLegalMoves returning moveNum    *
//  outputs number of legal moves and legal move number       *                                                  
//*************************************************************
int Bishop::choices()
{
    getLegalMoves();  //access attributes

    //cout for the number of legal moves for instance "board"
    cout << "The number of legal moves is: " << getCountLegalMoves() << endl;
    cout << endl;

    //for loop
    //cout move location
    for (int i = 0; i < MOVEB; i++)
    {
        cout << (i + 1) << ": " << offsetB[i][0] + 1 << "," << offsetB[i][1] + 1 << endl;
    }
    cout << endl;

    //for loop
    //cout the legal move number
    for (int i = 0; i < getCountLegalMoves(); i++)
    {
        cout << "The legal move number is: " << moveB[i] << endl;
    }
    cout << endl
        << endl;

    return getCountLegalMoves();
}