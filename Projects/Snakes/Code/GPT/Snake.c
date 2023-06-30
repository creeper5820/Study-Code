#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 80
#define HEIGHT 25

int gameOver;
int playerX, playerY;
int bulletX, bulletY;
int enemyX, enemyY;
int score;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Setup()
{
    gameOver = 0;
    playerX = WIDTH / 2;
    playerY = HEIGHT - 1;
    bulletX = -1;
    bulletY = -1;
    enemyX = rand() % WIDTH;
    enemyY = 0;
    score = 0;
}

void Draw()
{
    system("cls"); // 清空控制台

    gotoxy(playerX, playerY);
    printf("^");

    if (bulletY != -1)
    {
        gotoxy(bulletX, bulletY);
        printf("|");
    }

    gotoxy(enemyX, enemyY);
    printf("*");

    gotoxy(0, HEIGHT);
    printf("Score: %d", score);
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            if (playerX > 0)
                playerX--;
            break;
        case 'd':
            if (playerX < WIDTH - 1)
                playerX++;
            break;
        case 'w':
            if (bulletY == -1)
            {
                bulletX = playerX;
                bulletY = playerY - 1;
            }
            break;
        case 'x':
            gameOver = 1;
            break;
        }
    }
}

void Logic()
{
    if (bulletY != -1)
    {
        bulletY--;

        if (bulletY == enemyY && bulletX == enemyX)
        {
            score++;
            bulletY = -1;
            enemyX = rand() % WIDTH;
            enemyY = 0;
        }
    }

    if (enemyY == playerY && enemyX == playerX)
        gameOver = 1;

    enemyY++;

    if (enemyY >= HEIGHT)
    {
        gameOver = 1;
        printf("\nGame Over!\nYour Score: %d\n", score);
    }
}

int main()
{
    Setup();

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(50); // 设置时间间隔，控制游戏速度
    }

    return 0;
}
