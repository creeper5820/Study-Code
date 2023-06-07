#include<stdio.h>
int main()
{
	int max,min;
    float t;
	printf("请输入上界(整数)\n");
	scanf("%d",&max);
	printf("请输入下界(整数)\n");
	scanf("%d",&min);
	printf("开始在该范围内搜寻x^3-3x+2=0的根\n\n");
	for(int i=min;i<+max;i++)
	{
		t=i*i*i-3*i+2;
		if(t==0)printf("x=%d是该方程的一个根\n",i);
		}	
	return 0;
}
