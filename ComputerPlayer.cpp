#include "ComputerPlayer.h"


ComputerPlayer::ComputerPlayer() {

}

ComputerPlayer::ComputerPlayer(char letterRep, Board* boardPtr) : Player(letterRep, boardPtr) {

}



int ComputerPlayer::getMove() {

    int numRows = boardPtr->getNumRows();
    int numCols = boardPtr->getNumCols();
    int columnChoice = 1;
    int bestVal = INT_MIN;

    for (int i = 0; i < numCols; i++) {
        if (checkValidMove(i)) {
            move(i);
            int moveVal = minimax(6, false, -1000, 1000);
            undoMove(i);
            if (moveVal > bestVal) {
                columnChoice = i;
                bestVal = moveVal;
            }
        }
    }
    return columnChoice;
}



int ComputerPlayer::minimax(int depth, bool isMax, int alpha, int beta) {
    int numRows = boardPtr->getNumRows();
    int numCols = boardPtr->getNumCols();
    int score = evaluate();
    if (score == 1000) {
        return score;
    }
    if (score == -1000) {
        return score;
    }
    if (boardPtr->fullBoard()) {
        return 0;
    }
    if (depth == 0) {

        return score;
    }
//Maximizing Player (computer)
    if (isMax) {
        int best = INT_MIN;
        for (int i = 0; i < numCols; i++) {
            if (checkValidMove(i)) {
                move(i);
                best = max(best, minimax(depth - 1, !isMax, alpha, beta));
                undoMove(i);
                alpha = max(alpha, best);
                if (alpha >= beta) {
                    break;
                }
            }
        }
        return best;
    }
//Minimizing Player (Player)
    else {
        int best = INT_MAX;
        for (int i = 0; i < numCols; i++) {
            if (checkValidMove(i)) {
                move(i, playerPiece);
                best = min(best, minimax(depth - 1, !isMax, alpha, beta));
                undoMove(i);
                beta = min(beta, best);
                if (alpha >= beta) {
                    break;
                }
            }
        }
        return best;
    }
}


int ComputerPlayer::max(int a, int b) const {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int ComputerPlayer::min(int a, int b) const {
    if (a > b) {
        return b;
    }
    else {
        return a;
    }
}

int ComputerPlayer::evaluate() {
    int numRows = boardPtr->getNumRows();
    int numCols = boardPtr->getNumCols();
    int winValueComputer = 1000;
    int winValuePlayer = -1000;

    int score = 0;

//Slighty weigh the middle column
    for (int i = 0; i < numRows; i++) {
        if (boardPtr->getSquare(i, 3)->getPiece() == this->getPieceRep()) {
            score += 3;
        }
    }

//Slightly weight the 2 columns next to the middle
    for (int i = 0; i < numRows; i++) {
        if (boardPtr->getSquare(i, 4)->getPiece() == this->getPieceRep() || boardPtr->getSquare(i, 2)->getPiece() == this->getPieceRep()) {
            score += 3;
        }
    }

    int winCountPlayer = numWins(playerPiece);
    int winCountComputer = numWins(this->getPieceRep());


//Check for wins, if so return max value
    if (winCountComputer || winCountPlayer) {
        if (winCountComputer) {
            return winValueComputer;
        }
        else {
            return winValuePlayer;
        }
    }

    else {
        //get computer score
        int pairValueComputer = 20;
        int tripleValueComputer = 50;
        int pairCountComputer = numPairs(this->getPieceRep());
        int tripleCountComputer = numTriples(this->getPieceRep());
        score += pairValueComputer * pairCountComputer;
        score += tripleValueComputer * tripleCountComputer;


        //get player score
        int pairValuePlayer = -25;
        int tripleValuePlayer = -55;
        int pairCountPlayer = numPairs(playerPiece);
        int tripleCountPlayer = numTriples(playerPiece);
        score += pairValuePlayer * pairCountPlayer;
        score += tripleValuePlayer * tripleCountPlayer;
    }
    return score;
}


int ComputerPlayer::numPairs(char piece) {
    int numRows = boardPtr->getNumRows();
    int numCols = boardPtr->getNumCols();
    int pairCount = 0;

//Go through board
    for (int i = numRows - 1; i >= 0; i--) {
        for (int j = 0; j < numCols; j++) {

            //Check Rows
            if (j < numCols - 3
                && boardPtr->getSquare(i, j)->getPiece() == piece
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i, j + 1)->getPiece()) {
                pairCount++;
            }

            //Check Cols
            if (i >= numRows - 3
                && boardPtr->getSquare(i, j)->getPiece() == piece
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i - 1, j)->getPiece()) {
                pairCount++;
            }

            //Check Main Diags
            if (i >= numRows - 3
                && j >= 3
                && boardPtr->getSquare(i, j)->getPiece() == piece
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i - 1, j - 1)->getPiece()) {
                pairCount++;
            }

            //Check Anti Diags
            if (i >= numRows - 3
                && j < numCols - 3
                && boardPtr->getSquare(i, j)->getPiece() == piece
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i - 1, j + 1)->getPiece()) {
                pairCount++;
            }
        }
    }

    return pairCount;
}

int ComputerPlayer::numTriples(char piece) {
    int numRows = boardPtr->getNumRows();
    int numCols = boardPtr->getNumCols();
    int tripleCount = 0;


//Go through board
    for (int i = numRows - 1; i >= 0; i--) {
        for (int j = 0; j < numCols; j++) {

            //Check Rows
            if (j < numCols - 3
                && boardPtr->getSquare(i, j)->getPiece() == piece
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i, j + 1)->getPiece()
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i, j + 2)->getPiece()) {
                tripleCount++;
            }

            //Check Cols
            if (i >= numRows - 3
                && boardPtr->getSquare(i, j)->getPiece() == piece
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i - 1, j)->getPiece()
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i - 2, j)->getPiece()) {
                tripleCount++;
            }

            //Check Main Diags
            if (i >= numRows - 3
                && j >= 3
                && boardPtr->getSquare(i, j)->getPiece() == piece
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i - 1, j - 1)->getPiece()
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i - 2, j - 2)->getPiece()) {
                tripleCount++;
            }

            //Check Anti Diags
            if (i >= numRows - 3
                && j < numCols - 3
                && boardPtr->getSquare(i, j)->getPiece() == piece
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i - 1, j + 1)->getPiece()
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i - 2, j + 2)->getPiece()) {
                tripleCount++;
            }
        }
    }
    return tripleCount;
}

int ComputerPlayer::numWins(char piece) {
    int numRows = boardPtr->getNumRows();
    int numCols = boardPtr->getNumCols();
    int winCount = 0;

//Go through board
    for (int i = numRows - 1; i >= 0; i--) {
        for (int j = 0; j < numCols; j++) {

            //Check Rows
            if (j < numCols - 3
                && boardPtr->getSquare(i, j)->getPiece() == piece
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i, j + 1)->getPiece()
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i, j + 2)->getPiece()
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i, j + 3)->getPiece()) {
                winCount++;
            }

            //Check Cols
            if (i >= numRows - 3
                && boardPtr->getSquare(i, j)->getPiece() == piece
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i - 1, j)->getPiece()
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i - 2, j)->getPiece()
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i - 3, j)->getPiece()) {
                winCount++;
            }

            //Check Main Diags
            if (i >= numRows - 3
                && j >= 3
                && boardPtr->getSquare(i, j)->getPiece() == piece
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i - 1, j - 1)->getPiece()
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i - 2, j - 2)->getPiece()
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i - 3, j - 3)->getPiece()) {
                winCount++;
            }

            //Check Anti Diags
            if (i >= numRows - 3
                && j < numCols - 3
                && boardPtr->getSquare(i, j)->getPiece() == piece
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i - 1, j + 1)->getPiece()
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i - 2, j + 2)->getPiece()
                && boardPtr->getSquare(i, j)->getPiece() == boardPtr->getSquare(i - 3, j + 3)->getPiece()) {
                winCount++;
            }
        }
    }
    return winCount;
}



ComputerPlayer::~ComputerPlayer() {

}


