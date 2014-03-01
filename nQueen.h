#ifndef NQUEEN_H
#define NQUEEN_H

class nQueen {
    private:
        int* board;
        int size;
        char letters[26];
        
    public:
        nQueen(int n);
        ~nQueen();
        void solve(int k = 0);
        bool attackable(int queen_number, int row_position);
        void printQueenCoords();
        void printPretty();
        int solutions;
};

#endif
