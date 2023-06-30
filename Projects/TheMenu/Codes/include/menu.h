#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define Number_Selection_Max 5

struct Menu
{
    char *Name_Menu;

    char *Message;

    int Number_Selection;
    char *Name_Selection[Number_Selection_Max];
    int Number_Function[Number_Selection_Max];
    int Num_Function[Number_Selection_Max];
};
typedef struct Menu Menu;


/*The Tree*/
struct Node
{
    Menu *pMenu;
    int Current_Selection;
    
    struct Node *Next[Number_Selection_Max];
    struct Node *Last;
};
typedef struct Node Node;
typedef Node *ListMenu;

Node *New_Node();
void Connect_Node(Node *Main_Node, Node *Sub_Node, int Number_Next);

/*The Tree END*/


Node *Current_pNode;


/*Menu Initiallize*/
void Set_Name(Node *pNode, char *name);
void Set_Message(Node *pNode, char *message);
void Set_Selection(Node *pNode, char *pString, int Number_Selection, int Number_Function, int Num_Function);
void Set_Number_Selection(Node *pNode, int num);

/*Some Function*/
void Init();
void Clear();/*Modify this to adapt different terminals*/
void Refresh();/*Modify this to adapt different terminals*/
void Function();/*Modify this to add your function*/

/*The main process*/
void Loop();
