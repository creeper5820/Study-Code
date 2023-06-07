#include <stdio.h>
#include <string.h>

int main() {
	char a[] = "NJUST";
	char b[] = {'N', 'J', 'U', 'S', 'T'};
	printf("%s,%d\n", a, strlen(a));
	printf("%s,%d\n", b, strlen(b));
	return 0;
}
