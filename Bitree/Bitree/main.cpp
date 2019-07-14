#include "function.h"

//递归实现
//abdhiejcfg
void preOrder(BiTree p)
{
	if(p!=NULL)
	{
		putchar(p->c);//等价于visit函数
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}
//中序遍历  hdibjeafcg
void InOrder(BiTree p)
{
	if(p!=NULL)
	{
		InOrder(p->lchild);
		putchar(p->c);
		InOrder(p->rchild);
	}
}
//hidjebfgca
void PostOrder(BiTree p)
{
	if(p!=NULL)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		putchar(p->c);
	}
}
//中序遍历非递归，非递归执行效率更高
void InOrder2(BiTree T)
{
	SqStack S;
	InitStack(S);BiTree p=T;
	while(p||!StackEmpty(S))//逻辑或||
	{
		if(p)
		{
			Push(S,p);
			p=p->lchild;
		}else{
			Pop(S,p);putchar(p->c);
			p=p->rchild;
		}
	}
}
//层次遍历,广度优先遍历
void LevelOrder(BiTree T)
{
	LinkQueue Q;
	InitQueue(Q);
	BiTree p;
	EnQueue(Q,T);//树根入队
	while(!IsEmpty(Q))
	{
		DeQueue(Q,p);
		putchar(p->c);
		if(p->lchild!=NULL)
			EnQueue(Q,p->lchild);
		if(p->rchild!=NULL)
			EnQueue(Q,p->rchild);
	}
}
//《龙哥带你撸代码》课程
//二叉树的建树（层次建树），前序、中序、后序遍历、中序非递归遍历、层次遍历
int main()
{
	BiTree pnew;
	int i,j,pos;
	char c;
	BiTree tree=NULL;//树根
	ptag_t phead=NULL,ptail=NULL,listpnew,pcur;
	//abcdefghij
	while(scanf("%c",&c)!=EOF)
	{
		if(c=='\n')
		{
			break;
		}
		pnew=(BiTree)calloc(1,sizeof(BiTNode));//calloc申请空间并对空间进行初始化，赋值为0
		pnew->c=c;
		listpnew=(ptag_t)calloc(1,sizeof(tag_t));
		listpnew->p=pnew;
		if(NULL==tree)
		{
			tree=pnew;//树的根
			phead=listpnew;//链表头
			ptail=listpnew;//链表尾
			pcur=listpnew;
			continue;
		}else{
			ptail->pnext=listpnew;//新结点放入链表，通过尾插法
			ptail=listpnew;
		}
		if(NULL==pcur->p->lchild)
		{
			pcur->p->lchild=pnew;
		}else if(NULL==pcur->p->rchild)
		{
			pcur->p->rchild=pnew;
			pcur=pcur->pnext;
		}
	}
	printf("--------前序遍历----------\n");
	preOrder(tree);
	printf("\n--------中序遍历------------\n");
	InOrder(tree);
	printf("\n--------后序遍历------------\n");
	PostOrder(tree);
	printf("\n--------中序遍历非递归------\n");
	InOrder2(tree);
	printf("\n--------层次遍历-----------\n");
	LevelOrder(tree);
	printf("\n");
	system("pause");
} 