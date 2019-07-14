#include<stdio.h>
#include<stdlib.h>


#define maxszie 50
typedef  int elemtype;
typedef struct {
	elemtype data[maxszie];
	int top;
}SqStack;

//初始化栈
void InitStack(SqStack &S)
{
	S.top = -1;
}

//判断栈空
bool StackEmpty(SqStack &S)
{
	if (S.top == -1)
		return true;
	else
	{
		return false;
	}	
}

//入栈
bool Push(SqStack &S, elemtype x)
{
	if (S.top == maxszie - 1)
		return  false;
	else
	{
		S.data[++S.top] = x;
		return true;
	}

}

//出栈
bool Pop(SqStack &S, elemtype x)
{
	if (S.top == -1)
		return false;
	x= S.data[S.top--];    //x = S.data[S.top];S.top--;
	return true;
}

//读取栈顶元素
bool Gettop(SqStack &S, elemtype &x)
{
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}

//实现栈，可以用数组，也可以用链表
int main()
{
	SqStack S;
	bool flag;
	elemtype m;
	InitStack(S);
	flag = StackEmpty(S);
	if (flag)
	{
		printf("栈是空的\n");
	}
	Push(S,3);
	Push(S,4);
	Push(S,5);
	flag = Gettop(S,m);
	if (flag)
	{
		printf("获取栈顶元素为：%d",m);
	}
	flag = Pop(S, m);
	if (flag)
	{
		printf("弹出元素为：%d", m);
	}
	system("pause");

}