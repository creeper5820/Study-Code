#include <stdio.h>
#include <math.h>

int main() {
	int N, M;
	int n[8], i, j;
	printf("����������\n");
	scanf("%d", &N);
	M = N;
//��ֵ����
	for (i = 0; i <= 8; i++) {
		j = pow(10, 8 - i);
		n[8 - i] = ((M / j) % 10);
	}
//�ж�λ������
	int k = 0;
	do {
		M /= 10;
		k++;
	} while (M != 0);
//��ӡ����
	for (i = k - 1; i >= 0; i--) {
		switch (n[i]) {
			case 0:
				if ((i != k - 1) && (n[i - 1] == 0)
				        || i == 0
				        || i == 4
				   ) {
					break;
				} else {
					printf("��");
					break;
				}
			case 1:
				printf("Ҽ");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
		}
		switch (i) {
			case 7:
				if (n[i] != 0) {
					printf("Ǫ");
				}
				break;
			case 6:
				if (n[i] != 0) {
					printf("��");
				}
				break;
			case 5:
				if (n[i] != 0) {
					printf("ʰ");
				}
				break;
			case 4:
				printf("��");
				break;
			case 3:
				if (n[i] != 0) {
					printf("Ǫ");
				}
				break;
			case 2:
				if (n[i] != 0) {
					printf("��");
				}
				break;
			case 1:
				if (n[i] != 0) {
					printf("ʰ");
				}
				break;
			case 0:
				break;
		}
	}
	printf("\n");
	system("pause");
	return 0;
}