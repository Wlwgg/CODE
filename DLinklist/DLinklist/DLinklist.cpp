#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct DNode 
{
	ElemType data;
	struct DNode *piror, *next;
}DNode,*DLinklist;

/*双链表的实现*/
//双向链表头插法
DLinklist Dlist_head_insert(DLinklist &DL)
{
	DNode *s;
	int x;
	DL = (DLinklist)malloc(sizeof(DNode));
	DL->next = NULL;
	DL->piror = NULL;
	scanf("%d",&x);
	while (x!=9999)
	{
		s = (DLinklist)malloc(sizeof(DNode));
		s->data = x;
		s->next = DL->next;
		if (DL->next != NULL)
		{
			DL->next->piror = s;
		}
		s->piror = DL;
		DL->next = s;
		scanf("%d",&x);

	}
	return  DL;
}

//双向链表尾插法
DLinklist Dlist_tail_insert(DLinklist &DL)
{
	int x;
	DL = (DLinklist)malloc(sizeof(DNode));
	DNode *s,*r = DL;
	DL->piror = NULL;
	scanf("%d",&x);
	while (x != 9999)
	{
		s = (DNode*)malloc(sizeof(DNode));
		s->data = x;
		r->next = s;
		s->piror = r;
		r = s;
		scanf("%d",&x);
	}
	r->next = NULL;
	return DL;
}

//按序号查找结点值
DNode *GetElem(DLinklist DL,int i)
{
	int j = 1;
	DNode *p = DL->next;
	if (i==0)
	{
		return DL;
	}
	if (i < 1)
	{
		return NULL;
	}
	while (p&&j<i)
	{
		p = p->next;
		j++;
	}
	return p;
}

//新结点插入第i个位置
bool DListFrontInsert(DLinklist DL, int i, ElemType e)
{
	DLinklist p = GetElem(DL, e);
	if (NULL==p)
	{
		return false;
	}
	DLinklist s = (DLinklist)malloc(sizeof(DNode));
	s->data = e;
	s->next = p->next;
	p->next->piror = s;
	s->piror = p;
	p->next = s;
	return true;
}

//删除第i个结点
bool DListDelete(DLinklist DL, int i)
{
	DLinklist p = GetElem(DL, i - 1);
	if (NULL == p)
	{
		return  false;
	}
	DLinklist q;
	q = p->next;
	if (q == NULL)
		return false;
	p->next = q->next;
	if (q->next!=NULL)
	{
		q->next->piror = p;
	}
	free(q);
	return true;
}

//链表打印
void PrintDList(DLinklist DL)
{
	DL = DL->next;
	while (DL!=NULL)
	{
		printf("%d",DL);
		DL = DL->next;
	}
	printf("\n");
}


int main()
{
	DLinklist DL;
	DLinklist search;
	//Dlist_head_insert(DL);
	Dlist_tail_insert(DL);
	PrintDList(DL);
	search = GetElem(DL, 2);
		if (search!=NULL)
		{
			printf("按序号查询");
			printf("%3d\n", search->data);
		}
		DListFrontInsert(DL, 3, 99);
		PrintDList(DL);
		DListDelete(DL, 2);
		PrintDList(DL);
		system("pause");
}