#include <stdio.h>
#include <stdlib.h>

int main() {
	int judge1( int y);
	int judge2(int Y, int M, int D);
	int year, x1, x2, x3, X;
	while (1) {
		system("cls");
		printf("主菜单\n");
		printf("闰年计算，请输入 a\n");
		printf("星期计算，请输入 b\n");
		printf("退出程序请输入 q\n");
		switch (getchar()) {
//子菜单（1）
			case 'a': {
part1:
				system("cls");
				printf("子菜单(1) \n");
				printf("请输入年份\n");
				printf("退到主菜单请输入 -1\n");
				scanf("%d", &year);
				if (year == -1)
					break;
				switch (judge1(year)) {
					case 1: {
						printf("这个是闰年\n");
						system("pause");
						goto part1;
					}
					case 0: {
						printf("这个不是闰年\n");
						system("pause");
						goto part1;
					}
					default: {
						printf("你输了个啥？\n");
						system("pause");
						break;
					}
				}
				break;
			}
//子菜单（2）
			case 'b': {
part2:
				system("cls");
				printf("子菜单(2) \n");
				printf("请输入年月日(例如 2020:10:7)\n");
				printf("退到主菜单请输入 -1\n");
				scanf("%d:%d:%d", &x1, &x2, &x3);
				X = judge2(x1, x2, x3);
				if (x1 == 1582 && x2 == 10 && x3 < 15 && x3 > 4) {
					printf("该日期不存在\n");
					system("pause");
					goto part2;
				}
				if (x1 == -1)
					break;
				switch (X) {
					case 0: {
						printf("周日\n");
						system("pause");
						goto part2;
					}
					case 1: {
						printf("周一\n");
						system("pause");
						goto part2;
					}
					case 2: {
						printf("周二\n");
						system("pause");
						goto part2;
					}
					case 3: {
						printf("周三\n");
						system("pause");
						goto part2;
					}
					case 4: {
						printf("周四\n");
						system("pause");
						goto part2;
					}
					case 5: {
						printf("周五\n");
						system("pause");
						goto part2;
					}
					case 6: {
						printf("周六\n");
						system("pause");
						goto part2;
					}
				}
			}
			break;
			case 'q': {
				return 0;
				break;
			}
		}
	}
	return 0;
}

//用于判断闰年的函数
int judge1(int y) {
	int t;
	t = (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
	return t;
}

//用于判断周数的函数
int judge2(int Y, int M, int D) {
	int w, c, y, m, d;
	c = (Y / 100);
	y = (Y - Y / 100 * 100);
	if (M < 3) {
		y = Y - 1;
		m = M + 12;
	} else {
		m = M;
	}
	d = D;
	if (Y < 1582
	        || (Y == 1582 && M < 10)
	        || (Y == 1582 && M == 10 && D <= 4)) {
		w = (y + (int)(y / 4) + (int)(c / 4) - 2 * c + (int)(13 * (m + 1) / 5) + d + 2) % 7;
	} else {
		w = ((int)(c / 4) - 2 * c + y + (int)(y / 4) + (int)(13 * (m + 1) / 5) + d - 1) % 7;
		if (w < 0) {
			w = w + 7;
		}
	}
	return w;
}