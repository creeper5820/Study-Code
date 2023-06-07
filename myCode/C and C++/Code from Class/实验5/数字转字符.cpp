#include <stdio.h>
#include <math.h>

int main() {
	void getNStr(int n, char myStr[]);
	int n;
	char str[30];
	printf("Input your number please!\n-");
	scanf("%d", &n);
	getNStr(n, str);
	printf("\nThe string is:%s", str);
	return 0;
}

void getNStr(int n, char myStr[]) {
	static int i = 0;
	if (n / 10 != 0) {
		getNStr(n / 10, myStr);
		n = n - n / 10 * 10;
	}
	if (n / 10 == 0) {
		myStr[i] = n + '0';
		i++;
	}
}