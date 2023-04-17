/*list.c*/
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
/*--------------------对链表的操作函数--------------------*/
bool EmptyJudge(const List *plist)
{
	if(*plist==NULL)
	return true;
	else
	return false;
}
/*----------------------------------------*/
bool FullJudge(const List *plist)
{
	List p=NULL;
	p=(List)malloc(sizeof(Node));
	if(p==NULL){
		free(p);
	return true;
	}
	else{
		free(p);
	return false;		
	}
}
/*----------------------------------------*/
void ListInitiallize( List *plist)
{
	*plist=NULL;
}
/*----------------------------------------*/
void AddNode1(List *plist)
{
	Node*pnode=NULL;
	pnode=(Node*)malloc(sizeof(Node));
	if(pnode==NULL) {
		printf("申请内存失败！！！");
		exit(1);
	}
	InputItem(pnode);
	if(EmptyJudge(plist))
	{
		*plist=pnode;
		pnode->next=NULL;
	}else{
		pnode->next=*plist;
		*plist=pnode;
	}	
}
/*----------------------------------------*/
void AddNode2(List *plist,Node temp)
{
	Node*pnode=NULL;
	pnode=(Node*)malloc(sizeof(Node));
	if(pnode==NULL) {
		printf("申请内存失败！！！");
		exit(1);
	}
	pnode->item=temp.item;
	if(EmptyJudge(plist))
	{
		*plist=pnode;
		pnode->next=NULL;
	}else{
		pnode->next=*plist;
		*plist=pnode;
	}	
}
/*----------------------------------------*/
void DeleteList(const List *plist)
{
	List list;
	list=*plist;
	List temp;
	do
	{
		temp=list->next;
		free(list);
		list=temp;
	}while(temp!=NULL);
}
/*----------------------------------------*/
int CountNode(const List *plist)
{
	List list=*plist;
	int n=0;
	while(list!=NULL)
	{
		n++;
		list=list->next;
	}
	return n;
}
/*----------------------------------------*/
void ExchangeNode(Node *pnode_1,Node *pnode_2)
{
	Node temp;
	temp.item=pnode_1->item;
	pnode_1->item=pnode_2->item;
	pnode_2->item=temp.item;
}
/*----------------------------------------*/
void DeleteNode(Node **ppnode)
{
	Node *temp;
	Node*pnode=*ppnode;
	if(pnode->next!=NULL){
	temp=pnode->next;
	*pnode=*temp;
	free(temp);
    }else{
    	free(pnode);
	    *ppnode=NULL;
	}
		
}
/*----------------------------------------*/
void InputItem(Node *pnode)
{
	char c[MAX];
	printf("请输入作品名称\n");
	scanf("%s",c);
	strcpy(pnode->item.name,c);
	printf("请输入作品时间\n");
	scanf("%s",c);
	strcpy(pnode->item.time,c);
	printf("请输入作品标签\n");
	scanf("%s",c);	
	strcpy(pnode->item.tag,c);
	printf("请输入作品备注\n");
	scanf("%s",c);	
	strcpy(pnode->item.more,c);
}
/*----------------------------------------*/
Node *NodeFind(const List *plist, const char *string,int n)
{	
    Node *pnode;
	pnode=*plist;
	List list2;
	ListInitiallize(&list2);

	switch(n)
	{
		case 1:{
			int num=0;
			while(pnode!=NULL)
			{			
				for(int i=0;pnode->item.name[i]!='\0';i++)
				{
					num=0;
					for(int j=0;string[j]!='\0';j++)
					{
						num+=(string[j]==pnode->item.name[i+j]);
					}
					if(num==strlen(string))
					{					
						AddNode2(&list2,*pnode);

						break;
					}
				}
				pnode=pnode->next;
			}
			return list2;
			break;
		}

		case 2:{
			int num=0;
			while(pnode!=NULL)
			{				
				for(int i=0;pnode->item.time[i]!='\0';i++)
				{
					num=0;
					for(int j=0;string[j]!='\0';j++)
					{
						num+=(string[j]==pnode->item.time[i+j]);
					}
					if(num==strlen(string))
					{					
						AddNode2(&list2,*pnode);

						break;
					}
				}
				pnode=pnode->next;
			}
			return list2;
			break;
		}

		case 3:{
			int num=0;
			while(pnode!=NULL)
			{				
				for(int i=0;pnode->item.tag[i]!='\0';i++)
				{
					num=0;
					for(int j=0;string[j]!='\0';j++)
					{
						num+=(string[j]==pnode->item.tag[i+j]);
					}
					if(num==strlen(string))
					{					
						AddNode2(&list2,*pnode);

						break;
					}
				}
				pnode=pnode->next;
			}
			return list2;
			break;
		}

		case 4:{
			int num=0;
			while(pnode!=NULL)
			{				
				for(int i=0;pnode->item.more[i]!='\0';i++)
				{
				    num=0;
					for(int j=0;string[j]!='\0';j++)
					{
						num+=(string[j]==pnode->item.more[i+j]);
					}
					if(num==strlen(string))
					{					
						AddNode2(&list2,*pnode);

						break;
					}

				}
				pnode=pnode->next;
			}
			return list2;
			break;
		}

	}
	
}
/*----------------------------------------*/
void PrintNode(Node *pnode)
{
	Item item;
	item=pnode->item;
	printf("/*----------------------------------------*/\n");
	printf("[Name]%s\n[Time]%s\n[ Tag]%s\n[More]%s\n",item.name ,item.time ,item.tag ,item.more);
	printf("/*----------------------------------------*/\n");
}
/*----------------------------------------*/
void PrintList(const List *plist)
{
	List temp=*plist;
	while(temp!=NULL)
	{
		PrintNode(temp);
		temp=temp->next;
	}
}
/*--------------------对Dirent信息和链表的操作函数--------------------*/
void DirentToNode(const Node *node, const char *address)
{
}
/*----------------------------------------*/
bool DirentFind(const char *address)
{
}
/*--------------------对文件和链表的操作函数--------------------*/
bool AllFileToList(const FILE *fp, const List *plist)
{
}
/*----------------------------------------*/
bool AllListToFile(const FILE *fp, const List *PList)
{
}
/*----------------------------------------*/
void FileCreate(const List *plist)
{
}
/*----------------------------------------*/
void DeleteFile(const Node *node)
{
}
/*----------------------------------------*/
void FileSave(const char *name[], const char *address)
{
}
/*----------------------------------------*/