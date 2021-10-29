#ifndef SQUARE_
#define SQUARE_


class Square {

private:
    char piece;

public:
    Square();
    ~Square();
    Square(char);
    void setPiece(char);
    char getPiece() const;
    bool hasPiece() const;
};


#endif
