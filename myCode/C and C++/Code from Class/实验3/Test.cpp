#include<stdio.h>
int main()
{
	int max,min;
    float t;
	printf("�������Ͻ�(����)\n");
	scanf("%d",&max);
	printf("�������½�(����)\n");
	scanf("%d",&min);
	printf("��ʼ�ڸ÷�Χ����Ѱx^3-3x+2=0�ĸ�\n\n");
	for(int i=min;i<+max;i++)
	{
		t=i*i*i-3*i+2;
		if(t==0)printf("x=%d�Ǹ÷��̵�һ����\n",i);
		}	
	return 0;
}
