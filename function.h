//  This file contains prototypes of all
//  functions in function.cpp file

int moveUp   (int& playerPositionX, int& playerPositionY, char** playGround);
int moveDown (int& playerPositionX, int& playerPositionY, char** playGround);
int moveLeft (int& playerPositionX, int& playerPositionY, char** playGround);
int moveRight(int& playerPositionX, int& playerPositionY, char** playGround);
int display(char** playGround);
int fCheckStatus(int x, int y, int** trapMap);
int countTrapAround(int x, int y, int **trapMap);
void display(int** trapMap);
void revealTrap(char **playGround, int **trapMap);
