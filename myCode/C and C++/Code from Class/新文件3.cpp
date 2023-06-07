#include <stdio.h>
#include <math.h>

int main() {
	int N, M;
	int n[8], i, j;
	printf("ÇëÊäÈëÊı×Ö\n");
	scanf("%d", &N);
	M = N;
	for (i = 0; i <= 8; i++) {
		j = pow(10, 8 - i);
		n[8 - i] = ((N / j) % 10);
	}
	int k ;
	do {
		M /= 10;
		k++;
	} while (M != 0);
	return 0;
}