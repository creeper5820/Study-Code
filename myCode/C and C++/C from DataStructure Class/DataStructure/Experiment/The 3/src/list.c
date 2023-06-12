/*list.c*/
#include "list.h"

/*--------------------对链表的操作函数--------------------*/
bool EmptyJudge(const List *plist)
{
    if (*plist == NULL)
        return true;
    else
        return false;
}
/*----------------------------------------*/
bool FullJudge()
{
    List p = NULL;
    p = (List)malloc(sizeof(Node));
    if (p == NULL)
    {
        free(p);
        return true;
    }
    else
    {
        free(p);
        return false;
    }
}
/*----------------------------------------*/
void ListInitiallize(List *plist)
{
    *plist = NULL;
}

/*----------------------------------------*/
void AddNode_Head(List *plist, Node temp)
{
    Node *pnode = NULL;
    pnode = (Node *)malloc(sizeof(Node));
    if (pnode == NULL)
    {
        printf("Memory request failed");
        exit(1);
    }
    pnode->item = temp.item;
    if (EmptyJudge(plist))
    {
        *plist = pnode;
        pnode->next = NULL;
    }
    else
    {
        pnode->next = *plist;
        *plist = pnode;
    }
}
/*----------------------------------------*/
void AddNode_Specified(List *plist, char *word)
{
    Node *pnode = NULL;
    pnode = (Node *)malloc(sizeof(Node));
    if (pnode == NULL)
    {
        printf("Memory request failed");
        exit(1);
    }
    strcpy(pnode->item.word, word);

    Node *temp = *plist;
    Node *temp_up = *plist;
    if (*plist == NULL || strcmp(word, temp->item.word) <= 0)
    {
        if (*plist == NULL || strcmp(word, temp->item.word) < 0)
        {
            pnode->next = *plist;
            *plist = pnode;
            pnode->item.number = 1;
        }
        else
            temp->item.number++;
    }
    else
    {

        for (;temp != NULL && strcmp(word, temp->item.word) > 0 ; temp = temp->next)
            ;
        for (; temp_up->next != NULL && temp_up->next != temp; temp_up = temp_up->next)
            ;
        if (temp != NULL &&strcmp(word, temp->item.word) == 0)
            temp->item.number++;
        else
        {
            pnode->next = temp_up->next;
            temp_up->next = pnode;
            pnode->item.number = 1;
        }
    }
}

/*----------------------------------------*/
void DeleteList(const List *plist)
{
    List list;
    list = *plist;
    List temp;
    do
    {
        temp = list->next;
        free(list);
        list = temp;
    } while (temp != NULL);
}
/*----------------------------------------*/
int CountNode(const List *plist)
{
    List list = *plist;
    int n = 0;
    while (list != NULL)
    {
        n++;
        list = list->next;
    }
    return n;
}
/*----------------------------------------*/
void ExchangeNode(Node *pnode_1, Node *pnode_2)
{
    Node temp;
    temp.item = pnode_1->item;
    pnode_1->item = pnode_2->item;
    pnode_2->item = temp.item;
}
/*----------------------------------------*/
void DeleteNode(List *plist, Node *pnode)
{
    Node *temp;

    if (pnode->next != NULL) // middle
    {
        temp = pnode->next;
        pnode->next = temp->next;
        pnode->item = temp->item;
        free(temp);
        return;
    }

    if (pnode == *plist && pnode->next == NULL) // head
    {
        free(pnode);
        *plist = NULL;
        return;
    }

    if (pnode->next == NULL && pnode != *plist) // end
    {
        List list = *plist;
        for (; list->next != pnode; list = list->next)
            ;
        list->next = NULL;
        free(pnode);
    }
}
/*----------------------------------------*/
void PrintNode(Node *pnode)
{
    Item item;
    item = pnode->item;
    printf("[Word]%s\n    Num :%d\n\n", item.word, item.number);
}
/*----------------------------------------*/
void PrintList(const List *plist)
{
    List temp = *plist;
    if (temp == NULL)
        printf("NULL\n");

    int n = 1;
    while (temp != NULL)
    {
        printf("[%d]", n);
        PrintNode(temp);
        temp = temp->next;
        n++;
    }
}
/*----------------------------------------*/
