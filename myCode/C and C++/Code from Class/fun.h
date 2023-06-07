#include <stdio.h>


void mySort(float score[ ], int n, int mode) {

	if (mode == 0)
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < n - 1 - j; j++) {
				if (score[j] > score[j + 1]) {
					float temp = 0;
					temp = score[j];
					score[j] = score[j + 1];
					score[j] = temp;
				}
			}
	if (mode == 1)
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < n - 1 - i; j++) {
				if (score[j] < score[j + 1]) {
					float temp = 0;
					temp = score[j];
					score[j] = score[j + 1];
					score[j + 1] = temp;
				}
			}

	printf("该组成绩排序为：\n");
	for (int i = 1; i < n + 1; i++) {
		printf("[%2.1f] ", score[i - 1]);
		if (i % 5 == 0)
			printf("\n");
	}
}
int G_myval = 100;