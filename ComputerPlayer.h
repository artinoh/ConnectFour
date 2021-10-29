#ifndef COMPUTER_PLAYER_
#define COMPUTER_PLAYER_


#include "Player.h"
#include <cstdlib>

class ComputerPlayer : public Player {


private:
    int max(int, int) const;
    int min(int, int) const;
    int evaluate();
    int minimax(int, bool, int, int);
    int numPairs(char);
    int numTriples(char);
    int numWins(char);
    const char playerPiece = 'X';



public:
    ComputerPlayer();
    ~ComputerPlayer();
    ComputerPlayer(char, Board*);
    virtual int getMove();


};

#endif