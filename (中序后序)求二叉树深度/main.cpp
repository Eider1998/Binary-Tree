#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;

}BiTNode, *BiTree;

char in[110], post[110];

BiTNode *CreatTree(char in[], char post[], int i)
{
    if(!i)
    {
        return NULL;
    }
    BiTree l;
    int j;
    l = (BiTNode *)malloc(sizeof(BiTNode));
    l-> data = post[i - 1];
    for(j = 0; j < i; j++)
    {
        if(in[j] == post[i - 1])
        {
            break;
        }
    }

    l-> lchild = CreatTree(in, post, j);
    l-> rchild = CreatTree(in + j + 1, post + j, i - j - 1);
    return l;
}

int shendu(BiTree &l)
{
    if(l == NULL)
    {
        return 0;
    }

    int len1 = shendu(l-> lchild);
    int len2 = shendu(l-> rchild);
    return len1 > len2 ? len1 + 1 : len2 + 1;
}

int main(void)
{
    int t, m, i;
    BiTree l;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", in);
        scanf("%s", post);
        i = strlen(in);
        l = CreatTree(in, post, i);
        m = 0;
        m = shendu(l);
        printf("%d\n", m);
    }

    return 0;

}
