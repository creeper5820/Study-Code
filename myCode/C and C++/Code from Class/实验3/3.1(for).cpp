#include<stdio.h>
int main()
{
	int x1,x2,x3,k=0;
	float Y;
	for(x1=0;x1<101;x1++)
	{
	for(x2=0;x2<101-x1;x2++)
	{
		Y=3*x1+2*x2+0.5*(100-x1-x2);
		x3=100-x1-x2;
		if(Y==100){
		k++;	
		printf("���ǵ�%d�ַ�����ĸ��%dֻ������%dֻ��С��%dֻ\n",k,x1,x2,x3);
		}
	}
	}
    return 0;
}
