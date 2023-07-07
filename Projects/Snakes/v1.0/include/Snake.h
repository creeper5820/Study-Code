/*
1. The message of snake
2. The refresh of map

SNAKE
    body[]
    1 coordinate + 2 coordinate * 100 = body[]
    1 and 0 to represent the body length
    mark the coordinates
    Max length exit
FOOD
    candy
    stone

MAP
    map[][]
    1 block = 1 pixel

LOOP
    getch
        chect ch, ch == 1 | 2 | 3 | 4 , turn
        ch == 0, keep direction
        end of loop, ch = 0

    QUESTION: how getchar and move work together

    direction
        getchar to modify the first body
        others folow the next
    eat food and react
        food[] == body[0], body[length] = body[length - 1]
        contory to the direction
        judge the wall ,the next body, the food

        slow speed
        accelerate speed
        lengthen body
        shorten body

    sleep 
        sleep accroding to the level
*/
#pragma once

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define AIR 0
#define SNAKE 1
#define HEAD 2
#define WALL 3
#define CANDY 4

#define LENGTH 22
#define WIDTH 22

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define Survival 0
#define Death 1

int Map[LENGTH][WIDTH];
int Pixel[LENGTH][WIDTH];
int Snake[LENGTH * WIDTH][2];
int Candy[2];
//The Status of Snake
int Direction;
double Time_Sleep;
int Level;
int Length;
int Status;

void delay(double number_of_seconds);
void Init_Map();
void Generate_Candy();
void Listen_Keyboard();
void Action();
void Refresh();

void Run();