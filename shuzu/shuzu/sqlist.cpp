#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
//线性表的动态分配
#define InitSize 100
typedef struct {
	ElemType *data;
	int capacity;
	int length;
}Seqlist;

//线性表的静态存储结构
#define MAXSIZE 50
typedef struct {
	ElemType data[MAXSIZE];
	int length;
}Sqlist;
	

//线性表插入操作，i为插入的位置，从1开始
bool ListInsert(Sqlist &L, int i, ElemType e)  
{
	if (i<1 || i>L.length + 1)      // 判断插入的为位置是否合法
		return false;
	if (L.length >= MAXSIZE)
		return false;
	for (int j = L.length; j >= i; j--)   //移动顺序表中的元素
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	return true;
}

//线性表删除操作
bool ListDelete(Sqlist &L, int i, ElemType &e)
{
	if (i<1 || i>L.length)
		return false;
	e = L.data[i - 1];                      // 获取顺序表中的元素
	for (int j = i; j < L.length; j++) 
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}

//按值查找
bool LocateElem(Sqlist L, ElemType e)
{
	int i;
	for (i = 1; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;
}

//打印线性表
void  PrintList(Sqlist &L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf("%4d", L.data[i]);
	}
	printf("\n");
}

int main()
{
	Sqlist L;  //顺序表的名称
	bool ret;
	ElemType del;
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;
	ret = ListInsert(L, 2, 60);
	if (ret)
	{
		printf("插入成功\n");
		PrintList(L);
	}
	else {
		printf("插入失败\n");
	}

	ret = ListDelete(L, 1, del);
	if (ret)
	{
		printf("删除成功\n");
		printf("删除元素为:%d\n", del);
		PrintList(L);
	}
	else {
		printf("删除失败\n");
	}

	ret = LocateElem(L, 60);
		if (ret)
		{
			printf("查找成功");
			printf("查找元素为：%d\n",ret);
		}
		else
		{
			printf("查找失败\n");
		}

	system("pause");//停在控制台窗口
}