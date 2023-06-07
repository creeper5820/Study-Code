#include <stdio.h>

int main()
{
    int Fibonacci(int N);
    for(int i=0; i<50; i++)
    printf("%d\n",Fibonacci(i));

    return 0;
}

// Fibonacci sequence
int Fibonacci(int N)
{
    switch (N)
    {
    case 0:
        return 0;
        break;

    case 1:
        return 1;
        break;

    default:
        return Fibonacci(N - 1) + Fibonacci(N - 2);
        break;
    }
}