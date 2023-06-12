/*Stack.c*/
#include "Stack.h"

int pop(Stack *pStack, struct QNode *key)
{
    int elem, Num;
    if (pStack->pLQ_Main->front == NULL)
    {
        printf("The Stack is empty!");
        return -1;
    }

    while (key != pStack->pLQ_Main->front)
    {
        elem = pStack->pLQ_Main->front->key;
        deQueue(pStack->pLQ_Main);
        enQueue(pStack->pLQ_Sec, elem);
    }

    if (key == pStack->pLQ_Main->front)
    {
        Num = pStack->pLQ_Main->front->key;
        deQueue(pStack->pLQ_Main);
    }

    while (pStack->pLQ_Main->front != NULL)
    {
        elem = pStack->pLQ_Main->front->key;
        deQueue(pStack->pLQ_Main);
        enQueue(pStack->pLQ_Sec, elem);
    }

    while (pStack->pLQ_Sec->front != NULL)
    {
        elem = pStack->pLQ_Sec->front->key;
        deQueue(pStack->pLQ_Sec);
        enQueue(pStack->pLQ_Main, elem);
    }

    return Num;
}

void push(Stack *pStack, int elem)
{
    enQueue(pStack->pLQ_Main, elem);
}

int gettop(Stack *pStack)
{
    if (pStack->pLQ_Main->front == pStack->pLQ_Main->rear)
    {
        printf("Empty!");
        return -1;
    }
    else
        return pStack->pLQ_Main->front->key;
}

bool empty(Stack *pStack)
{
    while (pStack->pLQ_Main->front != pStack->pLQ_Main->rear)
        deQueue(pStack->pLQ_Main);

    if (pStack->pLQ_Main->front == pStack->pLQ_Main->rear)
        return true;
    else
        return false;
}

void StackPrint(Stack *pStack)
{

    if (pStack->pLQ_Main->front == pStack->pLQ_Main->rear)
        return;

    struct QNode *pQNode = pStack->pLQ_Main->front;
    while (pQNode != NULL)
    {
        printf("[%d]\n", (pQNode->key));
        pQNode = pQNode->next;
    }
}