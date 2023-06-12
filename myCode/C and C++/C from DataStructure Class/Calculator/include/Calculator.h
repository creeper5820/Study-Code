#pragma once

#include <string.h>
#include <stdio.h>

struct Stack_Node{
    char ch;
    struct Stack_Node *next;
};
typedef struct Stack_Node Node;


typedef struct Stack{
    Node *Stack_Top;
    Node *Stack_Bottom;
};
typedef struct Stack Stack;



Stack *NewStack();

void PushStack(const char *expression);

