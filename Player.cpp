#include "Player.h"

Board* Player::boardPtr;

Player::Player() {
    this->pieceRep = ' ';
    this->boardPtr = nullptr;

}

Player::Player(char pieceRep, Board* boardPtr) {
    this->pieceRep = pieceRep;
    this->boardPtr = boardPtr;

}


void Player::setPieceRep(char pieceRep) {
    this->pieceRep = pieceRep;
}

char Player::getPieceRep() const {
    return pieceRep;
}


bool Player::checkValidMove(int col) const {

//Check if column exists
    if (col >= boardPtr->getNumCols()) {
        return false;
    }
//make sure column is not full
    else if (boardPtr->getSquare(0, col)->hasPiece()) {
        return false;
    }

    return true;
}

void Player::move(int moveCol) {
    for (int i = boardPtr->getNumRows() - 1; i >= 0; i--) {
        if (!boardPtr->getSquare(i, moveCol)->hasPiece()) {
            boardPtr->getSquare(i, moveCol)->setPiece(this->getPieceRep());
            return;
        }
    }
}
void Player::move(int moveCol, char piece) {
    for (int i = boardPtr->getNumRows() - 1; i >= 0; i--) {
        if (!boardPtr->getSquare(i, moveCol)->hasPiece()) {
            boardPtr->getSquare(i, moveCol)->setPiece(piece);
            return;
        }
    }
}

void Player::undoMove(int moveCol) {
    for (int i = 0; i < boardPtr->getNumRows(); i++) {
        if (boardPtr->getSquare(i, moveCol)->hasPiece()) {
            boardPtr->getSquare(i, moveCol)->setPiece('.');
            return;
        }
    }
}

int Player::getMove() {

    return 0;

}

void Player::setBoard(Board* bPtr) {
    boardPtr = bPtr;
}




Player::~Player() {

}