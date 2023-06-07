
#include <stdio.h>
#include <math.h>

//函数求值
float F(float x) {
	float y;
	y = x * x * x - 3 * x + 2;
	return y;
}

//导函数求值
float F1(float x) {
	float y1;
	y1 = 3 * x * x - 3;
	return y1;
}

//main函数
int main() {
	int max, min;
	float x1, x2;
	printf("请输入上界(整数)\n");
	scanf("%d", &max);
	printf("请输入下界(整数)\n");
	scanf("%d", &min);
	printf("开始在该范围内搜寻x^3-3x+2=0 的根\n\n");
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

