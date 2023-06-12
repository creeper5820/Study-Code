#include "Stack.h"

int main()
{
    Stack MainStack;
    MainStack.pLQ_Main = createQueue();
    MainStack.pLQ_Sec = createQueue();
    // push my student numbers in the Stack
    push(&MainStack, 9);
    push(&MainStack, 2);
    push(&MainStack, 2);
    push(&MainStack, 1);
    push(&MainStack, 1);
    push(&MainStack, 0);
    push(&MainStack, 8);
    push(&MainStack, 0);
    push(&MainStack, 0);
    push(&MainStack, 6);
    push(&MainStack, 1);
    push(&MainStack, 2);
    // print all the stack elements
    StackPrint(&MainStack);
    // print the numbers that can be divisible by 3
    struct QNode *pQNode = MainStack.pLQ_Main->front;
    while (pQNode != NULL)
    {
        if (pQNode->key % 3 == 0)
            printf(">%d\n", pQNode->key);
        pQNode = pQNode->next;
    }
    // print the element in the top
    printf(">>%d\n", gettop(&MainStack));
    // pop a element and than print the stack
    pQNode = MainStack.pLQ_Main->front;
    while (pQNode->key != 8 && pQNode != NULL)
        pQNode = pQNode->next;
    pop(&MainStack, pQNode);
    StackPrint(&MainStack);

    return 0;
}