#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode ,*Linklist;


//头插法新建链表
Linklist CreateList1(Linklist &L)
{
	LNode *s;
	int x;
	L = (Linklist)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d", &x);
	while (x != 9999){
		s = (LNode*)malloc(sizeof(LNode));     //申请一个节点，强制类型转换
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

//尾插法新建链表
Linklist CreateList2(Linklist &L)
{
	int x;
	L = (Linklist)malloc(sizeof(LNode));
	LNode *s, *r = L;
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d",&x);
	}
	r->next = NULL;
	return L;
}

//按序号查找结点值
LNode *GetElem(Linklist L, int i)
{
	int j = 1;
	LNode *p = L->next;
	if (i = 0)
		return L;
	if (i < 1)
		return NULL;
	while (p&& j<i)
	{
		p = p->next;
		j++;
	}
	return p;

}

//按值查找
LNode *LocteElem(Linklist L, ElemType e)
{
	LNode *p = L->next;
	while (p!=NULL&&p->data!=e)
	{
		p = p->next;
	}
	return p;
}

//新结点插入第i个位置
bool ListFrontInsert(Linklist L,int i , ElemType e)
{
	Linklist p = GetElem(L,i-1);
	if (NULL == p)
	{
		return false;
	}
	Linklist s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//删除第i个结点
bool ListDelete(Linklist L, int i){
	Linklist p = GetElem(L, i - 1);
	if (NULL == p )
	{
		return false;
	}
	Linklist q;
	q = p->next;
	p->next = q->next;
	free(q);
	return true;
}

//逆置单链表
void reverse(Linklist L)
{

	LNode *p, *q;
	p = L;
	p = p->next;
	L->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		q->next = L->next;
		L->next = q;
	}
}

//求P的直接前驱
LNode *PreLNode(Linklist L, LNode *p)
{
	LNode *q;
	q = L;
	while (q->next!=p)
	{
		q = q->next;
	}
	return q;
}

//将两个有序链表合并成一个顺序链表
Linklist MergeList(Linklist La, Linklist Lb)
{
	LNode *p, *q, *Lc, *r;
	p = La->next;
	q = Lb->next;
	Lc = r = La;
	while (p&&q)
	{
		if (p->data<=q->data)
		{
			r->next = p;
			r = r->next;
			p = p->next;
		}
		else
		{
			r->next = q;
			r = r->next;
			q = q->next;
		}
	}
	if (p)
		r->next = p;
	else
		r->next = q;
	free(Lb);
	return Lc;
}

//打印链表中每个结点的值
void PrintList(Linklist L)
{
	L = L->next;
	while (L != NULL)
	{
		printf("%3d",L->data);
		L = L->next;
	}
	printf("\n");
}


int main()
{
	Linklist L;
	Linklist search;
	CreateList1(L);   //输入数据3 4 5 6 7  9999
	//CreateList2(L);     //输入数据3 4 5 6 7 9999
	PrintList(L);
	search = GetElem(L, 2);  //按序号查找
	if (search != NULL)
	{
		printf("按序号查找成功");
		printf("%d\n",search->data);
	}
	search = LocteElem(L, 6);
	if (search != NULL);
	{
		printf("按值查找成功\n");
		printf("%d\n", search->data);
	}
	ListFrontInsert(L, 2, 99);
	printf("前插成功\n");
	PrintList(L);
	ListDelete(L,3);
	printf("删除节点\n");
	PrintList(L);
	printf("逆置链表\n");
	reverse(L);
	PrintList(L);
	system("pause");






}