#include <stdio.h>

int n = 20;

int a[20] = {1, 0, 9, 15, 41, 16, 15, 15, 12, 16, 58, 14, 59, 6, 5, 4, 1, 6, 8, 9};

int main() {
	int removeData(int myData[], int n);
	printf("%d", removeData(a, n));
	return 0;
}


int removeData(int myData[], int n) {
	int length = 0;
	int t[n], x = 0;
	for (int i = 0; i < n; i++)
		t[i] = myData[i];

//重复数列进一位
	for (int i = 0; i < n - x; i++)
		for (int j = i + 1; j < n - x; j++) {
			if (t[i] == t[j]) {
				x++;
				for (int k = j; k < n - x; k++)
					t[k] = t[k + 1];
			}
		}

//打印数列
	for (int i = 0; i < n - x; i++)
		printf("[%d]", t[i]);
	printf("\n数组长度为:");
	return n - x;
}