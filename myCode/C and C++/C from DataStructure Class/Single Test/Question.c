#include <stdio.h>

int main()
{
    printf("\033[32mHelloWorld\r\n\033[0m");
    printf("\033[36;36m 淡蓝 \033[0m");
    getchar();
    printf("\033[2J\033[H");
    getchar();
}