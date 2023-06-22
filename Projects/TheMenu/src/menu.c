#include "menu.h"

void Loop_Menu()
{
    while (1)
    {
        if (Ptr_MainMenu == NULL)
        {
            printf("NULL\n");
            exit(0);
        }

        Show_MainMenu(Ptr_MainMenu);
        int Num = Input_Num();
        if (Num <= Ptr_MainMenu->Num_Submenu)
        {
            Enter_Submenu(Ptr_MainMenu->List_Submenu, Num);
            Clear();
        }
        else
            Ptr_MainMenu->Function[Num - Ptr_MainMenu->Num_Submenu](Global_Data);
    }
}

Menu New_Menu(char *Name_Menu, char *Information)
{
}
void Connect_Menu(Menu *Ptr_MainMenu, Menu *Ptr_SubMenu)
{
}
void Connect_Function(Menu *Ptr_Menu, void (*Ptr_Function)(void))
{
}
void Show_MainMenu(Menu *Ptr_MainMenu)
{
}
void Enter_Submenu(Menu *List_Submenu, int Num)
{
}
void Clear()
{
    printf("\033[2J\033[H");
}
int Input_Num()
{
//  int max = Ptr_MainMenu->Num_Function + Ptr_MainMenu->Num_Submenu;
    int max = 5;
    int N = -1;
    while (N < 0 || N > max)
    {
        printf(">");
        scanf("%d",&N);
    }
    return N;
}