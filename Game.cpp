#include "Game.h"



Game::Game() {
    board = new Board;
    player = new HumanPlayer('X', this->board);
    computer = new ComputerPlayer('O', this->board);
    currentPlayer = computer;
}



void Game::playGame() {
    while (!checkWin() && !checkDraw()) {
        changeCurrentPlayer();
        if (currentPlayer->getPieceRep() == 'X') {
            board->printBoard();
        }
        currentPlayer->move(currentPlayer->getMove());

    }
    board->printBoard();
    if (checkDraw()) {
        std::cout << "\nThe game was a draw!" << std::endl;
    }
    else if (checkWin() && currentPlayer->getPieceRep() == 'O') {
        std::cout << "\nThe computer wins!" << std::endl;
    }
    else {
        std::cout << "\nYou win!" << std::endl;
    }
}



void Game::changeCurrentPlayer() {
    if (currentPlayer == player) {
        currentPlayer = computer;
    }
    else if (currentPlayer == computer) {
        currentPlayer = player;
    }
}


bool Game::checkWin() const {
    int numRows = board->getNumRows();
    int numCols = board->getNumCols();

//Go through board
    for (int i = numRows-1; i >= 0; i--) {
        for (int j = 0; j < numCols; j++) {

            //Check Rows
            if (j < numCols-3
                && board->getSquare(i, j)->hasPiece()
                && board->getSquare(i, j)->getPiece() == board->getSquare(i, j + 1)->getPiece()
                && board->getSquare(i, j)->getPiece() == board->getSquare(i, j + 2)->getPiece()
                && board->getSquare(i, j)->getPiece() == board->getSquare(i, j + 3)->getPiece()) {

                board->getSquare(i, j)->setPiece('W');
                board->getSquare(i, j + 1)->setPiece('W');
                board->getSquare(i, j + 2)->setPiece('W');
                board->getSquare(i, j + 3)->setPiece('W');

                return true;
            }

            //Check Cols
            if (i >= numRows-3
                && board->getSquare(i, j)->hasPiece()
                && board->getSquare(i, j)->getPiece() == board->getSquare(i - 1, j)->getPiece()
                && board->getSquare(i, j)->getPiece() == board->getSquare(i - 2, j)->getPiece()
                && board->getSquare(i, j)->getPiece() == board->getSquare(i - 3, j)->getPiece()) {

                board->getSquare(i, j)->setPiece('W');
                board->getSquare(i - 1, j)->setPiece('W');
                board->getSquare(i - 2, j)->setPiece('W');
                board->getSquare(i - 3, j)->setPiece('W');
                return true;
            }

            //Check Main Diags
            if (i >= numRows-3
                && j >= 3
                && board->getSquare(i, j)->hasPiece()
                && board->getSquare(i, j)->getPiece() == board->getSquare(i - 1, j - 1)->getPiece()
                && board->getSquare(i, j)->getPiece() == board->getSquare(i - 2, j - 2)->getPiece()
                && board->getSquare(i, j)->getPiece() == board->getSquare(i - 3, j - 3)->getPiece()) {

                board->getSquare(i, j)->setPiece('W');
                board->getSquare(i - 1, j - 1)->setPiece('W');
                board->getSquare(i - 2, j - 2)->setPiece('W');
                board->getSquare(i - 3, j - 3)->setPiece('W');
                return true;
            }

            //Check Anti Diags
            if (i >= numRows-3
                && j < numCols-3
                && board->getSquare(i, j)->hasPiece()
                && board->getSquare(i, j)->getPiece() == board->getSquare(i - 1, j + 1)->getPiece()
                && board->getSquare(i, j)->getPiece() == board->getSquare(i - 2, j + 2)->getPiece()
                && board->getSquare(i, j)->getPiece() == board->getSquare(i - 3, j + 3)->getPiece()) {

                board->getSquare(i, j)->setPiece('W');
                board->getSquare(i - 1, j + 1)->setPiece('W');
                board->getSquare(i - 2, j + 2)->setPiece('W');
                board->getSquare(i - 3, j + 3)->setPiece('W');
                return true;
            }
        }
    }
    return false;
}





bool Game::checkDraw() const {
    if (boardIsFull() && !checkWin()) {
        return true;
    }
    return false;
}

bool Game::boardIsFull() const {
    for (int i = 0; i < board->getNumCols(); i++) {
        if (!board->getSquare(0, i)->hasPiece()) {
            return false;
        }
    }
    return true;
}


Game::~Game() {
    delete board;
    delete player;
    delete computer;
}

