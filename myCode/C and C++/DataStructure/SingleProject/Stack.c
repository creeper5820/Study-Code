#include <stdio.h>
#include <stdlib.h>

/*
主要思想：后进先出
本质是一个特殊的线性表

有以下几种属性和操作
top,buttom

push(),pop(),
*/

// # Stack
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

// # Calculate

int Pow(int a, int b)
{
    int N = 1;

    if (b == 0)
        return 1;
    for (int i = 0; i < b; i++)
        N = N * a;

    return N;
}
/*
基本思路：
中缀表达式改逆波兰表达式，亦可称后缀表达式
*/

int Judge_Type(char ch)
{
    if (ch == ' ')
        return 0;
    if (ch > '0' && ch < '9')
        return 1;

    return (int)ch;
}


char *Get_Expression()
{
    char *pString = (char *)malloc(sizeof(char));
    char current;
    int count = 0;

    while ((current = getchar()) != '\n')
    {
        pString[count] = current;
        count++;
        pString = (char *)realloc(pString, sizeof(char *) * (count + 1));
    }

    pString[count] = '\0';
    return pString;
}

void Accumulate_Num(int figure, int **pNum)
{
    int *Num = *pNum;

    if (Num == NULL)
    {
        Num = (int *)malloc(sizeof(int *) * 2);
        Num[1] = figure;
        Num[0] = 1;
    }
    else
    {
        Num = (int *)realloc(Num, sizeof(int *) * (Num[0] + 2));
        Num[Num[0] + 1] = figure;
        Num[0]++;
    }

    *pNum = Num;
}

int Get_Num(int *Num)
{
    int N = 0;
    for (int i = 1; i <= Num[0]; i++)
    {
        int a = Num[i];
        N += Num[i] * Pow(10, (Num[0] - i));
    }
    return N;
}

char *Transform_Exprssion(char *String)
{
    Stack *Action = Init_Stack();
    char *Expression = (char *)malloc(sizeof(char));
    Expression[0] = '\0';

    for(int count = 0,char current;String[count] != '\0';count++)
    {
        current = String[count];
        
        
    }


}

// main
int main()
{
    char *String = Get_Expression();

    printf("%s",String);
    return 0;
}