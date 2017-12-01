#include <iostream>
//  Check Status
//  if at treasure: return 2
//  if on trap: return 1
int fCheckStatus(int x, int y, int** trapMap) {
    if ((x == 9) && (y == 9))
        return 2;
    else if (trapMap[x][y] == 1)
        return 1;
}

//  MoveUp
int moveUp(int& playerPositionX, int& playerPositionY, char** playGround) {
    //  Check if not on the top of screen
    if ( playerPositionX != 0) {
        //  Set back the soil
        playGround[playerPositionX][playerPositionY] = '.';

        //  Change player position
        playerPositionX--;

        //  Set player position to the map
        playGround[playerPositionX][playerPositionY] = 'H';
    }
}

//  MoveRight
int moveRight(int& playerPositionX, int& playerPositionY, char** playGround) {
    //  Check if not on the right of screen
    if ( playerPositionY != 9) {
        //  Set back the soil
        playGround[playerPositionX][playerPositionY] = '.';

        //  Change player position
        playerPositionY++;

        //  Set player position to the map
        playGround[playerPositionX][playerPositionY] = 'H';
    }
}

//  MoveDown
int moveDown(int& playerPositionX, int& playerPositionY, char** playGround) {
    //  Check if not on the bottom of screen
    if ( playerPositionX != 9) {
        //  Set back the soil
        playGround[playerPositionX][playerPositionY] = '.';

        //  Change player position
        playerPositionX++;

        //  Set player position to the map
        playGround[playerPositionX][playerPositionY] = 'H';
    }
}

//  MoveLeft
int moveLeft(int& playerPositionX, int& playerPositionY, char** playGround) {
    //  Check if not on the left of screen
    if ( playerPositionY != 0) {
        //  Set back the soil
        playGround[playerPositionX][playerPositionY] = '.';

        //  Change player position
        playerPositionY--;

        //  Set player position to the map
        playGround[playerPositionX][playerPositionY] = 'H';
    }
}

//  Count traps around you, but not at the corner
int countTrapAround(int x, int y, int **trapMap) {
    int trapNumber = 0;
    if (x != 0)
        trapNumber += trapMap[x-1][y];
    if (x != 9)
        trapNumber += trapMap[x+1][y];
    if (y != 0)
        trapNumber += trapMap[x][y-1];
    if (y != 9)
        trapNumber += trapMap[x][y+1];

    return trapNumber;
}

//  Display the playground
void display(char** playGround) {
    //  INTRO
    std::cout << "-------DUNGEON---CRAWL-------" << "\n\n"
              << "  Made by Noctis26 \n"
              << "  RULES: \n"
              << "  1. Use W,A,S,D to move your hero (H) \n"
              << "  2. Avoid hidden Trap! \n"
              << "  3. Claim the treasure (X) \n"
              << "      A mystery is waiting for you! \n"
              << "-----------------------------" << '\n';

    // print playground
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << ' ' << playGround[i][j];
        }
        std::cout << '\n';
    }
}

//  FOR DEVELOPER ONLY
//  DISPLAY TRAPMAP
void display(int** trapMap) {
    std::cout << "  TRAP MAP \n";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << ' ' << trapMap[i][j];
        }
        std::cout << '\n';
    }
}

//  FOR DEVELOPER ONLY
//  REVEAL TRAP!
void revealTrap(char **playGround, int **trapMap) {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            if (trapMap[i][j] == 1)
                playGround[i][j] = 'T';
        }
}
