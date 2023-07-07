#line 1 "D:\\Git\\CodeLearning\\Projects\\SmartEsp8266\\Smart\\_Snake.h"
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

int Score[10] = { 0 };
int Time_Sleep = 1;

struct Snake {
  int Body[LENGTH * WIDTH][2];
  int Direction;
  int Length;
  int Status;
};
typedef struct Snake Snake;

struct SnakeMap{
  int Pixel[LENGTH][WIDTH] = { AIR };
  int Candy[2];
};
typedef struct SnakeMap SnakeMap;

struct ThisGame

void Init_Snake(Snake *pSnake) {

  pSnake->Status = SURVIVAL;
  pSnake->Length = 3;
  pSnake->Direction = LEFT;

  pSnake->Body[0][0] = WIDTH / 2 - 1;
  pSnake->Body[0][1] = LENGTH / 2;

  pSnake->Body[1][0] = WIDTH / 2;
  pSnake->Body[1][1] = LENGTH / 2;

  pSnake->Body[2][0] = WIDTH / 2 + 1;
  pSnake->Body[2][1] = LENGTH / 2;
}


void Generate_Candy(const int Pixel[LENGTH][WIDTH], int *ptr_Candy[2]) {
  int X;
  int Y;
  do {
    srand((unsigned)time(NULL));
    X = 1 + rand() % (WIDTH - 2);
    Y = 1 + rand() % (LENGTH - 2);
  } while (Pixel[X][Y] != AIR);

  *ptr_Candy[0] = X;
  *ptr_Candy[1] = Y;
}


void Listen_Keyboard(const int Snake[LENGTH * WIDTH][2], int *ptr_Status, int *ptr_Direction) {

  char key_snake = customKeypad.getKey();

  while (key_snake) {
    switch (key_snake) {
      case '2':
        if (*ptr_Snake[0][1] - 1 != *ptr_Snake[1][1])
          *ptr_Direction = UP;
        break;
      case '8':
        if (*ptr_Snake[0][1] + 1 != *ptr_Snake[1][1])
          Direction = DOWN;
        break;
      case '4':
        if (*ptr_Snake[0][0] - 1 != *ptr_Snake[1][0])
          Direction = LEFT;
        break;
      case '6':
        if (*ptr_Snake[0][0] + 1 != *ptr_Snake[1][0])
          Direction = RIGHT;
        break;
      case 'A':
        *ptr_Status = DEATH;
        break;
      case 'B':
        char ch = customKeypad.getKey();
        ch = 0;
        while (!ch) {
          ch = customKeypad.getKey();
          delay(100);
        }
        break;
    }
    key_snake = 0;
  }
}


void Load(int *ptr_Pixel[LENGTH][WIDTH], const int Snake[LENGTH * WIDTH][2], const int Candy[2]) {
  memset((*ptr_Pixel), AIR, sizeof((*ptr_Pixel)));
  //Load Map
  for (int i = 0; i < LENGTH; i++)
    for (int j = 0; j < WIDTH; j++) {
      if (i == 0 || i == LENGTH - 1 || j == 0 || j == WIDTH - 1)
        *ptr_Pixel[j][i] = WALL;
    }
  // Load Snake
  for (int i = 0; i < Length; i++)
    *ptr_Pixel[Snake[i][0]][Snake[i][1]] = SNAKE;
  *ptr_Pixel[Snake[0][0]][Snake[0][1]] = HEAD;
  // Load Candy
  *ptr_Pixel[Candy[0]][Candy[1]] = CANDY;
}


void Action(int *ptr_Snake[LENGTH * WIDTH][2], int *ptr_Candy[2], int *ptr_Length, const int Direction, const int Pixel[LENGTH][WIDTH]) {
  int Previous[2];
  Previous[0] = *ptr_Snake[0][0];
  Previous[1] = *ptr_Snake[0][1];

  //Turn Head
  switch (Direction) {
    case UP:
      *ptr_Snake[0][1]--;
      break;
    case DOWN:
      *ptr_Snake[0][1]++;
      break;
    case LEFT:
      *ptr_Snake[0][0]--;
      break;
    case RIGHT:
      *ptr_Snake[0][0]++;
      break;
    default:
      break;
  }

  //Candy
  if (*ptr_Snake[0][0] == *ptr_Candy[0] && *ptr_Snake[0][1] == *ptr_Candy[1]) {
    *ptr_Length++;
    Generate_Candy(Pixel, ptr_Candy);
  }

  // Move
  int temp[2];
  for (int i = 1; i < *ptr_Length; i++) {
    temp[0] = *ptr_Snake[i][0];
    temp[1] = *ptr_Snake[i][1];
    *ptr_Snake[i][0] = Previous[0];
    *ptr_Snake[i][1] = Previous[1];
    Previous[0] = temp[0];
    Previous[1] = temp[1];
  }

  // Die
  if (Pixel[*ptr_Snake[0][0]][*ptr_Snake[0][1]] == WALL || Pixel[*ptr_Snake[0][0]][*ptr_Snake[0][1]] == SNAKE)
    Status = DEATH;
}

void Refresh_Snake(const int Snake[][2], const int Candy[]) {
  u8g2.firstPage();
  do {
    //Print the map
    for (int i = 0; i < LENGTH; i++) {
      if (i == 0 || i == LENGTH - 1) {
        for (int j = 0; j < WIDTH; j++) {
          u8g2.drawPixel(j * 2, i * 2);
          u8g2.drawPixel(j * 2 - 1, i * 2 - 1);
          u8g2.drawPixel(j * 2 - 1, i * 2);
          u8g2.drawPixel(j * 2, i * 2 - 1);
        }
      } else {
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
    //Print the snak
    for (int i = 0; i < Length; i++) {
      u8g2.drawPixel(Snake[i][0] * 2, Snake[i][1] * 2);
      u8g2.drawPixel(Snake[i][0] * 2 - 1, Snake[i][1] * 2 - 1);
      u8g2.drawPixel(Snake[i][0] * 2 - 1, Snake[i][1] * 2);
      u8g2.drawPixel(Snake[i][0] * 2, Snake[i][1] * 2 - 1);
    }
    //Print the candy
    u8g2.drawPixel(Candy[0] * 2, Candy[1] * 2);
    u8g2.drawPixel(Candy[0] * 2 - 1, Candy[1] * 2 - 1);
    u8g2.drawPixel(Candy[0] * 2 - 1, Candy[1] * 2);
    u8g2.drawPixel(Candy[0] * 2, Candy[1] * 2 - 1);
    //Print the score
    char Score[5];
    std::sprintf(Score, "%d", Length);
    u8g2.drawStr(80, 15, Score);

  } while (u8g2.nextPage());
}


void Is_dead(int *ptr_Status) {

  if (*ptr_Status == DEATH) {
    char ch_Death = customKeypad.getKey();
    u8g2.clearBuffer();

    while (!ch_Death) {
      u8g2.setCursor(5, 20);
      ch_Death = customKeypad.getKey();
      u8g2.print("YOU DEAD!!");
      delay(10);
    }
    *ptr_Status = SURVIVAL;
  }
}


void Run_Snake() {
  //Setup basic data
  Map Map;
  Snake Creeper;
  //Initiallize the game
  Init_Snake(&Snake, &Status, &Length, &Direction);
  Generate_Candy(&Pixel, &Candy);

  //Game loop
  Load(&Pixel, Snake, Candy);
  int count = 0;

  while (Status != DEATH) {
    delay(10);
    Listen_Keyboard(&Snake, &Status, &Direction);

    count++;
    if (count > Time_Sleep) {
      Load(&Pixel, Snake, Candy);
      Action();
      Is_dead(&Status);
      Refresh_Snake(Snake, Candy);
      count = 0;
    }
  }
}
