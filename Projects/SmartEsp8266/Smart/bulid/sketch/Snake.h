#line 1 "D:\\Git\\CodeLearning\\Projects\\SmartEsp8266\\Smart\\Snake.h"
#define AIR 0
#define SNAKE 1
#define HEAD 2
#define WALL 3
#define CANDY 4

#define LENGTH 32
#define WIDTH 32

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define SURVIVAL 0
#define DEATH 1

short int Score[10] = {0};
short int Time_Sleep = 1;

struct Snake
{
    short int Body[LENGTH * WIDTH / 2][2];
    short int Direction;
    short int Length;
    short int Status;
};
typedef struct Snake Snake;

struct SnakeMap
{
    short int Pixel[LENGTH][WIDTH] = {AIR};
    short int Candy[2];
};
typedef struct SnakeMap SnakeMap;

struct ThisGame
{
    Snake Snake;
    SnakeMap SnakeMap;
} typedef struct ThisGame ThisGame;


void Generate_Candy(SnakeMap *pSnakeMap)
{
    short int X;
    short int Y;
    do
    {
        srand((unsigned)time(NULL));
        X = 1 + rand() % (WIDTH - 2);
        Y = 1 + rand() % (LENGTH - 2);
    } while (pSnakeMap->Pixel[X][Y] != AIR);

    pSnakeMap.Candy[0] = X;
    pSnakeMap.Candy[1] = Y;
}


void Init_Game(ThisGame *pThisGame)
{
    //Initiallize the Snake
    pThisGame->Snake.Status = SURVIVAL;
    pThisGame->Snake.Length = 3;
    pThisGame->Snake.Direction = LEFT;

    pThisGame->Snake.Body[0][0] = WIDTH / 2 - 1;
    pThisGame->Snake.Body[0][1] = LENGTH / 2;

    pThisGame->Snake.Body[1][0] = WIDTH / 2;
    pThisGame->Snake.Body[1][1] = LENGTH / 2;

    pThisGame->Snake.Body[2][0] = WIDTH / 2 + 1;
    pThisGame->Snake.Body[2][1] = LENGTH / 2;

    //Initiallize the Map
    Generate_Candy(&(pThisGame->SnakeMap));
}



void Listen_Keyboard(ThisGame *pThisGame)
{

    char key_snake = customKeypad.getKey();

    while (key_snake)
    {
        switch (key_snake)
        {
        case '2':
            if (pThisGame->Snake.Body[0][1] - 1 != pThisGame->Snake.Body[1][1])
                pThisGame->Snake.Direction = UP;
            break;
        case '8':
            if (pThisGame->Snake.Body[0][1] + 1 != pThisGame->Snake.Body[1][1])
                pThisGame->Snake.Direction = DOWN;
            break;
        case '4':
            if (pThisGame->Snake.Body[0][0] - 1 != pThisGame->Snake.Body[1][0])
                pThisGame->Snake.Direction = LEFT;
            break;
        case '6':
            if (pThisGame->Snake.Body[0][0] + 1 != pThisGame->Snake.Body[1][0])
                pThisGame->Snake.Direction = RIGHT;
            break;
        case 'A':
            pThisGame->Snake.Status = DEATH;
            break;
        case 'B':
            char ch = customKeypad.getKey();
            ch = 0;
            while (!ch)
            {
                ch = customKeypad.getKey();
                delay(100);
            }
            break;
        }
        key_snake = 0;
    }
}

void Load(ThisGame *pThisGame)
{
    memset(pThisGame->SnakeMap.Pixel, AIR, pThisGame->SnakeMap.Pixel);
    // Load Map
    u8g2.drawFrame(0, 0, WIDTH, LENGTH);
    u8g2.drawFrame(1, 1, WIDTH - 2, LENGTH - 2);
    // Load Snake
    for (int i = 0; i < pThisGame->Snake.Length; i++)
        pThisGame->SnakeMap.Pixel[pThisGame->Snake.Body[i][0]][pThisGame->Snake.Body[i][1]] = SNAKE;
    pThisGame->SnakeMap.Pixel[pThisGame->Snake.Body[0][0]][pThisGame->Snake.Body[0][1]] = HEAD;
    // Load Candy
    pThisGame->SnakeMap.Pixel[pThisGame->SnakeMap.Candy[0]][pThisGame->SnakeMap.Candy[1]] = CANDY;
}

void Action(ThisGame *pThisGame)
{
    int Previous[2];
    Previous[0] = pThisGame->Snake.Body[0][0];
    Previous[1] = pThisGame->Snake.Body[0][1];

    // Turn Head
    switch (Direction)
    {
    case UP:
        pThisGame->Snake.Body[0][1]--;
        break;
    case DOWN:
        pThisGame->Snake.Body[0][1]++;
        break;
    case LEFT:
        pThisGame->Snake.Body[0][0]--;
        break;
    case RIGHT:
        pThisGame->Snake.Body[0][0]++;
        break;
    default:
        break;
    }

    // Candy
    if (pThisGame->Snake.Body[0][0] == pThisGame->SnakeMap.Candy[0] && pThisGame->Snake.Body[0][1] == pThisGame->SnakeMap.Candy[1])
    {
        pThisGame->Snake.Length++;
        Generate_Candy(&(pThisGame->SnakeMap));
    }

    // Move
    int temp[2];
    for (int i = 1; i < pThisGame->Snake.Length; i++)
    {
        temp[0] = pThisGame->Snake.Body[i][0];
        temp[1] = pThisGame->Snake.Body[i][1];
        pThisGame->Snake.Body[i][0] = Previous[0];
        pThisGame->Snake.Body[i][1] = Previous[1];
        Previous[0] = temp[0];
        Previous[1] = temp[1];
    }

    // Die
    if (pThisGame->SnakeMap.Pixel[pThisGame->Snake.Body[0][0]][pThisGame->Snake.Body[0][1]] == WALL || pThisGame->SnakeMap.Pixel[pThisGame->Snake.Body[0][0]][pThisGame->Snake.Body[0][1]] == SNAKE)
        pThisGame->Snake.Status = DEATH;
}

void Refresh_Snake(ThisGame *pThisGame)
{
    u8g2.firstPage();
    do
    {
        // Print the map
        for (int i = 0; i < LENGTH; i++)
        {
            if (i == 0 || i == LENGTH - 1)
            {
                for (int j = 0; j < WIDTH; j++)
                {
                    u8g2.drawPixel(j * 2, i * 2);
                    u8g2.drawPixel(j * 2 - 1, i * 2 - 1);
                    u8g2.drawPixel(j * 2 - 1, i * 2);
                    u8g2.drawPixel(j * 2, i * 2 - 1);
                }
            }
            else
            {
                u8g2.drawPixel(0, i * 2);
                u8g2.drawPixel(0 - 1, i * 2 - 1);
                u8g2.drawPixel(0, i * 2 - 1);
                u8g2.drawPixel(0 - 1, i * 2);

                u8g2.drawPixel((WIDTH - 1) * 2, i * 2);
                u8g2.drawPixel((WIDTH - 1) * 2 - 1, i * 2 - 1);
                u8g2.drawPixel((WIDTH - 1) * 2 - 1, i * 2);
                u8g2.drawPixel((WIDTH - 1) * 2, i * 2 - 1);
            }
        }
        // Print the snak
        for (int i = 0; i < pThisGame->Snake.Length; i++)
        {
            u8g2.drawPixel(pThisGame->Snake.Body[i][0] * 2, pThisGame->Snake.Body[i][1] * 2);
            u8g2.drawPixel(pThisGame->Snake.Body[i][0] * 2 - 1, pThisGame->Snake.Body[i][1] * 2 - 1);
            u8g2.drawPixel(pThisGame->Snake.Body[i][0] * 2 - 1, pThisGame->Snake.Body[i][1] * 2);
            u8g2.drawPixel(pThisGame->Snake.Body[i][0] * 2, pThisGame->Snake.Body[i][1] * 2 - 1);
        }
        // Print the candy
        u8g2.drawPixel(pThisGame->SnakeMap.Candy[0] * 2, pThisGame->SnakeMap.Candy[1] * 2);
        u8g2.drawPixel(pThisGame->SnakeMap.Candy[0] * 2 - 1, pThisGame->SnakeMap.Candy[1] * 2 - 1);
        u8g2.drawPixel(pThisGame->SnakeMap.Candy[0] * 2 - 1, pThisGame->SnakeMap.Candy[1] * 2);
        u8g2.drawPixel(pThisGame->SnakeMap.Candy[0] * 2, pThisGame->SnakeMap.Candy[1] * 2 - 1);
        // Print the score
        char Score[5];
        std::sprintf(Score, "%d", pThisGame->Snake.Length);
        u8g2.drawStr(80, 15, Score);

    } while (u8g2.nextPage());
}

void Is_dead(ThisGame *pThisGame)
{

    if (pThisGame->Snake.Status == DEATH)
    {
        char ch_Death = customKeypad.getKey();
        u8g2.clearBuffer();

        while (!ch_Death)
        {
            u8g2.setCursor(5, 20);
            ch_Death = customKeypad.getKey();
            u8g2.print("YOU DEAD!!");
            delay(10);
        }
        pThisGame->Snake.Status = SURVIVAL;
    }
}

void Run_Snake()
{
    // Setup basic data
    Snake Creeper;
    SnakeMap CreeperMap;
    ThisGame Game{CreeperMap, Creeper};
    // Initiallize the game
    Init_Game(&Game);

    // Game loop
    Load(&Game);
    int count = 0;

    while (Status != DEATH)
    {
        delay(10);
        Listen_Keyboard(&Game);

        count++;
        if (count > Time_Sleep)
        {
            Load(&Game);
            Action(&Game);
            Is_dead(&Game);
            Refresh_Snake(&Game);
            count = 0;
        }
    }
}
