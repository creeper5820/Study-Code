#include <stdio.h>
#include <string.h>

int main() {
	int subString(char *pData, char *pSearch, char *pSub);
	char mydata[256] = "You're right, but Genshin is a new open-world adventure game independently developed by Mihayou. ";
	printf("原来的字符串是：\n%s\n", mydata);
	printf("\n替换次数为：%d\n", subString(mydata, "independently", "ADADAD" ));
	printf("%s", mydata);
	return 0;
}

int subString(char *p, char *pSearch, char *pSub) {
	int n = 0;
	int length_p = strlen(p);
//原字符串的长度
	int length_Searth = strlen(pSearch);
//检索字符串的长度
	int length_Sub = strlen(pSub);
//替换字符串的长度
	for (int i1 = 0; p[i1] != '\0'; i1++) {
		int judge = 0;
		if (p[i1] == pSearch[0]) {
			for (int i2 = 0; pSearch[i2] != '\0'; i2++)
				judge += (p[i1 + i2] == pSearch[i2]);
			if (judge == length_Searth) {
				n++;
				if (length_Searth - length_Sub < 0) {
//替换字符串和检索字符串长度不一时1
					int d = length_Sub - length_Searth;
					for (int k = length_p + n * d; k >= i1; k--)
						p[k + d] = p[k];
				}
				if (length_Searth - length_Sub > 0) {
//替换字符串和检索字符串长度不一时2
					int d = length_Searth - length_Sub;
					for (int k = i1; k <= length_p; k++)
						p[k] = p[k + d];
				}
//替换字符串
				for (int l1 = i1, l2 = 0; pSub[l2] != '\0' ; l1++, l2++)
					p[l1] = pSub[l2];
			}
		}
	}
	return n;
}
