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
		if(Y==100){k++;	printf("这是第%d种方案：母鸡%d只，公鸡%d只，小鸡%d只\n",k,x1,x2,x3);}
		x2++;
    	}while(x2<101-x1);
	x1++;
	}while(x1<101);
    return 0;
}
