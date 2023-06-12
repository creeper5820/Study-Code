队列实现栈

鉴于学习通界面提供的链队列代码漏洞百出，且接口不统一，没有注释没有文档，我在耗费了一定时间理解后决定弃用该代码并自寻更好的库函数支持

此外，程序验证方面，由于时间的仓促，我将一并在main函数中一一展现，而非实现一个用户界面支持功能选择

程序介绍：
没什么好介绍的，一切按照题目要求，没有额外的功能，下面将一一展现需要实现的功能

    初始化
    Stack MainStack;
    MainStack.pLQ_Main = createQueue();
    MainStack.pLQ_Sec = createQueue();
    
    学号入栈
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

    打印栈的所有元素
    StackPrint(&MainStack);

    打印能被3整除的元素
    struct QNode *pQNode = MainStack.pLQ_Main->front;
    while (pQNode != NULL)
    {
        if (pQNode->key % 3 == 0)
            printf(">%d\n", pQNode->key);
        pQNode = pQNode->next;
    }    

    获取栈顶元素并打印出来
    printf(">>%d\n", gettop(&MainStack));

    让元素值为8的元素出栈，并打印出剩下的栈元素
    pQNode = MainStack.pLQ_Main->front;
    while (pQNode->key != 8 && pQNode != NULL)
        pQNode = pQNode->next;
    pop(&MainStack, pQNode);
    StackPrint(&MainStack);

这里是输出结果：
    [9] //栈元素
    [2]
    [2]
    [1]
    [1]
    [0]
    [8]
    [0]
    [0]
    [6]
    [1]
    [2]
    >9  //被三整除
    >0
    >0
    >0
    >6
    >>9 //栈顶元素
    [9] //剩余栈元素
    [2]
    [2]
    [1]
    [1]
    [0]
    [0]
    [0]
    [6]
    [1]
    [2]

综上，使用两条队列实现栈的需求得到了实现！