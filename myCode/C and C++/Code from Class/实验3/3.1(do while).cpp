#include<stdio.h>
int main()
{
	int x1=0,x2=0,x3=0,k=0;
	float Y=0;
    do
    {
    x2=0;
    	do
    	{
    	Y=3*x1+2*x2+0.5*(100-x1-x2);
		x3=100-x1-x2;
		if(Y==100){k++;	printf("���ǵ�%d�ַ�����ĸ��%dֻ������%dֻ��С��%dֻ\n",k,x1,x2,x3);}
		x2++;
    	}while(x2<101-x1);
	x1++;
	}while(x1<101);
    return 0;
}
