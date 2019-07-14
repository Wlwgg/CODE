#include"function.h"

/*递归实现*/
//前序遍历   abdhiejcfg
void  preOrder(BiTree p)
{
	if (p!= NULL)
	{
		putchar(p->c);
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}
//中序遍历   hdibjeafcg
void inOrder(BiTree p)
{
	if (p != NULL)
	{
		inOrder(p->lchild);
		putchar(p->c);
		inOrder(p->rchild);
	}
}

//后序遍历  hidjebfgca
void  postOrder(BiTree p)
{
	if (p != NULL) 
	{
		postOrder(p->lchild);
		postOrder(p->rchild);
		putchar(p->c);
	}
}

/*非递归调用*/
//中序遍历，非递归执行效率更高
void inOrder2(BiTree T)
{
	SqStack s;
	InitStack(s);
	BiTree p=T;
	while (p||!StackEmpty(s))
	{
		if (p)
		{
			Push(s, p);
			p = p->lchild;
		}
		else
		{
			Pop(s, p);
			putchar(p->c);
			p = p->rchild;
		}
	}
}

void LevelOrder(BiTree T)
{
	LinkQueue(Q);
	InitQueue(Q);
	BiTree p;
	EnQueue(Q,T);
	while (!IsEmpty(Q))
	{
		DeQueue(Q,p);
		putchar(p->c);
		if (p->lchild!=NULL)
		{
			EnQueue(Q,p->lchild);
		}
		if (p->rchild != NULL)
		{
			EnQueue(Q, p->rchild);
		}
	}
}

int main() 
{
	BiTree pnew;
	int i, j, pos;
	char c;
	BiTree tree = NULL;
	ptag_t phead = NULL, ptail = NULL, listpnew, pcur;
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')\
		{
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));
		pnew->c = c;
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));
		if (tree == NULL)
		{
			tree = pnew;
			phead = listpnew;
			ptail = listpnew;
			pcur = listpnew;
			continue;
		}
		else
		{
			ptail->pnext = listpnew;
			ptail = listpnew;
		}
		if (NULL == pcur->p->lchild)
		{
			pcur->p->lchild = pnew;
		}
		else if (NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;
			pcur = pcur->pnext;
		}
	}
	printf("·····前序遍历········\n");
	preOrder(tree);
	printf("·····中序遍历········\n");
	inOrder(tree);
	printf("·····后序遍历········\n");
	postOrder(tree);
	printf("·····中序遍历非递归········\n");
	inOrder2(tree);
	printf("·····层次遍历········\n");
	LevelOrder(tree);
	printf("\n");
	system("pause");

}
