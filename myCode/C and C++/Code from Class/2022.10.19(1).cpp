#include <stdio.h>
#include <math.h>

int main() {
	int i = 1, k = 0;
	do {
		if (i % 7 == 0 || i / 10 == 7 || i % 10 == 7) {
			printf("������%d\n", i);
			k++;
		}
		i++;
	} while (i < 100);
	printf("һ������%d����", k);
	return 0;
}