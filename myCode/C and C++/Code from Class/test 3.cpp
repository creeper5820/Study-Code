#include <stdio.h>

int main() {
	char a[5][10];
	int i;
	for (i = 1; i < 5; i++) {
		scanf("%s", a[i]);
	}
	i = 1;
	printf("%s", a[i]);
	return 0;
}