#include <stdio.h>
#include <string>
#include <Keypad.h>
#include <U8g2lib.h>
#include <Arduino.h>
#include <time.h>

#include "Support.h"
#include "Menu.h"
#include "Snake.h"

void Function() /*Modify this to add your function*/
{
  switch (Current_pNode->pMenu->Number_Function[Current_pNode->Current_Selection])
  {
  case 0:
  {
    break;
  }
  case 1:
  {
    Current_pNode = Current_pNode->Next[Current_pNode->pMenu->Num_Function[Current_pNode->Current_Selection]];
    break;
  }
  case 2:
  {
    Current_pNode = Current_pNode->Last;
    break;
  }
  case 3:
  {
    Init_Map();
    Generate_Candy();
    Run_Snake();
    break;
  }
  case 4:
  {
    Time_Sleep = Current_pNode->pMenu->Num_Function[Current_pNode->Current_Selection];
    char ch = customKeypad.getKey();
    ch = 0;
    while (!ch)
    {
      u8g2.firstPage();
      do
      {
        u8g2.drawStr(0, 30, "OKKK!");
        ch = customKeypad.getKey();
        delay(10);
      } while (u8g2.nextPage());
    }
    Current_pNode = Current_pNode->Last;
    break;
  }
  default:
  {
    break;
  }
  }
}

void setup()
{
  Init();

  Node *Main = New_Node();
  Set_Name(Main, "Game Box");
  Set_Message(Main, "2023 Creeper");
  Set_Number_Selection(Main, 2);
  Set_Selection(Main, "Snakes", 0, 1, 0);
  Set_Selection(Main, "exit", 1, 0, 0);

  Node *SubMain_1 = New_Node();
  Set_Name(SubMain_1, "SNAKES");
  Set_Message(SubMain_1, "Let us begin to play this game!");
  Set_Number_Selection(SubMain_1, 3);
  Set_Selection(SubMain_1, "Play now", 0, 3, 0);
  Set_Selection(SubMain_1, "Set Level", 1, 1, 0);
  Set_Selection(SubMain_1, "back", 2, 2, 0);

  Node *SubMain_1_1 = New_Node();
  Set_Name(SubMain_1_1, "LEVEL");
  Set_Message(SubMain_1_1, "Choose your level");
  Set_Number_Selection(SubMain_1_1, 3);
  Set_Selection(SubMain_1_1, "Hard", 0, 4, 3);
  Set_Selection(SubMain_1_1, "Mid", 1, 4, 7);
  Set_Selection(SubMain_1_1, "Easy", 2, 4, 12);

  Connect_Node(Main, SubMain_1, 0);
  Connect_Node(SubMain_1, SubMain_1_1, 0);

  Current_pNode = Main;

  Serial.begin(115200);
  u8g2.begin();
  u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_unifont_t_symbols);

  u8g2.clearBuffer();
  Init_Map();
  Generate_Candy();
}

void loop()
{
  u8g2.firstPage();
  do
  {
    Refresh();

    char key = customKeypad.getKey();

    while (key)
    {
      Serial.println(key);
      switch (key)
      {
      case 'U':
      {
        Current_pNode->Current_Selection--;
        if (Current_pNode->Current_Selection + 1 < 1)
          Current_pNode->Current_Selection = Current_pNode->pMenu->Number_Selection - 1;
        break;
      }
      case 'D':
      {
        Current_pNode->Current_Selection++;
        if (Current_pNode->Current_Selection + 1 > Current_pNode->pMenu->Number_Selection)
          Current_pNode->Current_Selection = 0;
        break;
      }
      case 'L':

        break;
      case 'R':

        break;
      case '1':
        Function();
        break;
      case '2':

        break;
      case '3':

        break;
      case '4':

        break;
      }
      delay(100);
      key = 0;
    }
  } while (u8g2.nextPage());
}
