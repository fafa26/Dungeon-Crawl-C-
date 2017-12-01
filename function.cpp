#include <iostream>
//  Check Status
int fCheckStatus(char position) {
    if (position == 'T')
        return 1;
    else if (position == 'X')
        return 2;
}

//  MoveUp
int moveUp(int& playerPositionX, int& playerPositionY, char** playGround) {
    // create next position variable
    char nextPosition;

    //  Check if not on the top of screen
    if ( playerPositionX != 0) {
        //  Set back the soil
        playGround[playerPositionX][playerPositionY] = '.';

        //  Change player position
        playerPositionX--;

        //  Check next position
        nextPosition = playGround[playerPositionX][playerPositionY];

        //  Set player position to the map
        playGround[playerPositionX][playerPositionY] = 'G';
    }
    return fCheckStatus(nextPosition);
}

//  MoveRight
int moveRight(int& playerPositionX, int& playerPositionY, char** playGround) {
    // create next position variable
    char nextPosition;

    //  Check if not on the right of screen
    if ( playerPositionY != 9) {
        //  Set back the soil
        playGround[playerPositionX][playerPositionY] = '.';

        //  Change player position
        playerPositionY++;

        //  Check next position
        nextPosition = playGround[playerPositionX][playerPositionY];

        //  Set player position to the map
        playGround[playerPositionX][playerPositionY] = 'G';
    }
    return fCheckStatus(nextPosition);
}

//  MoveDown
int moveDown(int& playerPositionX, int& playerPositionY, char** playGround) {
    // create next position variable
    char nextPosition;

    //  Check if not on the bottom of screen
    if ( playerPositionX != 9) {
        //  Set back the soil
        playGround[playerPositionX][playerPositionY] = '.';

        //  Change player position
        playerPositionX++;

        //  Check next position
        nextPosition = playGround[playerPositionX][playerPositionY];

        //  Set player position to the map
        playGround[playerPositionX][playerPositionY] = 'G';
    }
    return fCheckStatus(nextPosition);
}

//  MoveLeft
int moveLeft(int& playerPositionX, int& playerPositionY, char** playGround) {
    // create next position variable
    char nextPosition;

    //  Check if not on the left of screen
    if ( playerPositionY != 0) {
        //  Set back the soil
        playGround[playerPositionX][playerPositionY] = '.';

        //  Change player position
        playerPositionY--;

        //  Check next position
        nextPosition = playGround[playerPositionX][playerPositionY];

        //  Set player position to the map
        playGround[playerPositionX][playerPositionY] = 'G';
    }
    return fCheckStatus(nextPosition);
}

//  Display the playground
void display(char** playGround) {
    //  INTRO
    std::cout << "-------DUNGEON---CRAWL-------" << "\n\n"
              << "  RULES: \n"
              << "  1. Use W,A,S,D to move your character (G) \n"
              << "  2. Avoid Trap (T) \n"
              << "  3. Claim the treasure (X) \n"
              << "-----------------------------" << '\n';
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << ' ' << playGround[i][j];
        }
        std::cout << '\n';
    }
}
