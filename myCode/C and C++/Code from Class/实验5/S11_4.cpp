#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char c[] = {"Apple$12pear watermelon $ # Banana"};
	char C[10][20];
	char Max[20];
	int n = 0, m = 0, max = 0;

	//���ַ����ֳ�һ�������ʸ���C[][]
	for (int i = 0; c[i] != '\0'; i++) {
		//�ж�c[i]�Ƿ�Ϊ��ĸ
		if (c[i] > 64 && c[i] < 91 || c[i] > 96 && c[i] < 123) {
			C[n][m] = c[i];
			m++;
		}
		//�ж�c[i]Ϊ����ĸ��ǰһλΪ��ĸ
		if ((c[i - 1] > 64 && c[i - 1] < 92
		        || c[i - 1] > 96 && c[i - 1] < 124)
		        && (c[i] < 65 || c[i] > 90 && c[i] < 97 || c[i] > 122)) {
			//�ڵ���ĩβ���Ͻ�����
			C[n][m] = '\0';
			//��һ������
			n++;
			//��ʼ��m���ӵ�һλ��ʼ���¸�ֵ
			m = 0;
		}
	}
//��ӡ���������ĵ���
	for (int i = 0; i < n + 1; i++)
		cout << C[i] << endl;
//�Ƚϵ��ʵĳ��Ȳ�ѡ����ĵ���
	for (int i = 0; i < n + 1; i++)
		if (strlen(C[max]) < strlen(C[i])) {
			strcpy(Max, C[i]);
			max = i;
		}
	cout << "The longest word is:" << Max << endl;
}