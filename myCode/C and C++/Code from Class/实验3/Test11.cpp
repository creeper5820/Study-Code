

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(0));
	char Num[11][29];
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 30; j++) {
			if (j % 6 == 0)
				Num[i][j] = '-';
			else {
				int N = rand() % 36;
				if (N < 10)
					Num[i][j] = N + 48;
				if (N >= 10)
					Num[i][j] = N + 55;
			}
		}
	}
	for (int i = 1; i < 11; i++) {
		for (int k = 1; k < 30; k++)
			printf("%c", Num[i][k]);
		printf("\n");
	}
	return 0;
}
