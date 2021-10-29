#ifndef GAME_
#define GAME_
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Board.h"

class Game {

private:
    HumanPlayer* player;
    ComputerPlayer* computer;
    Player* currentPlayer;
    Board* board;

    void changeCurrentPlayer();
    bool boardIsFull() const;

public:
    Game();
    ~Game();
    void playGame();
    bool checkWin() const;
    bool checkDraw() const;

};


#endif




