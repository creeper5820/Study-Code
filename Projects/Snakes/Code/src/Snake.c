#include "Snake.h"

void delay(double number_of_seconds)
{
    double milli_seconds = 1000.0 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}
void Init_Map()
{
    for (int i = 0; i < LENGTH; i++)
        for (int j = 0; j < WIDTH; j++)
        {
            if (i == 0 || i == LENGTH - 1 || j == 0 || j == WIDTH - 1)
                Map[j][i] = WALL;
        }

    Status = Survival;
    Length = 3;
    Direction = LEFT;
    Level = 1;
    Time_Sleep = 0.3;

    Snake[0][0] = WIDTH / 2 - 1;
    Snake[0][1] = LENGTH / 2;

    Snake[1][0] = WIDTH / 2;
    Snake[1][1] = LENGTH / 2;

    Snake[2][0] = WIDTH / 2 + 1;
    Snake[2][1] = LENGTH / 2;
}
void Generate_Candy()
{
    int X;
    int Y;
    do
    {
        srand((unsigned)time(NULL));
        X = 1 + rand() % (WIDTH - 2);
        Y = 1 + rand() % (LENGTH - 2);
    } while (Map[X][Y] != AIR);

    Candy[0] = X;
    Candy[1] = Y;
}
void Listen_Keyboard()
{
    char ch;
    if (_kbhit())
    {
        ch = getch();

        if (ch == '0')
        {
            Status = Death;
            return;
        }
        if (ch == '1')
        {
            getch();
            return;
        }

        if (ch == -32)
        {
            ch = getch();
            switch (ch)
            {
            case 72: // UP
                if (Snake[0][1] - 1 != Snake[1][1])
                    Direction = UP;
                break;
            case 80: // DOWN
                if (Snake[0][1] + 1 != Snake[1][1])
                    Direction = DOWN;
                break;
            case 75: // LEFT
                if (Snake[0][0] - 1 != Snake[1][0])
                    Direction = LEFT;
                break;
            case 77: // RIGHT
                if (Snake[0][0] + 1 != Snake[1][0])
                    Direction = RIGHT;
                break;
            default:
                break;
            }
        while (kbhit())
            getch();
        }
        
    }
}
void Action()
{
    int Previous[2];
    Previous[0] = Snake[0][0];
    Previous[1] = Snake[0][1];
    //---- Load Map
    for (int i = 0; i < LENGTH; i++)
        for (int j = 0; j < WIDTH; j++)
        {
        Pixel[j][i] = AIR;
        Pixel[j][i] = Map[j][i];
        }
    // Load Snake
    for (int i = 0; i < Length; i++)
        Pixel[Snake[i][0]][Snake[i][1]] = SNAKE;
    Pixel[Snake[0][0]][Snake[0][1]] = HEAD;
    // Load Candy
    Pixel[Candy[0]][Candy[1]] = CANDY;
    
    //----Turn Head
    switch (Direction)
    {
    case UP:
        Snake[0][1]--;
        break;
    case DOWN:
        Snake[0][1]++;
        break;
    case LEFT:
        Snake[0][0]--;
        break;
    case RIGHT:
        Snake[0][0]++;
        break;
    default:
        break;
    }

    //----Candy
    if (Snake[0][0] == Candy[0] && Snake[0][1] == Candy[1])
    {
        Length++;
        Generate_Candy();
    }

    // Move
    int temp[2];
    for (int i = 1; i < Length; i++)
    {
        temp[0] = Snake[i][0];
        temp[1] = Snake[i][1];
        Snake[i][0] = Previous[0];
        Snake[i][1] = Previous[1];
        Previous[0] = temp[0];
        Previous[1] = temp[1];
    }

    // Die
    if (Pixel[Snake[0][0]][Snake[0][1]] == WALL || Pixel[Snake[0][0]][Snake[0][1]] == SNAKE)
        Status = Death;

    // Load Snake
    for (int i = 0; i < Length; i++)
        Pixel[Snake[i][0]][Snake[i][1]] = SNAKE;
    Pixel[Snake[0][0]][Snake[0][1]] = HEAD;
}
void Refresh()
{
    printf("\033[H");
    for (int i = 0; i < LENGTH; i++)
        for (int j = 0; j < WIDTH; j++)
        {

            switch (Pixel[j][i])
            {
            case AIR:
            {
                printf("\033[40m  \033[0m");
                break;
            }
            case WALL:
            {
                printf("\033[47m  \033[0m");
                break;
            }
            case SNAKE:
            {
                printf("\033[47m  \033[0m");
                break;
            }
            case HEAD:
            {
                printf("\033[41m  \033[0m");
                break;
            }
            case CANDY:
            {
                printf("\033[41m  \033[0m");
                break;
            }
            default:
            {
                break;
            }
            }
            if (j == WIDTH - 1)
                printf("\n");
        }
}
void Run()
{
    while (1)
    {
        delay(Time_Sleep);
        Listen_Keyboard();
        Action();
        Refresh();
        if (Status == Death)
        {
            printf("\033[%d;%dH YOU DEAD ", LENGTH / 2, WIDTH);
            return;
        }
    }
}