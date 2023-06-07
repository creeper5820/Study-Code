#include "Stack.h"

// function

Stack *Init_Stack()
{
    Stack *pstack = (Stack *)malloc(sizeof(Stack));
    pstack->Size_Stack = 0;
    pstack->top = NULL;
    return pstack;
}

void Push(Stack *pStack, ElemType E)
{
    Node_Stack *temp = (Node_Stack *)malloc(sizeof(Node_Stack));
    temp->data = E;

    if (pStack->Size_Stack)
        temp->next = pStack->top;
    else
        temp->next = NULL;

    pStack->top = temp;
    pStack->Size_Stack++;
}

void Pop(Stack *pStack, ElemType *pE)
{
    if (!pStack->Size_Stack)
    {
        printf("Stack is Empty");
        return;
    }

    *pE = pStack->top->data;

    Node_Stack *Pre = pStack->top;
    pStack->top = pStack->top->next;
    free(Pre);
    pStack->Size_Stack--;
}

void Print(Stack *pStack)
{
    if (!pStack->Size_Stack)
        return;
    for (Node_Stack *temp = pStack->top; temp != NULL; temp = temp->next)
        printf("%c\n", temp->data);
}