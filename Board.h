#ifndef BOARD_
#define BOARD_


#include "Square.h"
#include <iostream>

class Board {

private:
    static const int numRows = 6;
    static const int numCols = 7;
    Square* squares[6][7];

public:
    Board();
    ~Board();
    void printBoard() const;
    Square* getSquare(int, int) const;
    int getNumRows() const;
    int getNumCols() const;
    bool fullBoard() const;
};

#endif


