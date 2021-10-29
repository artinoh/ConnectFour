#ifndef HUMAN_PLAYER_
#define HUMAN_PLAYER_

#include "Player.h"
class HumanPlayer : public Player {


private:

public:
    HumanPlayer();
    ~HumanPlayer();
    HumanPlayer(char, Board*);
    virtual int getMove();

};


#endif


