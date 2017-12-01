#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "function.h"
#include <conio.h>
#include <ctime>

using namespace std;

int main() {
    // clear screen
    system("cls");

    // random function need this line
    srand(time(NULL));

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
    playGround[0][0] = 'H';

    // create treasure
    playGround[9][9] = 'X';

    // create blank trap map
    int **trapMap;
    trapMap = new int *[10];
    for(int i = 0; i < 10; i++)
        trapMap[i] = new int[10];

    // create random trap
    for ( int i = 0; i < 10; i++)
        for ( int j = 0 ; j < 10 ; j++) {
            trapMap[i][j] = 0;
            if ((i+j) != 0 && (i+j) != 18)
                if ((rand()%6) == 1)
                    trapMap[i][j] = 1;
        }

    // -----------------PLAY---------------------
    // display the beginning playground
    display(playGround);

    //  Create movement variable to contain current movement
    char movement;

    //      Loop forever to input movement from keyboard
    //      then do some actions
    for ( ; ; ) {
        //  input movement from keyboard
        movement = getch();

        // check movement
        switch (movement) {
        case 'w':
            moveUp(playerPositionX,playerPositionY,playGround);
            break;
        case 'd':
            moveRight(playerPositionX,playerPositionY,playGround);
            break;
        case 's':
            moveDown(playerPositionX,playerPositionY,playGround);
            break;
        case 'a':
            moveLeft(playerPositionX,playerPositionY,playGround);
            break;
        //  HACK: reveal all trap!
        case 'n':
            revealTrap(playGround,trapMap);
            break;
        }

        // clear old graphic before display the new one
        system("cls");

        // display the graphic
        display(playGround);

        // display number of traps around you
        cout << "There are "
             << countTrapAround(playerPositionX,playerPositionY,trapMap)
             << " trap around you! \n";

        // FOR DEV ONLY: DISPLAY TRAPMAP
        //         display(trapMap);

        //      checkStatus: a variable to check traped or win status
        int checkStatus = fCheckStatus(playerPositionX,playerPositionY,trapMap);

        // check on trap status
        if (checkStatus == 1) {
            cout << "You walked on a trap! \n"
                 << "GAME OVER! \n\n\n";
            break;
        }
        //check win status
        else if (checkStatus == 2) {
            cout << "You claimed the TREASURE! \n"
                 << "YOU WIN! \n"
                 << "   Visit my Github: \n"
                 << "   https://github.com/fafa26/Dungeon-Crawl-C-   \n"
                 << "Enter to play more \n";
            cin.get();
            break;
        }
    }
    display(trapMap);
    // press any key to continue...
    system("PAUSE");
    // replay
    main();
    return 0;
}
