#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *Init_List()
{
    Node *list = (Node *)malloc(sizeof(Node));
    list->data = 0;
    list->next = NULL;
    return list;
}

void Insert_Head(Node *list, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = list->next;
    list->next = node;
    list->data++;
}

void Insert_Tail(Node *list, int data)
{
    Node *head = list;
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    for (; list->next; list = list->next)
        ;
    list->next = node;
    head->data++;
}

void Delete_Node(Node *list, int data)
{
    Node *head = list;
    Node *pre = list;
    Node *current = list->next;

    while (current)
    {
        if (current->data == data)
        {
            pre->next = current->next;
            free(current);
            current = pre->next;
            head->data--;
        }
        else
        {
            current = current->next;
        }
    }
}

void Print_List(Node* list)
{
    for(;list;list = list->next)
    printf("%d\n",list->data);
}


int main()
{
    Node* list = Init_List();
    Insert_Head(list, 5);
    Insert_Head(list, 6);
    Insert_Tail(list, 1);
    Insert_Head(list, 6);
    Insert_Tail(list, 4);
    Delete_Node(list, 6);
    Print_List(list);
    
}