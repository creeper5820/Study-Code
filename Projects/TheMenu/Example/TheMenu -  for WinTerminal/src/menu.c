#include "menu.h"

Node *New_Node()
{
    Node *temp = (Node *)malloc(sizeof(Node));

    for (int i = 0; i < Number_Selection_Max; i++)
    {
        temp->Next[i] = NULL;
    }
    temp->Current_Selection = 0;

    Menu *temp_Menu = (Menu *)malloc(sizeof(Menu));
    temp_Menu->Name_Menu = NULL;
    temp_Menu->Message = NULL;
    temp_Menu->Number_Selection = 0;
    for (int i = 0; i < Number_Selection_Max; i++)
    {
        temp_Menu->Name_Selection[i] = NULL;
        temp_Menu->Number_Function[i] = 0;
        temp_Menu->Num_Function[i] = 0;
    }

    temp->pMenu = temp_Menu;
    return temp;
}

void Connect_Node(Node *Main_Node, Node *Sub_Node, int Number_Next)
{
    Main_Node->Next[Number_Next] = Sub_Node;
    Sub_Node->Last = Main_Node;
}

void Set_Name(Node *pNode, char *name)
{
    if (pNode->pMenu->Name_Menu != NULL)
        free(pNode->pMenu->Name_Menu);

    char *temp = (char *)malloc(strlen(name) + 1);
    pNode->pMenu->Name_Menu = temp;
    strcpy(pNode->pMenu->Name_Menu, name);
}

void Set_Message(Node *pNode, char *message)
{
    if (pNode->pMenu->Message != NULL)
        free(pNode->pMenu->Message);

    char *temp = (char *)malloc(strlen(message) + 1);
    pNode->pMenu->Message = temp;
    strcpy(pNode->pMenu->Message, message);
}

void Set_Selection(Node *pNode, char *pString, int Number_Selection, int Number_Function, int Num_Function)
{
    if (pNode->pMenu->Name_Selection[Number_Selection] != NULL)
        free(pNode->pMenu->Name_Selection[Number_Selection]);

    char *temp = (char *)malloc(strlen(pString) + 1);
    pNode->pMenu->Name_Selection[Number_Selection] = temp;
    
    strcpy(pNode->pMenu->Name_Selection[Number_Selection], pString);
    pNode->pMenu->Number_Function[Number_Selection] = Number_Function;
    pNode->pMenu->Num_Function[Number_Selection] = Num_Function;
}

void Set_Number_Selection(Node *pNode, int num)
{
    pNode->pMenu->Number_Selection = num;
}

void Init()
{
    Current_pNode = NULL;
}

void Clear()
{
    system("cls");
}

void Refresh()
{
    Clear();

    if (Current_pNode == NULL)
    {
        printf("\033[0;31mNULL\033[0m");
        return;
    }
    printf("%s\n%s\n", Current_pNode->pMenu->Name_Menu, Current_pNode->pMenu->Message);

    for (int i = 0; i < Current_pNode->pMenu->Number_Selection; i++)
    {
        if (i == Current_pNode->Current_Selection)
            printf("\033[47m\033[30m%s \033[0m\n", Current_pNode->pMenu->Name_Selection[i]);
        else
            printf("%s\n", Current_pNode->pMenu->Name_Selection[i]);
    }
}

void Function()
{
    switch (Current_pNode->pMenu->Number_Function[Current_pNode->Current_Selection])
    {
    case 0:
    {
        exit(1);
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
        Clear();
        printf("\033[0;31m");
        printf("你说的对，但是呢，那个，就是《原神》，它那个，嗯，他是由那个米...哈游，自主，啊，研发的一款…全新的，开放的，那个叫做什么世界冒险，的游戏。这个，游戏发生在一个…一个被称作，被称作「提瓦……特」的一个幻想的世界，然后就是在这里，嗯，怎么说呢，被…那个神，怎么呢，那个神选中的人…就是将被授予…「神什么眼」，然后导引这个，元素之力。那个谁，就是你，将扮演一位名为…名为「旅行者」的什么，那个神秘角色，啊，然后就是在自由的旅行中干什么来着，就是邂逅性格各异的、还有就是能力独特的那个同伴们，然后和他们一起击败强敌，然后找回那个，失散的谁来着……那个亲人——然后同时，啊，逐步发掘「忘叫啥了」的真相。?");
        printf("​\033[0m\n");
        getch();
    }
    default:
    {
        break;
    }
    }
}

void Loop()
{
    while (1)
    {
        Refresh();

        char c = getch();
        switch (c)
        {
        case 72:
        {
            Current_pNode->Current_Selection--;
            if (Current_pNode->Current_Selection + 1 < 1)
                Current_pNode->Current_Selection = Current_pNode->pMenu->Number_Selection - 1;
            break;
        }
        case 80:
        {
            Current_pNode->Current_Selection++;
            if (Current_pNode->Current_Selection + 1 > Current_pNode->pMenu->Number_Selection)
                Current_pNode->Current_Selection = 0;
            break;
        }

        case 13:
        {
            Function();
            break;
        }

        default:
        {
            break;
        }
        }
    }
}