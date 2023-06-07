#include <stdio.h>
#include <math.h>

int main() {
	int N, M;
	int n[8], i, j;
	printf("请输入数字\n");
	scanf("%d", &N);
	M = N;
//赋值部分
	for (i = 0; i <= 8; i++) {
		j = pow(10, 8 - i);
		n[8 - i] = ((M / j) % 10);
	}
//判断位数部分
	int k = 0;
	do {
		M /= 10;
		k++;
	} while (M != 0);
//打印部分
	for (i = k - 1; i >= 0; i--) {
		switch (n[i]) {
			case 0:
				if ((i != k - 1) && (n[i - 1] == 0)
				        || i == 0
				        || i == 4
				   ) {
					break;
				} else {
					printf("零");
					break;
				}
			case 1:
				printf("壹");
				break;
			case 2:
				printf("贰");
				break;
			case 3:
				printf("叁");
				break;
			case 4:
				printf("肆");
				break;
			case 5:
				printf("伍");
				break;
			case 6:
				printf("陆");
				break;
			case 7:
				printf("柒");
				break;
			case 8:
				printf("捌");
				break;
			case 9:
				printf("玖");
				break;
		}
		switch (i) {
			case 7:
				if (n[i] != 0) {
					printf("仟");
				}
				break;
			case 6:
				if (n[i] != 0) {
					printf("佰");
				}
				break;
			case 5:
				if (n[i] != 0) {
					printf("拾");
				}
				break;
			case 4:
				printf("万");
				break;
			case 3:
				if (n[i] != 0) {
					printf("仟");
				}
				break;
			case 2:
				if (n[i] != 0) {
					printf("佰");
				}
				break;
			case 1:
				if (n[i] != 0) {
					printf("拾");
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