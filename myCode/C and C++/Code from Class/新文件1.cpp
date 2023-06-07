#include <stdio.h>

int main() {
	//初始化
	int num, i = 1, j = 0, k = 0, weishu = 0;
	char num_s1[8] = {0};
	char num_s2[10][4] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};

	//获取用户输入并将每一位单独存储于数组中 （顺序为倒序）
	scanf("%d", &num);
	while (num != 0) {
		num_s1[i] = num % 10;
		num = num / 10; //循环一次去除一位
		i++;
		weishu++;
	}

	//将顺序反过来的数组num_s1顺序纠正
	char num_s3[weishu];
	while (j < weishu) {
		num_s3[j] = num_s1[weishu - j];
		j++;
	}

	//循环打印
	while (k < weishu) {
		printf("%s", num_s2[num_s3[k]]);
		switch (weishu - k) { //加单位
			case 2:
				printf("拾");
				break;
			case 3:
				printf("佰");
				break;
			case 4:
				printf("仟");
				break;
			case 5:
				printf("万");
				break;
			case 6:
				printf("拾");
				break;
			case 7:
				printf("佰");
				break;
			case 8:
				printf("仟");
				break;

		}
		k++;
	}
	printf("元整");
	return 0;
}