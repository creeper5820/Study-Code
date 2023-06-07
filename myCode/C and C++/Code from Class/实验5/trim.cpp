#include <stdio.h>

int main() {
	void trim_left(char myData[]);
	void trim_right(char myData[]);
	void trim(char myData[]);
	char string[100] = " 123\r\n  1 ";
	trim(string);
	printf("%s", string);
	printf("|分界线");
	return 0;
}


void trim_left(char myData[]) {
	int k = 0;
//错位赋值
	for (int i = 0; myData[i] != '\0'; i++) {
		if (myData[i] != '\n' && myData[i] != '\r') {
			myData[k] = myData[i];
			k++;
		}
	}
}

void trim_right(char myData[]) {
	int i, j, k = 0;
//错位赋值
	for (; myData[i] != '\0'; i++) {
		if (myData[i] != '\n' && myData[i] != '\r') {
			myData[k] = myData[i];
			k++;
		}
	}
//去除右边空格
	for (j = k; myData[j - 1] == ' '; j--);
	myData[j] = '\0';
}

void trim(char myData[]) {
	trim_right(myData);
//计算左边空格数
	int i;
	for (i = 0; myData[i] == ' '; i++);
//去除左边空格
	for (int j = 0; j < i; j++)
		for (int k = 0; myData[k] != '\0'; k++)
			myData[k] = myData[k + 1];
}