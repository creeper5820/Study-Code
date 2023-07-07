#define AIR 0
#define SNAKE 1
#define HEAD 2
#define WALL 3
#define CANDY 4

#define LENGTH 20
#define WIDTH 20

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define SURVIVAL 0
#define DEATH 1

short int HighestScore = 0;
short int Time_Sleep = 1;

struct Snake {
  short int Body[LENGTH * WIDTH / 2][2];
  short int Direction;
  short int Length;
  short int Status;
};
typedef struct Snake Snake;

struct SnakeMap {
  short int Pixel[LENGTH][WIDTH] = { AIR };
  short int Candy[2];
};
typedef struct SnakeMap SnakeMap;

struct ThisGame {
  Snake snake;
  SnakeMap snakeMap;
};
typedef struct ThisGame ThisGame;


void Generate_Candy(SnakeMap *pSnakeMap) {
  short int X;
  short int Y;
  do {
    srand((unsigned)time(NULL));
    X = 1 + rand() % (WIDTH - 2);
    Y = 1 + rand() % (LENGTH - 2);
  } while (pSnakeMap->Pixel[X][Y] != AIR);

  pSnakeMap->Candy[0] = X;
  pSnakeMap->Candy[1] = Y;
}


void Init_Game(ThisGame *pThisGame) {
  //Initiallize the Snake
  pThisGame->snake.Status = SURVIVAL;
  pThisGame->snake.Length = 3;
  pThisGame->snake.Direction = LEFT;

  pThisGame->snake.Body[0][0] = WIDTH / 2 - 1;
  pThisGame->snake.Body[0][1] = LENGTH / 2;

  pThisGame->snake.Body[1][0] = WIDTH / 2;
  pThisGame->snake.Body[1][1] = LENGTH / 2;

  pThisGame->snake.Body[2][0] = WIDTH / 2 + 1;
  pThisGame->snake.Body[2][1] = LENGTH / 2;

  //Initiallize the Map
  Generate_Candy(&(pThisGame->snakeMap));
}



void Listen_Keyboard(ThisGame *pThisGame) {

  char key_snake = customKeypad.getKey();

  while (key_snake) {
    switch (key_snake) {
      case '2':
        if (pThisGame->snake.Body[0][1] - 1 != pThisGame->snake.Body[1][1])
          pThisGame->snake.Direction = UP;
        break;
      case '8':
        if (pThisGame->snake.Body[0][1] + 1 != pThisGame->snake.Body[1][1])
          pThisGame->snake.Direction = DOWN;
        break;
      case '4':
        if (pThisGame->snake.Body[0][0] - 1 != pThisGame->snake.Body[1][0])
          pThisGame->snake.Direction = LEFT;
        break;
      case '6':
        if (pThisGame->snake.Body[0][0] + 1 != pThisGame->snake.Body[1][0])
          pThisGame->snake.Direction = RIGHT;
        break;
      case 'A':
        pThisGame->snake.Status = DEATH;
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


void Load(ThisGame *pThisGame) {
  memset(pThisGame->snakeMap.Pixel, AIR, sizeof(pThisGame->snakeMap.Pixel));
  // Load Map
  for (int i = 0; i < LENGTH; i++)
    for (int j = 0; j < WIDTH; j++) {
      if (i == 0 || i == LENGTH - 1 || j == 0 || j == WIDTH - 1)
        pThisGame->snakeMap.Pixel[j][i] = WALL;
    }
  // Load Snake
  for (int i = 0; i < pThisGame->snake.Length; i++)
    pThisGame->snakeMap.Pixel[pThisGame->snake.Body[i][0]][pThisGame->snake.Body[i][1]] = SNAKE;
  pThisGame->snakeMap.Pixel[pThisGame->snake.Body[0][0]][pThisGame->snake.Body[0][1]] = HEAD;
  // Load Candy
  pThisGame->snakeMap.Pixel[pThisGame->snakeMap.Candy[0]][pThisGame->snakeMap.Candy[1]] = CANDY;
}


void Action(ThisGame *pThisGame) {
  int Previous[2];
  Previous[0] = pThisGame->snake.Body[0][0];
  Previous[1] = pThisGame->snake.Body[0][1];

  // Turn Head
  switch (pThisGame->snake.Direction) {
    case UP:
      pThisGame->snake.Body[0][1]--;
      break;
    case DOWN:
      pThisGame->snake.Body[0][1]++;
      break;
    case LEFT:
      pThisGame->snake.Body[0][0]--;
      break;
    case RIGHT:
      pThisGame->snake.Body[0][0]++;
      break;
    default:
      break;
  }

  // Candy
  if (pThisGame->snake.Body[0][0] == pThisGame->snakeMap.Candy[0] && pThisGame->snake.Body[0][1] == pThisGame->snakeMap.Candy[1]) {
    pThisGame->snake.Length++;
    Generate_Candy(&(pThisGame->snakeMap));
  }

  // Move
  int temp[2];
  for (int i = 1; i < pThisGame->snake.Length; i++) {
    temp[0] = pThisGame->snake.Body[i][0];
    temp[1] = pThisGame->snake.Body[i][1];
    pThisGame->snake.Body[i][0] = Previous[0];
    pThisGame->snake.Body[i][1] = Previous[1];
    Previous[0] = temp[0];
    Previous[1] = temp[1];
  }

  // Die
  if (pThisGame->snakeMap.Pixel[pThisGame->snake.Body[0][0]][pThisGame->snake.Body[0][1]] == WALL || pThisGame->snakeMap.Pixel[pThisGame->snake.Body[0][0]][pThisGame->snake.Body[0][1]] == SNAKE)
    pThisGame->snake.Status = DEATH;
  Serial.print("The Status is");
  Serial.println(pThisGame->snake.Status);
}


void Refresh_Snake(ThisGame *pThisGame) {
  u8g2.firstPage();
  do {
    // Print the map
    u8g2.drawFrame(0, 0, WIDTH * 2, LENGTH * 2);
    u8g2.drawFrame(1, 1, WIDTH * 2 - 2, LENGTH * 2 - 2);
    // Print the snake
    for (int i = 0; i < pThisGame->snake.Length; i++) {
      u8g2.drawPixel(pThisGame->snake.Body[i][0] * 2, pThisGame->snake.Body[i][1] * 2);
      u8g2.drawPixel(pThisGame->snake.Body[i][0] * 2 - 1, pThisGame->snake.Body[i][1] * 2 - 1);
      u8g2.drawPixel(pThisGame->snake.Body[i][0] * 2 - 1, pThisGame->snake.Body[i][1] * 2);
      u8g2.drawPixel(pThisGame->snake.Body[i][0] * 2, pThisGame->snake.Body[i][1] * 2 - 1);
    }
    // Print the candy
    u8g2.drawPixel(pThisGame->snakeMap.Candy[0] * 2, pThisGame->snakeMap.Candy[1] * 2);
    u8g2.drawPixel(pThisGame->snakeMap.Candy[0] * 2 - 1, pThisGame->snakeMap.Candy[1] * 2 - 1);
    u8g2.drawPixel(pThisGame->snakeMap.Candy[0] * 2 - 1, pThisGame->snakeMap.Candy[1] * 2);
    u8g2.drawPixel(pThisGame->snakeMap.Candy[0] * 2, pThisGame->snakeMap.Candy[1] * 2 - 1);
    // Print the score
    u8g2.drawFrame(WIDTH * 2, 0, WIDTH * 2, LENGTH * 2);
    char Score[5];
    std::sprintf(Score, "%d", pThisGame->snake.Length);
    u8g2.drawStr(WIDTH * 2 + 5, 15, Score);

  } while (u8g2.nextPage());
}

bool Is_dead(ThisGame *pThisGame) {

  if (pThisGame->snake.Status == DEATH) {
    char ch_Death = customKeypad.getKey();
    if (pThisGame->snake.Length > HighestScore)
      HighestScore = pThisGame->snake.Length;
    u8g2.clear();

    while (!ch_Death) {
      u8g2.firstPage();
      do {
        u8g2.setCursor(5, 20);
        ch_Death = customKeypad.getKey();
        u8g2.print("YOU DEAD!!");
        delay(10);
      } while (u8g2.nextPage());
    }
    return DEATH;
  }

  return SURVIVAL;
}

void Run_Snake() {
  // Setup basic data
  Snake creeper;
  SnakeMap creeperMap;
  ThisGame Game;
  Game.snake = creeper;
  Game.snakeMap = creeperMap;
  // Initiallize the game
  Init_Game(&Game);

  Serial.println("The Game is initiallized successfully!");
  // Game loop
  Load(&Game);

  Serial.println("The first initiallizing successfully!");

  int count = 0;

  while (creeper.Status != DEATH) {

    delay(10);
    Listen_Keyboard(&Game);

    count++;
    if (count > Time_Sleep) {

      Serial.println("A loop of game");

      Load(&Game);
      Action(&Game);
      if (Is_dead(&Game) == DEATH)
        return;
      Refresh_Snake(&Game);
      count = 0;
    }
  }
}
