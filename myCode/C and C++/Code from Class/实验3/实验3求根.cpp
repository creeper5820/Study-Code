
#include <stdio.h>
#include <math.h>

//������ֵ
float F(float x) {
	float y;
	y = x * x * x - 3 * x + 2;
	return y;
}

//��������ֵ
float F1(float x) {
	float y1;
	y1 = 3 * x * x - 3;
	return y1;
}

//main����
int main() {
	int max, min;
	float x1, x2;
	printf("�������Ͻ�(����)\n");
	scanf("%d", &max);
	printf("�������½�(����)\n");
	scanf("%d", &min);
	printf("��ʼ�ڸ÷�Χ����Ѱx^3-3x+2=0 �ĸ�\n\n");
	x2 = min;
	for (int i = 0; i <= max - min; i += 10) {
		x2 += 10;
		while (fabs(x2 - x1) > 1e-6 ) {
			x1 = x2;
			x2 = x2 = x1 - F(x1) / F1(x1);
		}
		if (x2 >= min && x2 <= max)
			printf("%f\n", x2);
	}

	return 0;
}

