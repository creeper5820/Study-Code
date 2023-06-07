#include <stdio.h>

int main() {
	void soft(int a[], int n);
	int a[] = {1, 5, 9, 7, 8, 9, 5, 1, 1, 11, 10, 15, 64, 81, 15, 13, 19};
	int length = sizeof(a) / sizeof(a[0]);
	soft(a, length);
	return 0;
}

void soft(int a[], int n) {

}