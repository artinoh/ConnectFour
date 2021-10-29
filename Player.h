#ifndef PLAYER_
#define PLAYER_


#include "Board.h"


class Player {
    friend class HumanPlayer;
    friend class ComputerPlayer;

private:
    char pieceRep;
    static Board* boardPtr;

public:
    Player();
    ~Player();
    Player(char, Board*);
    char getPieceRep() const;
    void setPieceRep(char);
    void setBoard(Board*);
    bool checkValidMove(int) const;
    void move(int);
    void move(int, char);
    void undoMove(int);
    virtual int getMove();

};

#endif

