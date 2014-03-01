#ifndef NQUEEN_H
#define NQUEEN_H

class nQueen {
    private:
        int* board;                 // Array representing game board.
        int size;                   // Dimensions of game board, will always be square, size x size.
        char letters[26];           // Array of letters used for display.
        
    public:
        nQueen(int n);
        ~nQueen();
        void solve(int k = 0);
        bool attackable(int queen_number, int row_position);
        void printQueenCoords();    // Set representation of game board solutions.
        void printPretty();         // Text representation of game board solutions.
        int solutions;              // Counts total number of solutions found.
};

#endif
