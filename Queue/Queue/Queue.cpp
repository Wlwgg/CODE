#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;
typedef struct LinkNode {
	elemtype data;
	struct LinkNode *next;
}LinkNode;

typedef struct {
	LinkNode *front, *rear;
}Linkqueue;

//链队初始化
void InitQueue(Linkqueue &Q) 
{
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}
//判断链表是否为空
bool Isempty(Linkqueue Q)
{
	if (Q.front == Q.rear)
	{
		return true;
	}
	else
		return false;
}
//进队
void EnQueue(Linkqueue &Q,elemtype x) 
{
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}

//出队  
bool Dequeue(Linkqueue &Q,elemtype &x)
{
	if (Q.front == Q.rear)
		return false;
	LinkNode *p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return true;
}

int main() 
{
	Linkqueue Q;
	bool ret;
	elemtype  x;
	InitQueue(Q);
	EnQueue(Q,3);
	EnQueue(Q,4);
	EnQueue(Q,5);
	EnQueue(Q,6); 
	EnQueue(Q,7);
	while (Q.rear!=Q.front)
	{
		ret = Dequeue(Q,x);
		if (ret)
		{
			printf("出队成功，元素值为%d\n", x);
		}
		else
		{
			printf("出队失败");
		}
	}
	system("pause");

}