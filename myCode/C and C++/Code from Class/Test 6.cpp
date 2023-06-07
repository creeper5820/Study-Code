#include <stdio.h>

int main() {
	int  n, i, j, k;
	float x, Sum = 0;
	printf("请输入x的值:");
	scanf("%f", &x);
	printf("请输入n的值:");
	scanf("%d", &n);
	if (n < 2)
		Sum = 1.0 / (2 * x);
	else {
		switch (n % 2) {
			case 1: {
				k = 1, j = 1;
				Sum = 1.0 / (2 * x);
				for (i = 1; i <= (n - 1) / 2; i++) {
					k = k + j;
					j = j + k;
					Sum = Sum - k * x / j + j / ((k + j) * x);
				}
				break;
			}
			case 0: {
				k = 1, j = 2;
				for (i = 1; i <= n / 2; i++) {
					Sum = Sum + k / (j * x) - j * x / (j + k);
					k = k + j;
					j = j + k;
				}
				break;
			}
		}
	}
	printf("Sum is %.3f", Sum);
	return 0;
}