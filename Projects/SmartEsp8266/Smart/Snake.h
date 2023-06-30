#define AIR 0
#define SNAKE 1
#define HEAD 2
#define WALL 3
#define CANDY 4

#define LENGTH 30
#define WIDTH 30

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define SURVIVAL 0
#define DEATH 1

int Map[LENGTH][WIDTH];
int Pixel[LENGTH][WIDTH];
int Snake[LENGTH * WIDTH][2];
int Candy[2];
// The Status of Snake
int Direction;
int Time_Sleep = 1;
int Level;
int Length;
int Status;

void Init_Map()
{
    for (int i = 0; i < LENGTH; i++)
        for (int j = 0; j < WIDTH; j++)
        {
            if (i == 0 || i == LENGTH - 1 || j == 0 || j == WIDTH - 1)
                Map[j][i] = WALL;
        }

    Status = SURVIVAL;
    Length = 3;
    Direction = LEFT;
    Level = 1;

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
    char key_snake = customKeypad.getKey();
    while (key_snake)
    {
        Serial.println(key_snake);
        switch (key_snake)
        {
        case 'U':
            if (Snake[0][1] - 1 != Snake[1][1])
                Direction = UP;
            break;
        case 'D':
            if (Snake[0][1] + 1 != Snake[1][1])
                Direction = DOWN;
            break;
        case 'L':
            if (Snake[0][0] - 1 != Snake[1][0])
                Direction = LEFT;
            break;
        case 'R':
            if (Snake[0][0] + 1 != Snake[1][0])
                Direction = RIGHT;
            break;
        case '1':
            Status = DEATH;
            break;
        case '2':
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
void Load()
{
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
}
void Action()
{
    int Previous[2];
    Previous[0] = Snake[0][0];
    Previous[1] = Snake[0][1];

    Load();

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
        Status = DEATH;

    Load();
}

void Refresh_Snake()
{
    u8g2.firstPage();
    do
    {
        for (int i = 0; i < LENGTH; i++)
        {
            if (i == 0 || i == LENGTH - 1)
            {
                for (int j = 0; j < WIDTH; j++)
                {
                    u8g2.drawPixel(j * 2, i * 2);
                    u8g2.drawPixel(j * 2 -1, i * 2 -1);
                    u8g2.drawPixel(j * 2 -1, i * 2);
                    u8g2.drawPixel(j * 2, i * 2 -1);
                }
            }
            else
            {
                u8g2.drawPixel(0, i*2);
                u8g2.drawPixel(0 -1, i*2 -1);
                u8g2.drawPixel(0, i*2 -1);
                u8g2.drawPixel(0 -1, i*2);

                u8g2.drawPixel((WIDTH - 1)*2, i*2);
                u8g2.drawPixel((WIDTH - 1)*2 -1, i*2 -1);
                u8g2.drawPixel((WIDTH - 1)*2 -1, i*2);
                u8g2.drawPixel((WIDTH - 1)*2, i*2 -1);
            }
        }

        for (int i = 0; i < Length; i++)
        {
            u8g2.drawPixel(Snake[i][0] * 2, Snake[i][1] * 2);
            u8g2.drawPixel(Snake[i][0] * 2 -1, Snake[i][1] * 2 -1);
            u8g2.drawPixel(Snake[i][0] * 2 -1, Snake[i][1] * 2);
            u8g2.drawPixel(Snake[i][0] * 2, Snake[i][1] * 2 -1);
        }

        u8g2.drawPixel(Candy[0]*2, Candy[1]*2);
        u8g2.drawPixel(Candy[0]*2 -1, Candy[1]*2 -1);
        u8g2.drawPixel(Candy[0]*2 -1, Candy[1]*2);
        u8g2.drawPixel(Candy[0]*2, Candy[1]*2 -1);

        char Score[5];
        std::sprintf(Score, "%d", Length);
        u8g2.drawStr(80, 15, Score);

    } while (u8g2.nextPage());
}

void Run_Snake()
{
    Load();
    int count = 0;
    while (Status != DEATH)
    {
        delay(10);

        Listen_Keyboard();

        count++;
        if (count > Time_Sleep)
        {
            Action();
            count = 0;

            if (Status == DEATH)
            {
                char ch_Death = customKeypad.getKey();

                while (!ch_Death)
                {
                    u8g2.setCursor(5, 20);
                    ch_Death = customKeypad.getKey();
                    u8g2.print("YOU DEAD!!");
                    delay(10);
                }
                Status = SURVIVAL;
                return;
            }
        }

        Refresh_Snake();
    }
}
