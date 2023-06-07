#include <stdio.h>

int main() { //主函数
	int max(int age_1, int age_2); //对被调用函数 max 的声明
	int age_1, age_2, age_max; //定义整型变量 age_1,age_2,age_max
	scanf("%d,%d", &age_1, &age_2) //从键盘输入变量 age_1 和 age_2 的值
	age_max = max(age_1, age_2); //调用 max 函数，将得到的值赋给 age_max
	printf("Max is %d\n", age_max); //输出 age_max 的值
	return 0;
}

//下面是求两个整数中的大者的函数
int max(int x, int y) { //定义 max 函数,函数值为整型, 形式参数 x 和 y 为整型
	int z; //定义本函数中用到的变量 z 为整型
	if (x > y)
		z = x; //如果 x>y，则将 x 的值赋给变量 z
	else
		z = y;
	return (z);
}