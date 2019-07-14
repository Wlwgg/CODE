#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char* SString;

//暴力比对
//S abcabaaabaabcac
//T abaabcac

int Index(SString S,SString T)
{
	int i=1, j=1;
	while (i<=S[0]&&j<=T[0])
	{
		if (S[i] == T[j])
		{
			++i, ++j;
		}
		else
		{
			i = i - j + 2, j = 1;
		}
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}


void get_next(char T[], int next[])
{
	int i = 1;
	next[1] = 0;
	int  j = 0;
	//abaabcac
	while (i<T[0])
	{
		if (j == 0 || T[i] == T[j])
		{
			++i, ++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

int KMP(char S[], char T[], int next[], int pos)
{
	int i = pos;
	int j = 1;
	while (i < S[0] && j <= T[0])
	{
		if (j == 0 || S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	if (j > T[0])
		return i - T[0];
	else
	{
		return 0;
	}
}



int main()
{
	char S[256];
	char T[10];
	int next[10];
	int pos;
	S[0] = strlen("abcabaaabaabcac");
	strcpy(S + 1, "abcabaaabaabcac");
	T[0] = strlen("abaabcac");
	strcpy(T + 1, "abaabcac");
	pos = Index(S, T);
	if (pos)
	{
		printf("匹配成功，位置为%d\n",pos);
	}
	else
	{
		printf("未匹配");
	}
	get_next(T, next);
	pos = KMP(S, T, next, 1);
	if (pos)
	{
		printf("匹配成功，位置为%d\n", pos);
	}
	else
	{
		printf("未匹配");
	}
	system("pause");
}
