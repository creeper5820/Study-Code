/*ui.c*/
#include"ui.h"

/*Windows*/
void Initialize(List *plist)
{
   ListInitiallize(plist); 
}


void HOME(List *plist)
{
    while(1){
    printf("\n[THE HOME]\n");
    printf("1.Add Students\n");
    printf("2.Manage Students\n");
    printf("3.Print the Student List\n");
    printf("4.Exit\n");
    printf(">");

    char j;
    while((j=getchar())<'1'||j>'4'){
        printf(">");
        }
        
        switch(j)
        {
            case '1':JumpPage('b',plist);
            break;
            case '2':JumpPage('c',plist);
            break;
            case '3':PrintList(plist);
            break;
            case '4':exit(1);
            break;
        }
    }
}

void MessageInput(List *plist)
{
    while(1){
    printf("\n[THE MessageInput]\n");
    printf("1.Add at head\n");
    printf("2.Add at given ordinal\n");
    printf("3.The StudentList\n");
    printf("4.back\n");
    printf("5.exit\n");
    printf(">");

    char j;
    while((j=getchar())<'1'||j>'5'){
        printf(">");
        }
        
        switch(j)
        {
            case '1':
            {
                Node* temp=(Node*)malloc(sizeof(Node*));
                InputItem(temp);
                AddNode_Head(plist,*temp);
                free(temp);
                break;
            }
            case '2':
            {
                printf("Intput the ordinal you want to insert(-1 to stop)\n");

                int N;
                do{
                    printf(">");
                    scanf("%d",&N);
                }while((N<1||N>CountNode(plist)+1)&&N!=-1);
                if(N==-1)break;

                Node* temp=(Node*)malloc(sizeof(Node*));
                InputItem(temp);
                AddNode_Specified(plist,*temp,N-1);
                free(temp);
                break;
            }
            case '3':
            {
                PrintList(plist);
                break;
            }
            case '4':break;
            case '5':exit(1);
        }
    if(j=='4')break;
    }
}


void StudentList(List *plist)
{
 while(1){
    PrintList(plist);
    printf("\n[Manage Student]\n");
    printf("1.select a student\n");
    printf("2.search students\n");
    printf("3.back\n");
    printf("4.exit\n");
    printf(">");

    char j;
    while((j=getchar())<'1'||j>'4'){
        printf(">");
        }
        
        switch(j)
        {
            case '1':
            {
                JumpPage('d',plist);
                break;
            }
            case '2':
            {
                JumpPage('g',plist);
                break;
            }
            case '3':break;
            case '4':exit(1);
        }
    if(j=='3')break;
    }
}


void StudentSelect(List *plist)
{
    if(*plist==NULL){
        printf("NULL\n");
        return;
    }
    printf("[The ordinal]\n");
    int N;
    do{
        printf(">");
        scanf("%d",&N);
    }while(N<1||N>CountNode(plist));

    Node *pnode=*plist;
    for(int i=1;i<N;i++)pnode=pnode->next;

    StudentMessage(plist,pnode);
}


void StudentMessage(List *plist,Node *pnode)
{  
while(1){
    printf("\n");
    PrintNode(pnode);
    printf("[Manage Student]\n");
    printf("1.the next student\n");
    printf("2.the last student\n");
    printf("3.Modify the message\n");
    printf("4.delete this student\n");
    printf("5.back\n");
    printf("6.exit\n");
    printf(">");

    char j;
    while((j=getchar())<'1'||j>'6'){
        printf(">");
        }
        
        switch(j)
        {
            case '1':
            {
                if(pnode->next!=NULL)
                    StudentMessage(plist,pnode->next);
                    else
                    StudentMessage(plist,*plist);
                break;
            }
            case '2':
            {
                Node *list=*plist;
                if(list!=pnode)
                {
                    for(;list->next!=pnode;list=list->next);
                    StudentMessage(plist,list);                 
                }else{
                    for(;list->next!=NULL;list=list->next);
                    StudentMessage(plist,list);
                }
                break;
            }
            case '3':
            {
                InputItem(pnode);
                break;
            }
            case '4':
            {
                DeleteNode(plist,pnode);
                break;
            }
            case '5':break;
            case '6':exit(1);
        }
    if(j=='5'||j=='1'||j=='2'||j=='4')break;
    }
}



void StudentFind(List *plist)
{
    while(1){
    printf("\n[The Student Search]\n");
    printf("1.Find by names\n");
    printf("2.Find by numbers\n");
    printf("3.Find by scores\n");
    printf("4.back\n");
    printf("5.exit\n");
    printf(">");

    char j;
    while((j=getchar())<'1'||j>'5'){
        printf(">");
        }
        
        char key[MAX];
    if(j=='1'||j=='2'||j=='3'){
        printf("Please input what you want to search\n");
        scanf("%s",key);
        }

    BackList backlist=NULL;
    backlist=NodeFind(plist,key,j-48);
    BackList *pbacklist=&backlist;
    

        switch(j)
        {
        
            case '1':
            {               
                
                FindBack(plist,pbacklist);
                break;
            }
            case '2':
            {
                FindBack(plist,pbacklist);
                break;
            }
            case '3':
            {
                FindBack(plist,pbacklist);
                break;
            }
            case '4':break;
            case '5':exit(1);
        }
    if(j=='4')break;
    }
}


void FindBack(List *plist,BackList* pbacklist)
{
    while(1){
    PrintBack(pbacklist);
    printf("\n[The Results]\n");
    printf("1.Select a student\n");
    printf("2.back\n");
    printf("3.exit\n");
    printf(">");

    char j;
    while((j=getchar())<'1'||j>'3'){
        printf(">");
        }

        switch(j)
        {
            case '1':
            {
                ResultsSelect(plist,pbacklist);
                break;
            }
            case '2':break;
            case '3':exit(1);
        }
    if(j=='2')break;
    }
}


void ResultsSelect(List *plist,BackList *pbacklist)
{
    {
    if(*pbacklist==NULL){
        printf("NULL\n");
        return;
    }
    printf("[The ordinal]\n");
    int N;
    do{
        printf(">");
        scanf("%d",&N);
    }while(N<1||N>CountBack(pbacklist));

    Back *pback=*pbacklist;
    for(int i=1;i<N;i++)pback=pback->next;

    BackMessage(plist,pbacklist,pback);
}
}

void BackMessage(List *plist,BackList *pbacklist,Back *pback)
{  
while(1){
    printf("\n");
    PrintNode(pback->p);
    printf("[Manage Student]\n");
    printf("1.the next student\n");
    printf("2.the last student\n");
    printf("3.Modify the message\n");
    printf("4.delete this student\n");
    printf("5.back\n");
    printf("6.exit\n");
    printf(">");

    char j;
    while((j=getchar())<'1'||j>'6'){
        printf(">");
        }
        
        switch(j)
        {
            case '1':
            {
                if(pback->next!=NULL)
                    BackMessage(plist,pbacklist,pback->next);
                    else
                    BackMessage(plist,pbacklist,*pbacklist);
                break;
            }
            case '2':
            {
                Back *backlist=*pbacklist;
                if(backlist!=pback)
                {
                    for(;backlist->next!=pback;backlist=backlist->next);
                    BackMessage(plist,pbacklist,backlist);             
                }else{
                    for(;backlist->next!=NULL;backlist=backlist->next);
                    BackMessage(plist,pbacklist,backlist);
                }
                break;
            }
            case '3':
            {
                InputItem(pback->p);
                break;
            }
            case '4':
            {
                DeleteNode(plist,pback->p);
                DeleteBack(pbacklist,pback);
                break;
            }
            case '5':break;
            case '6':exit(1);
        }
    if(j=='5'||j=='1'||j=='2'||j=='4')break;
    }
}


/*Functions*/
void JumpPage(char page,List *plist)
{
    switch(page)
    {
        case 'a':{
            HOME(plist);
            break;
        }
        case 'b':{
            MessageInput(plist);
            break;
        }
         case 'c':{
            StudentList(plist);
            break;
        }
        case 'd':{
            StudentSelect(plist);
            break;
        }
        case 'g':{
            StudentFind(plist);
            break;
        }
    }
}