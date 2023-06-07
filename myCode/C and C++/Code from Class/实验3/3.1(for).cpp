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
		printf("这是第%d种方案：母鸡%d只，公鸡%d只，小鸡%d只\n",k,x1,x2,x3);
		}
	}
	}
    return 0;
}
