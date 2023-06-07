#include <stdio.h>
#include <math.h>

int main() {
	int i = 1, k = 0;
	do {
		if (i % 7 == 0 || i / 10 == 7 || i % 10 == 7) {
			printf("敲桌子%d\n", i);
			k++;
		}
		i++;
	} while (i < 100);
	printf("一共敲了%d桌子", k);
	return 0;
}