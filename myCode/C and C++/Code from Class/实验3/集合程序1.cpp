#include <stdio.h>
#include <stdlib.h>

int main() {
	int judge1( int y);
	int judge2(int Y, int M, int D);
	int year, x1, x2, x3, X;
	while (1) {
		system("cls");
		printf("���˵�\n");
		printf("������㣬������ a\n");
		printf("���ڼ��㣬������ b\n");
		printf("�˳����������� q\n");
		switch (getchar()) {
//�Ӳ˵���1��
			case 'a': {
part1:
				system("cls");
				printf("�Ӳ˵�(1) \n");
				printf("���������\n");
				printf("�˵����˵������� -1\n");
				scanf("%d", &year);
				if (year == -1)
					break;
				switch (judge1(year)) {
					case 1: {
						printf("���������\n");
						system("pause");
						goto part1;
					}
					case 0: {
						printf("�����������\n");
						system("pause");
						goto part1;
					}
					default: {
						printf("�����˸�ɶ��\n");
						system("pause");
						break;
					}
				}
				break;
			}
//�Ӳ˵���2��
			case 'b': {
part2:
				system("cls");
				printf("�Ӳ˵�(2) \n");
				printf("������������(���� 2020:10:7)\n");
				printf("�˵����˵������� -1\n");
				scanf("%d:%d:%d", &x1, &x2, &x3);
				X = judge2(x1, x2, x3);
				if (x1 == 1582 && x2 == 10 && x3 < 15 && x3 > 4) {
					printf("�����ڲ�����\n");
					system("pause");
					goto part2;
				}
				if (x1 == -1)
					break;
				switch (X) {
					case 0: {
						printf("����\n");
						system("pause");
						goto part2;
					}
					case 1: {
						printf("��һ\n");
						system("pause");
						goto part2;
					}
					case 2: {
						printf("�ܶ�\n");
						system("pause");
						goto part2;
					}
					case 3: {
						printf("����\n");
						system("pause");
						goto part2;
					}
					case 4: {
						printf("����\n");
						system("pause");
						goto part2;
					}
					case 5: {
						printf("����\n");
						system("pause");
						goto part2;
					}
					case 6: {
						printf("����\n");
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

//�����ж�����ĺ���
int judge1(int y) {
	int t;
	t = (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
	return t;
}

//�����ж������ĺ���
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