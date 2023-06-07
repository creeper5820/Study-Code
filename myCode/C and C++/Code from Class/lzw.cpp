#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d,%d", &a, &b);
	if (a >= b)
		c = a;
	else
		c = b;
	printf("************\n");
	printf("max=%d\n", c);
	printf("************\n");
	getchar();
	getchar();
	return 0;

}