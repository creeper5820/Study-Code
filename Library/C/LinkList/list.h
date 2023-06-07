/*list.h*/
//Some functions about linklist
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <dirent.h>
#ifndef _LIST_H_
#define _LIST_H_
#define MAX 50


struct Item {
	char name[MAX];
	char num[MAX];
	char price[MAX];
};
typedef struct Item Item;


struct node {
	Item item;
	struct node *next;
};
typedef struct node Node;
typedef Node *List;

//Results List
struct Address{
    Node *p;
    struct Address *next;
};
typedef struct Address Back;
typedef Back *BackList;



/*----------------------------------------*/


bool EmptyJudge(const List *plist);

bool FullJudge();

void ListInitiallize(List *plist);

void InputItem(Node *pnode);/*---*/

void AddNode_Head(List *plist,Node temp);

void AddNode_Specified(List *plist,Node temp,int N);

void DeleteList(const List *plist);

int CountNode(const List *plist);

int CountBack(const BackList *pbacklist);

void PrintList(const List *plist);

void PrintBack(BackList *pbacklist);

void ExchangeNode(Node *pnode_1,Node *pnode_2);

void DeleteNode(List *plist,Node *pnode);

void DeleteBack(BackList *pbacklist,Back *pback);

void AddBack(BackList *pbacklist,Node* pNode);

BackList NodeFind(const List *plist, const char *string,int n);/*---*/

void PrintNode(Node *pnode);/*---*/







#endif