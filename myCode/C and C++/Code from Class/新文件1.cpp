#include <stdio.h>

int main() {
	//��ʼ��
	int num, i = 1, j = 0, k = 0, weishu = 0;
	char num_s1[8] = {0};
	char num_s2[10][4] = {"��", "Ҽ", "��", "��", "��", "��", "½", "��", "��", "��"};

	//��ȡ�û����벢��ÿһλ�����洢�������� ��˳��Ϊ����
	scanf("%d", &num);
	while (num != 0) {
		num_s1[i] = num % 10;
		num = num / 10; //ѭ��һ��ȥ��һλ
		i++;
		weishu++;
	}

	//��˳�򷴹���������num_s1˳�����
	char num_s3[weishu];
	while (j < weishu) {
		num_s3[j] = num_s1[weishu - j];
		j++;
	}

	//ѭ����ӡ
	while (k < weishu) {
		printf("%s", num_s2[num_s3[k]]);
		switch (weishu - k) { //�ӵ�λ
			case 2:
				printf("ʰ");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("Ǫ");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("ʰ");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("Ǫ");
				break;

		}
		k++;
	}
	printf("Ԫ��");
	return 0;
}