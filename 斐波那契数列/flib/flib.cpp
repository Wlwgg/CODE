#include<stdio.h>
#include<stdlib.h>



int flib(int x)
{
	if (x == 0)
		return 0;
	else if (x==1)
	{
		return 1;
	}
	else 
	{
		return flib(x - 1) + flib(x - 1);
	}

}

int main()
{
	int x,a;
	printf("请输入斐波齐列数：");
	scanf("%d",&x);
	a=flib(x);
	printf("输出斐波齐列数为：%d",a);
}
