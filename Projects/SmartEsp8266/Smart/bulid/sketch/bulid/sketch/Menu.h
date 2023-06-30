#line 1 "D:\\Git\\Code-Learning\\Projects\\SmartEsp8266\\Smart\\bulid\\sketch\\Menu.h"
#line 1 "D:\\Git\\Code-Learning\\Projects\\SmartEsp8266\\Smart\\Menu.h"
// Menu
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

// The Tree
struct Node
{
    Menu *pMenu;
    int Current_Selection;

    struct Node *Next[Number_Selection_Max];
    struct Node *Last;
};
typedef struct Node Node;
typedef Node *ListMenu;

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

Node *Current_pNode;

// Menu Initiallize
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

/*Some Function*/
void Init()
{
    Current_pNode = NULL;
}

void Clear() /*Modify this to adapt different terminals*/
{
    u8g2.clear();
}

void Refresh() /*Modify this to adapt different terminals*/
{
    if (Current_pNode == NULL)
    {
        u8g2.drawStr(64, 32, "NULL");
        return;
    }
    u8g2.setCursor(0, 15);
    u8g2.print(Current_pNode->pMenu->Name_Menu);
    //    u8g2.setCursor(0, 30);
    //    u8g2.print(Current_pNode->pMenu->Message);

    for (int i = 0; i < Current_pNode->pMenu->Number_Selection; i++)
    {
        if (i == Current_pNode->Current_Selection)
        {
            // u8g2.drawFrame(1, (18 + i*15), strlen(Current_pNode->pMenu->Name_Selection[i])*9 + 1, 15);
            // u8g2.setCursor(3, (30 + i*15));
            // u8g2.print(Current_pNode->pMenu->Name_Selection[i]);

            u8g2.drawButtonUTF8(3, (30 + i * 15), U8G2_BTN_INV | U8G2_BTN_BW2, 0, 1, 1, Current_pNode->pMenu->Name_Selection[i]);
        }
        else
        {
            u8g2.setCursor(3, (30 + i * 15));
            u8g2.print(Current_pNode->pMenu->Name_Selection[i]);
        }
    }
}