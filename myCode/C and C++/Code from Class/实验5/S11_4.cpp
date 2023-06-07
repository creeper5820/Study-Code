#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char c[] = {"Apple$12pear watermelon $ # Banana"};
	char C[10][20];
	char Max[20];
	int n = 0, m = 0, max = 0;

	//将字符串分成一个个单词赋给C[][]
	for (int i = 0; c[i] != '\0'; i++) {
		//判断c[i]是否为字母
		if (c[i] > 64 && c[i] < 91 || c[i] > 96 && c[i] < 123) {
			C[n][m] = c[i];
			m++;
		}
		//判断c[i]为非字母且前一位为字母
		if ((c[i - 1] > 64 && c[i - 1] < 92
		        || c[i - 1] > 96 && c[i - 1] < 124)
		        && (c[i] < 65 || c[i] > 90 && c[i] < 97 || c[i] > 122)) {
			//在单词末尾填上结束符
			C[n][m] = '\0';
			//下一个单词
			n++;
			//初始化m，从第一位开始重新赋值
			m = 0;
		}
	}
//打印出来单个的单词
	for (int i = 0; i < n + 1; i++)
		cout << C[i] << endl;
//比较单词的长度并选出最长的单词
	for (int i = 0; i < n + 1; i++)
		if (strlen(C[max]) < strlen(C[i])) {
			strcpy(Max, C[i]);
			max = i;
		}
	cout << "The longest word is:" << Max << endl;
}