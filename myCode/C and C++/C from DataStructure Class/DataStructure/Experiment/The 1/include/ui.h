/*ui.h*/
//The function of printing the different GUI to help user use this program
#include<stdio.h>
#include"list.h"
#ifndef UI_H_
#define UI_H_




/*Windows*/
void Initialize(List *plist);
//As what it named!

void HOME(List *plist);
//plist:The LinkList    a
//To Show the main operations

void MessageInput(List *plist);
//plist:The LinkList    b
//to add a new node by inputing

void StudentList(List *plist);
//plist:The LinkList    c
//Show the entire List and operations

void StudentSelect(List *plist);
//plist:The LinkList    d
//Choose a Student by number

void StudentMessage(List *plist,Node *pnode);
//plist:The LinkList,pnode:the current node e
//To show operations foe a single student

void BackMessage(List *plist,BackList *pbacklist,Back *pback);
//To show the result of students search

void StudentFind(List *plist);
//plist:The LinkList    g
//To Find some student

void FindBack(List *plist,BackList* pbacklist);
//backhead:The find results,a pointer to thr struct of single resuelt   h
//Operations for the back results

void ResultsSelect(List *plist,BackList *pBackList);
//pBackList: the results list from searching students
//to select a student to manage from this list

/*Functions*/

void JumpPage(char page,List *plist);
//page:The page you want to jump into




#endif