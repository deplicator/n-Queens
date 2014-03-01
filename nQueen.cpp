/**
 * James Pryor
 * COMP3053 Analysis of Algorithms
 * Homework #2 - Eight Queens
 * 
 * nQueen.cpp
 */

#include <iostream>
#include "nQueen.h"

using namespace std;

nQueen::nQueen(int n) {
    size = n;
    board = new int[size];

    char temp[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                   'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for(int i = 0; i < 26; i++) {
        letters[i] = temp[i];
    }
    
    solutions = 0;
    for(int i = 0; i < size; i++) {
        board[i] = 0;
    }
}

nQueen::~nQueen() {
    delete board;
}
 
bool nQueen::attackable(int column, int row) {
    for (int i = 0; i < column; i++) {
        if (board[i] == row || board[i] == row - (column - i) || board[i] == row + (column - i)) {
        //if(board[i] == board[column] || abs(board[column]-board[i]) == column - i) {
        //never could get this to work, requires cmath.
            return true;
        }
    }
    return false;
}
 
void nQueen::solve(int x) {
    if (x == size) {
        cout << endl << "  Solution " << ++solutions << endl;
        if(solutions < 10) {
            cout << "  ----------" << endl;
        } else {
            cout << "  -----------" << endl;
        }
        printPretty();
    } else {
        for (int i = 0; i < size; i++) {
            if (!attackable(x, i)) {
                board[x] = i;
                solve(x + 1);
            }
        }
    }
}

void nQueen::printQueenCoords() {
    int letter;
    cout << "  Queen Coordinates = {";
    for(int i = 0; i < size; i++) {
        if(i < size-1) {
            cout << "(" << i+1 << ", " << letters[board[i]] << "), ";
        } else {
            cout << "(" << i+1 << ", " << letters[board[i]] << ")}" << endl << endl;
        }
    }
}

/**
 * Print whole game board.
 */
void nQueen::printPretty() {
    //column marker across top
    cout << endl << "    ";
    for(int i = 0; i < size; i++) {
        cout << "  " << letters[i] << " ";
    }
    
    //top of board
    cout << endl << "    +";
    for(int i = 0; i < size; i++) {
        cout << "---+";
    }
    
    //for each row
    for(int i = 0; i < size; i++) {
        //row marker on left
        if(i < 9) {
            cout << endl << "  " << i+1 << " | ";
        } else {
            cout << endl << " " << i+1 << " | ";
        }
        
        //board contents
        for(int j = 0; j < size; j++) {
            if(board[i] == j) {
                if(j < 9) {
                    cout << board[i]+1 << " | ";
                } else if(j < 99) {
                    cout << board[i]+1 << "| ";
                } else {
                    cout << board[i]+1 << "|"; //doubt we'll ever need this.
                }
            } else {
                cout << "0 | ";
            }
        }
        
        //line between contents
        cout << endl << "    +";
        for(int k = 0; k < size; k++) {
            cout << "---+";
        }
    }
    cout << endl <<  endl;
    printQueenCoords();
}
