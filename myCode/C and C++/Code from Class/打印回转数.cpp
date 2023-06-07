#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	int N = 1;
	scanf("%d", &n);
	system("cls");
	int a[100][100] = {0};
	int k1, k2, k3, k4;
	//以一圈为一个循环
	for (int i = 1; i <= (n + 1) / 2; i++) {
		for (k1 = i; k1 <= n - i + 1; k1++) {
			a[i][k1] = N++;
		}
		for (k2 = i + 1; k2 <= n -  i + 1; k2++) {
			a[k2][n + 1 - i] = N++;
		}
		for (k3 = n - i ; k3 >= i; k3--) {
			a[n + 1 - i][k3] = N++;
		}
		for (k4 = n -  i ; k4 >= i + 1; k4--) {
			a[k4][i] = N++;
		}
	}
//打印数组
	for (int j = 1; j <= n; j++) {
		for (int l = 1; l <= n; l++)
			printf("[%-2d]", a[j][l]);
		printf("\n\n");
	}
	return 0;
}
