#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

char pre[110], in[110];
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTree creat(int n, char pre[], char in[])
{
    if(!n)
    {
        return NULL;
    }

    BiTree T;
    int i;
    T = (BiTNode *)malloc(sizeof(BiTNode));
    T-> data = *pre;
    for(i = 0; i < n; i++)
    {
        if(*pre == in[i])
        {
            break;
        }
    }

    T-> lchild = creat(i, pre + 1, in);
    T-> rchild = creat(n - i - 1, pre + 1 + i, in + 1 + i);
    return T;
}

int findtree(BiTNode *T)
{
   if(T == NULL)
   {
       return 0;
   }

   int len1 = findtree(T-> lchild);
   int len2 = findtree(T-> rchild);
   return len1 > len2?len1 + 1:len2 + 1;
}

int main(void)
{
    int n, t;
    BiTree T;

    while(~scanf("%d", &n))
    {
        scanf("%s", pre);
        scanf("%s", in);
        T = creat(n, pre, in);
        t = findtree(T);
        printf("%d\n", t);
    }

    return 0;
}
