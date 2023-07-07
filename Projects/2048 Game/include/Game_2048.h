#include <stdio.h>
#include <conio.h>

/*
the game called 2048

The Map
    4*4

The Operations
    up down left right
    judge the blocks
*/

struct ThisGame
{
    short int Map[4][4];
};
typedef struct ThisGame ThisGame;

short int License_KeyPad();
void Init_Game(ThisGame game);
void Operation(ThisGame game, short int operation);
void Refresh(ThisGame game);