#include <stdio.h>

int main() {
	int m, c;
	printf("�ó��������жϼ��ڣ�����#ʱֹͣ\n");
	do {
		printf("�������·�\n");
		scanf("%d", &m);
		switch ( m / 3) {

			case 1: {
				printf("֥ʿ�����򴺼�\n");
				break;
			}
			case 2: {
				printf("֥ʿ�������ļ�\n");
				break;
			}
			case 3: {
				printf("֥ʿ�������＾\n");
				break;
			}
			case 0:
			case 4: {
				printf("֥ʿ�����򶬼�\n");
				break;
			}

		}
	} while ((c = getchar() ) != '#');
	return 0;
}


