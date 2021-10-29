#include "Board.h"


Board::Board() {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            squares[i][j] = new Square;
        }
    }

}



int Board::getNumRows() const {
    return numRows;
}
int Board::getNumCols() const {
    return numCols;
}

void Board::printBoard() const {
    std::cout << "\nConnect Four!\n";
    std::cout << "---------------\n  ";
    for (int i = 0; i < numCols; i++) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < numRows; i++) {
        std::cout << i << " ";
        for (int j = 0; j < numCols; j++) {
            if (!squares[i][j]->hasPiece()) {
                std::cout << "." << " ";
            }
            else {
                std::cout << squares[i][j]->getPiece() << " ";
            }
        }
        std::cout << "\n";
    }
}

bool Board::fullBoard() const {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (!squares[i][j]->hasPiece()) {
                return false;
            }
        }
    }
    return true;
}


Square* Board::getSquare(int row, int col) const{
    if (row < numRows && col < numCols) {
        return squares[row][col];
    }
    else {
        return nullptr;
    }

}

Board::~Board() {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            delete squares[i][j];
        }
    }
}