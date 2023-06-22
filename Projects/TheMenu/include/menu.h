#pragma once

#include<stdio.h>
#include<stdlib.h>

//Customization
typedef int Type_Data;



//Const Number in Menu
#define MaxNum_Function 10

//the Menu struct
struct Menu{

    char *Name_Menu;
    char *Information;

    int    Num_Submenu;
    int    Num_Function;
    struct Menu *List_Submenu;
    struct Menu *Ptr_NextMenu;
    struct Menu *Ptr_LastMenu;

    void (*Function[MaxNum_Function])(Type_Data);
    char *Name_Function[MaxNum_Function];
};
typedef struct Menu Menu;

//Global Varible
Menu *Ptr_MainMenu;
Type_Data Global_Data;

//Global Function
void Loop_Menu();
Menu New_Menu(char *Name_Menu,char *Information);
void Connect_Menu(Menu *Ptr_MainMenu,Menu *Ptr_SubMenu);
void Connect_Function(Menu *Ptr_Menu,void (*Ptr_Function)(void));
void Show_MainMenu(Menu *Ptr_MainMenu);
void Enter_Submenu(Menu *List_Submenu,int Num);
void Clear();
int Input_Num();