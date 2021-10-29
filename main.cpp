#include <iostream>
#include "Game.h"
using namespace std;

int main() {
    char userChoice;

    do {
        cout << "\nMenu\n";
        cout << "--------------\n";
        cout << "1) Play a game of connect four\n";
        cout << "Q) Quit\n";
        cin >> userChoice;
        if (userChoice == '1') {
            Game* connectFour = new Game();
            connectFour->playGame();
            delete connectFour;
        }
        else if (userChoice == 'Q' || userChoice == 'q') {
            cout << "\nThanks for playing!\n";
        }
        else {
            cout << "\nInvalid Choice\n";
        }

    }
    while (userChoice != 'Q' && userChoice != 'q');

    return 0;
}