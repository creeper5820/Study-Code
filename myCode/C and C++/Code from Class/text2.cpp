#include <stdio.h>

int main() {
	int a;
	printf("����һ�Ǻ�����Ҳ��\n1.lsp  2.home  3.hentai\n");
	scanf("%d", &a);
	switch (a) {
		case 1:
			printf("��ô˵�������˰ɣ�");
			break;
		case 2:
			printf("����ǰɣ���Ҳ����˵");
			break;
		case 3:
			printf("����϶��ǣ��������ʵ�");
			break;
		default:
			printf("��������ɶ�Ӷ�������");
	}
	getchar();
	return 0;
}