#include <stdio.h>
#include <stdlib.h>




//����������ݽṹ
typedef char BiElmType;
typedef struct BiTNode {
	BiElmType c;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;

typedef struct tag {
	BiTree p;
	struct  tag *pnext;
}tag_t,*ptag_t;


//ջ��������ݽṹ
#define MaxSize 50
typedef BiTree ElemType;
typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack &S);
bool StackEmpty(SqStack &S);
bool Push(SqStack &S,ElemType x);
bool Pop(SqStack &S,ElemType &x);
bool GetTop(SqStack &S,ElemType &x);



//���е�������ݽṹ
typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}LinkNode;
typedef struct{
	LinkNode *front,*rear;
}LinkQueue;
void InitQueue(LinkQueue &Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue &Q,ElemType x);
bool DeQueue(LinkQueue &Q,ElemType &x);