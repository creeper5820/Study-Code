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
    printf("\033[2J\033[1;1H");
}

void flush()
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
            printf(" \033[47m\033[30m%s \033[0m\n", Current_pNode->pMenu->Name_Selection[i]);
        else
            printf(" %s \n", Current_pNode->pMenu->Name_Selection[i]);
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
        printf("\033[0;31mOHHHHHHHHH!!!\033[0m");
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
        flush();

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