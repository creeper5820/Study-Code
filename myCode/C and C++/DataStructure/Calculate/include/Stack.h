#pragma once

#include <stdio.h>
#include <stdlib.h>

#define ElemType char

typedef struct Node_Stack
{
    ElemType data;
    struct Node_Stack *next;
} Node_Stack;

typedef struct Stack
{
    Node_Stack *top;
    int Size_Stack;
} Stack;

// function

Stack *Init_Stack();

void Push(Stack *pStack, ElemType E);

void Pop(Stack *pStack, ElemType *pE);

void Print(Stack *pStack);