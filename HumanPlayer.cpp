#include "HumanPlayer.h"




HumanPlayer::HumanPlayer() {

}
HumanPlayer::HumanPlayer(char letterRep, Board* boardPtr) : Player(letterRep, boardPtr)  {

}



int HumanPlayer::getMove() {
    int columnChoice;
    std::cout << "\nWhat column would you like to place your piece in?\n";
    std::cin >> columnChoice;
    while (!checkValidMove(columnChoice)) {
        std::cout << "You cannot place your piece in that column. Make another choice." << std::endl;
        std::cin >> columnChoice;
    }
    return columnChoice;
}

HumanPlayer::~HumanPlayer() {

}