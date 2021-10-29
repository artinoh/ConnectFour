#include "Square.h"

Square::Square() {
    piece = '.';
}

Square::Square(char piece) {
    this->piece = piece;
}


bool Square::hasPiece() const {
    if (getPiece() == '.') {
        return false;
    }
    else {
        return true;
    }
}


void Square::setPiece(char inPiece) {
    this->piece = inPiece;
}
char Square::getPiece() const{
    return piece;
}

Square::~Square() {

}