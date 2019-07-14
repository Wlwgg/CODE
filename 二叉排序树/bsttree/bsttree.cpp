#include<stdio.h>
#include<stdlib.h>

typedef int KeyType;
typedef struct BSTNode {
	KeyType key;
	struct BSTNode *lchild, *rchild;
}BSTNode,*BiTree;



int BST_Insert(BiTree &T, KeyType k)
{
	if (NULL == T)
	{
		T = (BiTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return 1;
	}
	else if (k == T->key)
		return 0;
	else if (k < T->key)
		return BST_Insert(T->lchild,k);
	else
		return BST_Insert(T->rchild, k);
}


//创建二叉排序树
void Creat_BST(BiTree &T, KeyType str[], int n)
{
	T == NULL;
	int i = 0;
	while (i<n)
	{
		BST_Insert(T, str[i]);
		i++;
	}
}

BSTNode *BST_Search(BiTree T, KeyType key, BiTree &p)
{
	p = NULL;
	while (T!=NULL&&key!=T->key)
	{
		p = T;
		if (key<T->key)
		{
			T = T->lchild;
		}
		else
		{
			T = T->rchild;
		}
	}
	return T;

}



void DeleteNode(BiTree &root, KeyType x)
{
	if (root == NULL)
		return;
	if (root->key>x)
	{
		DeleteNode(root->lchild,x);
	}
	else if (root->key < x)
	{
		DeleteNode(root->rchild, x);
	}
	else
	{
		if (root->lchild==NULL)
		{
			BiTree tempNode = root;
			root = root->rchild;
			free(tempNode);
		}
		else if(root->rchild==NULL)
		{
			BiTree tempNode = root;
			root = root->lchild;
			free(tempNode);
		}
		else 
		{
			BiTree  tempNode = root->lchild;
			if (tempNode->rchild!=NULL)
			{
				tempNode = tempNode->rchild;
			}
			root->key = tempNode->key;
			DeleteNode(root->lchild,tempNode->key);
		}
	}
}

void InOrder(BiTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		printf("%3d", T->key);
		InOrder(T->rchild);
	}
}


int main() 
{
	BiTree T;
	BiTree parent;
	BiTree search;
	KeyType str[] = {54,20,66,40,28,79,58};
	Creat_BST(T,str,7);
	InOrder(T);
	printf("\n");
	search = BST_Search(T,41,parent);
	if (search)
	{
		printf("找到对应节点，值=%d\n",search->key);
	}
	else
	{
		printf("找到对应节点\n");
	}
	DeleteNode(T,40);
	InOrder(T);
	printf("\n");
	system("pause");
}

