#include <stdio.h>
//定义数组与个数
int n = 10;

int a[10] = {1, 1, 1, 6, 5, 5, 5, 6, 8, 9};
//主函数调用函数并输出数组长度
int main() {
	int removeData(int myData[], int n);
	int x = removeData(a, n);
	printf("%d\n", x );
	for (int i = 0; i < x; i++)
		printf("%d", a[i]);
	return 0;
}
//核心功能函数
int removeData(int myData[], int n) {
	int x, k = 0;
	for (int i = 0; i < n; i++) {
		k = 0;
		for (int j = 0; j < i; j++) {
			if (myData[i] == myData[j])
				k = 1;
		}
		if (k == 1)
			continue;
		myData[x] = myData[i];
		x++;
	}
	return x;
}
