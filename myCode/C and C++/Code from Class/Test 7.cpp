#include <stdio.h>

int main() {
	int x;
	scanf("%d", &x);
	switch (x % 2) {
		case 1:
			printf("single");
			break;
		case 0:
			printf("double");
			break;
	}
	return 0;
}