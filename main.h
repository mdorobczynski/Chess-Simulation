/*
Martin Dorobczynski
Final Project Chess
12/11/2019
CSIS 297
*/
#include "Chessboard.hpp" //include header file
#include <string>
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include "Rook.hpp"
#include "Pawn.hpp"
#include <iostream> //allows reading/writing to standard input/output stream
using namespace std;

//*************************************************************************
// Menu is the initial prompt to the user and is called after every move  *
//*************************************************************************
int menu()
{
    int choice; //local variable initiliazed

    do //dowhile runs atleast once
    {
        cout << "Press 1: to continue\nPress 2: to EXIT" << endl;
        cin >> choice;
    } while (choice != 1 and choice != 2);
    {
        return choice;
    }
}
//*****************************************************
// selectPiece is a menu for choosing the game piece  *
//*****************************************************
int selectPiece()
{
    int choice;
    cout << endl << "Please select a game piece\n 1 for King\n 2 for Queen\n 3 for Bishop\n 4 for Knight\n 5 for Rook\n 6 for Pawn\n"
        << endl;
    cin >> choice;
    return choice;
}
//*******************************************************
//                        MAIN                          *
//*******************************************************
int main()
{
    Chessboard board;   //Chessboard object

    King k1(1, 5);      //King object with specific board location passed
    Queen q1(1, 4);
    Bishop b1(1, 3);
    Bishop b2(1, 6);
    Knight n1(1, 2);
    Knight n2(1, 7);
    Rook r1(1, 1);
    Rook r2(1, 8);
    Pawn p1(2, 1);
    Pawn p2(2, 2);
    Pawn p3(2, 3);
    Pawn p4(2, 4);
    Pawn p5(2, 5);
    Pawn p6(2, 6);
    Pawn p7(2, 7);
    Pawn p8(2, 8);

    Bishop bArray[2];   //Array of Bishop object with 2 indexes for each piece
    bArray[0] = b1;
    bArray[1] = b2;

    Knight kArray[2];
    kArray[0] = n1;
    kArray[1] = n2;

    Rook rArray[2];
    rArray[0] = r1;
    rArray[1] = r2;

    Pawn pArray[8];
    pArray[0] = p1;
    pArray[1] = p2;
    pArray[2] = p3;
    pArray[3] = p4;
    pArray[4] = p5;
    pArray[5] = p6;
    pArray[6] = p7;
    pArray[7] = p8;

    board.updateBoard(k1.initialRow, k1.initialColumn, k1.nameOf); //function updateBoard called on board object
    board.updateBoard(q1.initialRow, q1.initialColumn, q1.nameOf);
    board.updateBoard(b1.initialRow, b1.initialColumn, b1.nameOf);
    board.updateBoard(b2.initialRow, b2.initialColumn, b2.nameOf);
    board.updateBoard(n1.initialRow, n1.initialColumn, n1.nameOf);
    board.updateBoard(n2.initialRow, n2.initialColumn, n2.nameOf);
    board.updateBoard(r1.initialRow, r1.initialColumn, r1.nameOf);
    board.updateBoard(r2.initialRow, r2.initialColumn, r2.nameOf);
    board.updateBoard(p1.initialRow, p1.initialColumn, p1.nameOf);
    board.updateBoard(p2.initialRow, p2.initialColumn, p2.nameOf);
    board.updateBoard(p3.initialRow, p3.initialColumn, p3.nameOf);
    board.updateBoard(p4.initialRow, p4.initialColumn, p4.nameOf);
    board.updateBoard(p5.initialRow, p5.initialColumn, p5.nameOf);
    board.updateBoard(p6.initialRow, p6.initialColumn, p6.nameOf);
    board.updateBoard(p7.initialRow, p7.initialColumn, p7.nameOf);
    board.updateBoard(p8.initialRow, p8.initialColumn, p8.nameOf);

    cout << "*** WELCOME TO CHESS ***" << endl << endl;
    board.printBoard();     //function printBoard called on object board
    int menuOption = menu(); //passes menu integer into the menuOption variable

    while (menuOption != 2) //2 exits the program, option 1 enters the while loop
    {
        int choice = selectPiece(); //user choice returned & passed into switch "choice"

        int moveChosen;     //variables shared within while loop
        int maxMoves;
        int chosenSubpiece;

        switch (choice)
        {
        case 1: {
            cout << "You've chosen KING\n";
            maxMoves = k1.choices();   //"countLegalMoves" passed to maxMovesK
            cout << "Choose move number 1 thru " << maxMoves << endl;
            cin >> moveChosen;
            int xK = k1.offsets[moveChosen - 1][0];  //user chosen row
            int yK = k1.offsets[moveChosen - 1][1];  //user chosen column

            if (!board.updateBoard(xK, yK, k1.nameOf)) //updateBoard checks isOccupied
            {
                cout << "Sorry this is not a legal move" << endl << endl;
                board.printBoard(); //printBoard called on object board
            }
            else
            {
                board.board[k1.initialRow][k1.initialColumn] = '.'; //following a moving piece
                k1.initialRow = xK;
                k1.initialColumn = yK;
                cout << "Board updated" << endl << endl;
                board.printBoard();
            }
            break; }
        case 2: {
            cout << "You've chosen QUEEN\n";
            maxMoves = q1.choices();
            cout << "Choose move number 1 thru " << maxMoves << endl;
            cin >> moveChosen;
            int xQ = q1.offsetQ[moveChosen - 1][0];
            int yQ = q1.offsetQ[moveChosen - 1][1];

            if (!board.updateBoard(xQ, yQ, q1.nameOf))
            {
                cout << "Sorry this is not a legal move" << endl << endl;
                board.printBoard();
            }
            else
            {
                board.board[q1.initialRow][q1.initialColumn] = '.';
                q1.initialRow = xQ;
                q1.initialColumn = yQ;
                cout << "Board updated" << endl << endl;
                board.printBoard();
            }
            break; }
        case 3: {
            cout << "You've chosen BISHOP\n";
            cout << "Choose Bishop piece 1 or 2\n";
            cin >> chosenSubpiece;

            Bishop* bPointer = &bArray[chosenSubpiece - 1];

            maxMoves = bPointer->choices();
            cout << "Choose move number 1 thru " << maxMoves << endl;
            cin >> moveChosen;
            int xB = bPointer->offsetB[moveChosen - 1][0];
            int yB = bPointer->offsetB[moveChosen - 1][1];

            if (!board.updateBoard(xB, yB, bPointer->nameOf))
            {
                cout << "Sorry this is not a legal move" << endl << endl;
                board.printBoard();
            }
            else
            {
                board.board[bPointer->initialRow][bPointer->initialColumn] = '.';
                bPointer->initialRow = xB;
                bPointer->initialColumn = yB;
                cout << "Board updated" << endl << endl;
                board.printBoard();
            }
            break; }
        case 4: {
            cout << "You've chosen KNIGHT\n";
            cout << "Choose Knight piece 1 or 2\n";
            cin >> chosenSubpiece;

            Knight* kPointer = &kArray[chosenSubpiece - 1];

            maxMoves = kPointer->choices();
            cout << "Choose move number 1 thru " << maxMoves << endl;
            cin >> moveChosen;
            int xN = kPointer->offsets[moveChosen - 1][0];
            int yN = kPointer->offsets[moveChosen - 1][1];

            if (!board.updateBoard(xN, yN, kPointer->nameOf))
            {
                cout << "Sorry this is not a legal move" << endl << endl;
                board.printBoard();
            }
            else
            {
                board.board[kPointer->initialRow][kPointer->initialColumn] = '.';
                kPointer->initialRow = xN;
                kPointer->initialColumn = yN;
                cout << "Board updated" << endl << endl;
                board.printBoard();
            }
            break; }
        case 5: {
            cout << "You've chosen ROOK\n";
            cout << "Choose Knight piece 1 or 2\n";
            cin >> chosenSubpiece;

            Rook* rPointer = &rArray[chosenSubpiece - 1];

            int maxMoves = rPointer->choices();
            cout << "Choose move number 1 thru " << maxMoves << endl;
            cin >> moveChosen;
            int xR = rPointer->offsetR[moveChosen - 1][0];
            int yR = rPointer->offsetR[moveChosen - 1][1];

            if (!board.updateBoard(xR, yR, rPointer->nameOf))
            {
                cout << "Sorry this is not a legal move" << endl << endl;
                board.printBoard();
            }
            else
            {
                board.board[rPointer->initialRow][rPointer->initialColumn] = '.';
                rPointer->initialRow = xR;
                rPointer->initialColumn = yR;
                cout << "Board updated" << endl << endl;
                board.printBoard();
            }
            break; }
        default:
            cout << "You've chosen PAWN\n";
            cout << "Choose Pawn piece 1-8\n";
            cin >> chosenSubpiece;

            Pawn* pPointer = &pArray[chosenSubpiece - 1];

            int maxMoves = pPointer->choices();
            cout << "Choose move number 1 thru " << maxMoves << endl;
            cin >> moveChosen;
            int xP = pPointer->offsets[moveChosen - 1][0];
            int yP = pPointer->offsets[moveChosen - 1][1];

            if (!board.updateBoard(xP, yP, pPointer->nameOf))
            {
                cout << "Sorry this is not a legal move" << endl << endl;
                board.printBoard();
            }
            else
            {
                board.board[pPointer->initialRow][pPointer->initialColumn] = '.';
                pPointer->initialRow = xP;
                pPointer->initialColumn = yP;
                cout << "Board updated" << endl << endl;
                board.printBoard();
            }
            break;
        }
        menuOption = menu();    //keeps while going until exit is chosen
    }
    cout << endl
        << "GAME OVER..." << endl << endl;

    board.printBoard(); //output the finished chessboard

    return 0;
}
