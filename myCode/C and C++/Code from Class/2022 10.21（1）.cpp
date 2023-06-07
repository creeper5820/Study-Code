#include <stdio.h>

int main() {
	int m, c;
	printf("该程序用于判断季节，输入#时停止\n");
	do {
		printf("请输入月份\n");
		scanf("%d", &m);
		switch ( m / 3) {

			case 1: {
				printf("芝士北半球春季\n");
				break;
			}
			case 2: {
				printf("芝士北半球夏季\n");
				break;
			}
			case 3: {
				printf("芝士北半球秋季\n");
				break;
			}
			case 0:
			case 4: {
				printf("芝士北半球冬季\n");
				break;
			}

		}
	} while ((c = getchar() ) != '#');
	return 0;
}


