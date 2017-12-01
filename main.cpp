#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "function.h"
#include <conio.h>

using namespace std;

int main() {
    // set position of the player to (0;0)
    int playerPositionX = 0;
    int playerPositionY = 0;

    // create the blank playground
    char **playGround;
    playGround = new char *[10];
    for(int i = 0; i < 10; i++)
        playGround[i] = new char[10];

    // create soil
    for ( int i = 0; i < 10; i++)
        for ( int j = 0 ; j < 10 ; j++) {
            playGround[i][j] = '.';
        }
    // create player
    playGround[0][0] = 'G';
    // create goal
    playGround[9][9] = 'X';

    // create some trap
    playGround[4][5] = 'T';

    // PLAY
    // display the beginning playground
    display(playGround);

    //      Create movement variable to contain current
    //      movement
    char movement;

    //      checkStatus: a variable to check traped or win status
    int checkStatus = 0;
    //      Loop forever to fetch movement from keyboard
    //      then do some action
    for ( ; ; ) {
        //  Movement
        movement = getch();
        switch (movement) {
        case 'w':
            checkStatus = moveUp(playerPositionX,playerPositionY,playGround);
            break;
        case 'd':
            checkStatus = moveRight(playerPositionX,playerPositionY,playGround);
            break;
        case 's':
            checkStatus = moveDown(playerPositionX,playerPositionY,playGround);
            break;
        case 'a':
            checkStatus = moveLeft(playerPositionX,playerPositionY,playGround);
            break;
        }
        // clear old graphic before display the new one
        system("cls");
        // display the graphic
        display(playGround);
        if (checkStatus == 1) {
            cout << "You walked on a trap! \n"
                 << "GAME OVER!";
            break;
        } else if (checkStatus == 2) {
            cout << "You claimed the TREASURE! \n"
                 << "VICTORY";
            break;
        }
    }
}
