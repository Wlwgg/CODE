#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "pch.h"

typedef int Elemtype;
typedef struct {
	Elemtype *elem;
	int TableLen;
}SSTable;

void ST_Init(SSTable &ST, int len)
{
	ST.TableLen = len;
	ST.elem = (Elemtype *)malloc(sizeof(Elemtype)*ST.TableLen);
	int i;
	srand(time(NULL));
	for (i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;
	}
}

void ST_printf(SSTable ST)
{
	for (int i = 0; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}
void swap(Elemtype &a, Elemtype &b)
{
	Elemtype temp;
	temp = a;
	a = b;
	b = temp;
}
//冒泡排序
void BubbleSort(Elemtype A[], int n)
{
	int  i, j;
	bool flag;
	for (i = 0; i < n - 1; i++)
	{
		flag = false;
		for (j = n - 1; j > i; j--)
		{
			if (A[j - 1] > A[j])
			{
				swap(A[j - 1], A[j]);
				flag = true;
			}
		}
		if (flag == false)
			return;
	}
}

//快速排序
int Partition(Elemtype A[], int low, int high)
{
	Elemtype pivot = A[low];
	while (low < high)
	{
		while (low < high&&A[high] >= pivot)
		{
			--high;
		}
		A[low] = A[high];
		while (low < high&&A[low] <= pivot)
		{
			++low;
		}
		A[high] = A[low];
	}
	A[low] = pivot;
	return  low;
}

//快速排序递归实现
void QuickSort(Elemtype A[], int low, int high)
{
	if (low < high)
	{
		int pivotpos = Partition(A, low, high);//分割点左边的元素都比分割点要小，右边的比分割点大
		QuickSort(A, low, pivotpos - 1);
		QuickSort(A, pivotpos, high);
	}
}

int  main()
{
	SSTable ST;
	Elemtype A[10] = { 64, 94, 95, 79, 69, 84, 18, 22, 12 ,78 };
	ST_Init(ST, 10);//初始化
	memcpy(ST.elem, A, sizeof(A));
	ST_printf(ST);
	//BubbleSort(ST.elem, 10);
	QuickSort(ST.elem, 0, 9);
	ST_printf(ST);
	system("pause");
}



#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
typedef int Elemtype;
typedef struct {
	Elemtype *elelm;
	int TableLen;
}SSTable;

void ST_Init(SSTable &ST, int len)
{
	ST.TableLen = len;
	ST.elelm = (Elemtype*)malloc(sizeof(Elemtype)*st.tablen);
	int i;
	srand(time(null));
	for (i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;
	}
}

void ST_printf(SSTable ST)
{
	for (int i = 0; i < ST.)

}
