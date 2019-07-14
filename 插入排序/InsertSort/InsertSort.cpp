#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;
typedef struct {
	ElemType *elem;
	int Tablelen;
}SSTable;


void ST_Init(SSTable &ST, int len)
{
	ST.Tablelen = len + 1;
	ST.elem = (ElemType *)malloc(sizeof(ElemType)*ST.Tablelen);
	int i;
	srand(time(NULL));
	for (i = 0; i < ST.Tablelen; i++)
	{
		ST.elem[i] = rand() % 100;
	}

}


void ST_Print(SSTable ST)
{
	for (int i = 0; i < ST.Tablelen; i++)
	{
		printf("%3d",ST.elem[i]);
	}
	printf("\n");
}




//插入排序，从小到大排序，升序
void InsertSort(ElemType A[], int n)
{
	int i, j;
	for (i = 2; i <= n; i++)
	{
		if (A[i] < A[j])
		{
			A[0] = A[i];
			for ( j = i-1; A[0]<A[j]; j--)
			{
				A[j + 1] = A[j];
			}
			A[j + 1] = A[0];
		}
	}
}


//折半查找 插入排序
void MidInsertSort(ElemType A[], int  n)
{
	int i, j, low, high, mid;
	for ( i = 2; i <= n; i++)
	{
		A[0] = A[i];
		low = 1, high = i - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (A[mid] > A[0])
				high = mid - 1;
			else
			{
				low = mid + 1;
			}
			for (j = i - 1; j >= high + 1; --j)
			{
				A[j + 1] = A[j];
			}
			A[high + 1] = A[0];
		}
	}
}



void ShellSort(ElemType A[], int n)
{
	int dk, i, j;
	// 73 29 74 51 29 90 37 48 72 54 83
	for (dk = n / 2; dk >= 1; dk = dk / 2)
	{
		for ( i = dk+1; i <=n; ++i)
		{
			if( A[i]<A[i-dk])
			{
				A[0] = A[i];
				for (j = i - dk; j > 0 && A[0] < A[j]; j = j - dk)
					A[j + dk] = A[j];
				A[j + dk] = A[0];
			}
		}
	}
}


int main()
{
	SSTable ST;
	ST_Init(ST, 10);
	ST_Print(ST);
	InsertSort(ST.elem, 10);
	MidInsertSort(ST.elem,10 );
	ShellSort(ST.elem, 10);
	ST_Print(ST);
	system("pause");

}
