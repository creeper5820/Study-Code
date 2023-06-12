/*Stack.h*/
#include<LinkQueue.h>

typedef struct Stack{
    struct Queue *pLQ_Main;
    struct Queue *pLQ_Sec;
} Stack;

int pop(Stack *pStack, struct QNode *key);

void push(Stack *pStack,int elem);

int gettop(Stack *pStack);

bool empty(Stack *pStack);

void StackPrint(Stack *pStack);