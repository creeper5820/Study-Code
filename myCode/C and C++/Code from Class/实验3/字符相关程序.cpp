#include <stdio.h>
#include <string.h>

//�ָ��ߡ��������ܣ�2��
void F1(char s[]) {
	char *p = s;
	int t[30] = {0};
	//�������ղ���
	for (p = s; *p != '\0'; p++) {
		for (int i = 'A'; i <= 'Z'; i++) {
			if (*p == i || *p == i + 32)
				t[i - 64]++;
		}
		if (*p == ' ')
			t[27]++;
		if (*p != ' ' && (*p < 65 || (*p > 90 && *p < 97) || *p > 122))
			t[28]++;
	}
	//��ӡ����
	for (int k = 1; k < 27; k++)
		if (t[k] != 0)
			printf("\n%c��Ƶ��Ϊ%d", k + 64, t[k]);
	printf("\n ��Ƶ��Ϊ%d", t[27]);
	printf("\n�����ַ���Ƶ��Ϊ%d", t[28]);
}

//�ָ��ߡ������������ܣ�3��
void F2(char s[]) {
	char *p = s;
	int count = 0, word, num;
	if (*p == ' ')
		for (; *p == ' '; p++);
	p--;
	*p = ' ';
	for (; *p != '\0'; p++) {
		if (*p == ' ')
			word = 0;
		else if (word == 0) {
			word = 1;
			num++;
		}
		if (((*(p - 1) == ' ') || (*(p - 1) == ','))
		        && (*p == 't' || *p == 'T')
		        && (*(p + 1) == 'h')
		        && (*(p + 2) == 'e')
		        && ((*(p + 3) == ' ') || (*(p + 3) == ',') || (*(p + 3) == '\0')) ) {
			printf("λ��[%d]", num);
			count++;
		}
	}
	printf("\nthe ������%d", count);
}//�ָ��ߡ���������������

int main() {
	char string[81];
	gets(string);
	F2(string);
	F1(string);
	return 0;
}

