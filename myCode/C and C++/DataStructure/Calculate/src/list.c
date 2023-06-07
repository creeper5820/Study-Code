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
void AddNode_Head(List *plist,Node temp)
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
void AddNode_Specified(List *plist,Node temp,int N)
{
    Node *pnode = NULL;
    pnode = (Node *)malloc(sizeof(Node));
    if (pnode == NULL)
    {
        printf("Memory request failed");
        exit(1);
    }
    pnode->item = temp.item;

    switch(N)
    {
    case 0:{
        pnode->next=*plist;
        *plist=pnode;
        break;
    }

    case 1:{
        pnode->next=(*plist)->next;
        (*plist)->next=pnode;
        break;
    }

    default:{
        List temp=*plist;
    for(int i=0;i<N-1;i++)
    temp=temp->next;
        if (temp->next==NULL)
        {
          temp->next = pnode;
          pnode->next = NULL;
        }
    else
        {
          pnode->next = temp->next;
          temp->next = pnode;
        }
    break;}
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
void DeleteNode(List *plist,Node *pnode)
{
    Node *temp;

    if (pnode->next != NULL)//middle
    {
        temp = pnode->next;
        pnode->next=temp->next;
        pnode->item=temp->item;
        free(temp);
        return;
    }
    
    if(pnode==*plist&&pnode->next == NULL)//head
    {
        free(pnode);
        *plist=NULL;
        return;
    }

    if(pnode->next == NULL&&pnode!=*plist)//end
    {
        List list=*plist;
        for(;list->next!=pnode;list=list->next);
        list->next=NULL;
        free(pnode);
    }
}
/*----------------------------------------*/
void DeleteBack(BackList *pbacklist,Back *pback)
{
    Back *temp;

    if (pback->next != NULL)//middle
    {
        temp = pback->next;
        pback->next=temp->next;
        pback->p=temp->p;
        free(temp);
        return;
    }
    
    if(pback==*pbacklist&&pback->next == NULL)//head
    {
        free(pback);
        *pbacklist=NULL;
        return;
    }

    if(pback->next == NULL&&pback!=*pbacklist)//end
    {
        BackList backlist=*pbacklist;
        for(;backlist->next!=pback;backlist=backlist->next);
        backlist->next=NULL;
        free(pback);
    }   
}
/*----------------------------------------*//*---*/
void InputItem(Node *pnode)
{
    char c[MAX];
    printf("Input the name\n");
    scanf("%s", c);
    strcpy(pnode->item.name, c);
    printf("Input the number\n");
    scanf("%s", c);
    strcpy(pnode->item.num, c);
    printf("Input the price\n");
    scanf("%s", c);
    strcpy(pnode->item.price, c);

}

/*----------------------------------------*/
void AddBack(BackList *pbacklist,Node* pNode)
{
    Back* temp=(Back*)malloc(sizeof(Back));
   if (temp == NULL)
    {
        printf("Memory request failed");
        exit(1);
    }

        temp->p=pNode;  

    if(*pbacklist==NULL)
    {
        *pbacklist=temp;
        temp->next=NULL;
    }else{
        temp->next=*pbacklist;
        *pbacklist=temp;
    }
}
/*----------------------------------------*//*---*/
BackList NodeFind(const List *plist, const char *string, int n)
{
    Node *pnode;
    pnode = *plist;
    char key[MAX];

    BackList backlist=NULL;

    while (pnode != NULL)
    {
    switch (n)
    {
    case 1:
        strcpy(key, pnode->item.name);
        break;
    case 2:
        strcpy(key, pnode->item.num);
        break;
    case 3:
        strcpy(key, pnode->item.price);
        break;
    }

    unsigned int num = 0;
        for (int i = 0; key[i] != '\0'; i++)
        {
            num = 0;
            for (int j = 0; string[j] != '\0'; j++)
            {
                num += (string[j] == key[i + j]);
            }
            if (num == strlen(string))
            {
                AddBack(&backlist,pnode);
                break;
            }
        }
        pnode = pnode->next;
    }
    return backlist;
}
/*----------------------------------------*//*---*/
void PrintNode(Node *pnode)
{
    Item item;
    item = pnode->item;
    printf("[Name]%s\n    Num :%s\n    Price:%s\n\n", item.name, item.num, item.price);
}
/*----------------------------------------*/
void PrintList(const List *plist)
{
    List temp = *plist;
    if(temp==NULL)
    printf("NULL\n");

    int n=1;
    while (temp != NULL)
    {
        printf("[%d]",n);
        PrintNode(temp);
        temp = temp->next;
        n++;
    }
}
/*----------------------------------------*/
void PrintBack(BackList *pbacklist)
{
    BackList temp = *pbacklist;
    if(temp==NULL)
    printf("NULL\n");

    int n=1;
    while (temp != NULL)
    {
        printf("[%d]",n);
        PrintNode(temp->p);
        temp = temp->next;
        n++;
    }
}
/*----------------------------------------*/
int CountBack(const BackList *pbacklist)
{
    {
    BackList backlist = *pbacklist;
    int n = 0;
    while (backlist != NULL)
    {
        n++;
        backlist = backlist->next;
    }
    return n;
}
}