#include <stdio.h>

int main() {
	void trim_left(char myData[]);
	void trim_right(char myData[]);
	void trim(char myData[]);
	char string[100] = " 123\r\n  1 ";
	trim(string);
	printf("%s", string);
	printf("|�ֽ���");
	return 0;
}


void trim_left(char myData[]) {
	int k = 0;
//��λ��ֵ
	for (int i = 0; myData[i] != '\0'; i++) {
		if (myData[i] != '\n' && myData[i] != '\r') {
			myData[k] = myData[i];
			k++;
		}
	}
}

void trim_right(char myData[]) {
	int i, j, k = 0;
//��λ��ֵ
	for (; myData[i] != '\0'; i++) {
		if (myData[i] != '\n' && myData[i] != '\r') {
			myData[k] = myData[i];
			k++;
		}
	}
//ȥ���ұ߿ո�
	for (j = k; myData[j - 1] == ' '; j--);
	myData[j] = '\0';
}

void trim(char myData[]) {
	trim_right(myData);
//������߿ո���
	int i;
	for (i = 0; myData[i] == ' '; i++);
//ȥ����߿ո�
	for (int j = 0; j < i; j++)
		for (int k = 0; myData[k] != '\0'; k++)
			myData[k] = myData[k + 1];
}