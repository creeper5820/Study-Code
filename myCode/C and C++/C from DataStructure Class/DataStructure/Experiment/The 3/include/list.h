/*list.h*/
//Some functions about linklist
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <dirent.h>
#ifndef _LIST_H_
#define _LIST_H_
#define MAX 50


struct Word {
	char word[MAX];
	int number;
};
typedef struct Word Item;


struct node {
	Item item;
	struct node *next;
};
typedef struct node Node;
typedef Node *List;




/*----------------------------------------*/


bool EmptyJudge(const List *plist);

bool FullJudge();

void ListInitiallize(List *plist);

void AddNode_Head(List *plist,Node temp);

void AddNode_Specified(List *plist,char *word);

void DeleteList(const List *plist);

int CountNode(const List *plist);

void PrintList(const List *plist);

void ExchangeNode(Node *pnode_1,Node *pnode_2);

void DeleteNode(List *plist,Node *pnode);

void PrintNode(Node *pnode);







#endif