#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef  int ElemType;
typedef struct {
	ElemType *elem;
	int TableLen;
}SStable;


int Search_Seq(SStable ST, ElemType key) 
{
	ST.elem[0] = key;
	int i;
	for (i = ST.TableLen - 1; ST.elem[i] != key; i--);
	return i;
}

void ST_Init(SStable &ST, int len)
{ 
	ST.TableLen = len + 1;
	ST.elem = (ElemType*)malloc(sizeof(ElemType)*ST.TableLen);
	int i;
	srand(time(NULL));
	for ( i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;
	}
}

void ST_print(SStable ST)
{
	
	for (int  i = 0; i < ST.TableLen; i++)
	{
		printf("%3d",ST.elem[i]);
	}
	printf("\n");
}

int Binary_Search(SStable L, ElemType key)
{
	int low = 0, high = L.TableLen - 1, mid;
	while (low<=high)
	{
		mid = (low + high) / 2;
		if (L.elem[mid] == key)
			return mid;
		else if (L.elem[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int compare(const void *left, const void *right)
{
	return *(ElemType *)left - *(ElemType*)right;

}


int main()
{
	SStable ST;
	ElemType key;
	int pos;
	ST_Init(ST,10);
	ST_print(ST);
	printf("请输入要搜索的Key值：\n");
	scanf("%d",&key);
	pos = Search_Seq(ST,key);
	if (pos)
	{
		printf("查找成功 位置为 %d\n",pos);
	}
	else
	{
		printf("查找失败 \n");
	}
	qsort(ST.elem, ST.TableLen, sizeof(int), compare);
	ST_print(ST);
	printf("二分查找，请输入要搜索的Key值 :\n");
	scanf("%d", &key);

	pos = Binary_Search(ST,key);
	if (pos!=-1)
	{
		printf("查找成功 位置为 %d\n", pos);
	}
	else
	{
		printf("查找失败 \n");
	}
	system("pause");
}