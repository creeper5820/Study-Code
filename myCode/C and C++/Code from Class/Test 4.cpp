#include <stdio.h>

int main() { //������
	int max(int age_1, int age_2); //�Ա����ú��� max ������
	int age_1, age_2, age_max; //�������ͱ��� age_1,age_2,age_max
	scanf("%d,%d", &age_1, &age_2) //�Ӽ���������� age_1 �� age_2 ��ֵ
	age_max = max(age_1, age_2); //���� max ���������õ���ֵ���� age_max
	printf("Max is %d\n", age_max); //��� age_max ��ֵ
	return 0;
}

//�����������������еĴ��ߵĺ���
int max(int x, int y) { //���� max ����,����ֵΪ����, ��ʽ���� x �� y Ϊ����
	int z; //���屾�������õ��ı��� z Ϊ����
	if (x > y)
		z = x; //��� x>y���� x ��ֵ�������� z
	else
		z = y;
	return (z);
}