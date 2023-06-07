#include <stdio.h>

int main() {
	int a;
	printf("霍博一是何许人也？\n1.lsp  2.home  3.hentai\n");
	scanf("%d", &a);
	switch (a) {
		case 1:
			printf("这么说便宜他了吧？");
			break;
		case 2:
			printf("大概是吧，咱也不好说");
			break;
		case 3:
			printf("这个肯定是，毫无疑问的");
			break;
		default:
			printf("你输入了啥子东西啊？");
	}
	getchar();
	return 0;
}