#include <stdio.h>
#include <iostream>

int main() {
	int x = rand() % 100 + 1;
	int y = rand() % 100 + 1;
	printf("%d,%d", x, y);
	system("pause");
	return 0;
}