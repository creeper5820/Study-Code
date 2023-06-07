#include <stdio.h>

int sum(int b[], int n) {
	int i, s = 0;
	for (int i = 0; i < n; i++)
		if (b[i] % 2 == 1)
			s = s + b[i];
	return s;
}

int main() {
	int a[12] = {10, 4, 2, 7, 3, 12, 5, 34, 5, 9, 21, 19}, n;
	n = sum(a, 12);
	printf("The result is %d\n", n);
	return 0;
}