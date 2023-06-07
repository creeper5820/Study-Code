#include <stdio.h>

int main() {
	char Name[3][20];
	char Number[3][20];
	int age[3], i;
	float Heigh[3];
	for (i = 0; i < 3; i++) {
		printf("请输入第%d个同学的名字:", i + 1);
		scanf("%s", &Name[i]);
		printf("请输入第%d个同学的学号:", i + 1);
		scanf("%s", &Number[i]);
		printf("请输入第%d个同学的年龄:", i + 1);
		scanf("%d", &age[i]);
		printf("请输入第%d个同学的身高:", i + 1);
		scanf("%f", &Heigh[i]);
	}
	printf("信息如下-------------------------------------------------------------------\n\n");
	for (i = 0; i < 3; i++) {
		printf("Name:%-20s", Name[i]);
		printf("Age:%-10d", age[i]);
		printf("Number:%-18s", Number[i]);
		printf("Heigh:%-5.1f", Heigh[i]);
		printf("\n");
	}
	printf("---------------------------------------------------------------------------\n\n");
	getchar();
	getchar();
	return 0;
}