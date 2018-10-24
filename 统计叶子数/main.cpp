#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

char str[55];
int i, ans;

char CreateTree(BiTree &T)
{
    if(str[i++] == ',')
    {
        T = NULL;
    }

    else
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        if(!T)
        {
            exit(0);
        }

        T-> data = str[i - 1];
        CreateTree(T-> lchild);
        CreateTree(T-> rchild);
    }

    return 1;
}

int yezi(BiTree &T)
{
    if(T)
    {
        if(T-> rchild == NULL && T-> lchild == NULL)
        {
            ans++;
        }

        else
        {
            yezi(T-> lchild);
            yezi(T-> rchild);
        }
    }

    return ans;

}
int main(void)
{
    BiTree T;
    while(~scanf("%s", str))
    {
        i = 0;
        ans = 0;
        CreateTree(T);
        yezi(T);
        printf("%d\n", ans);
    }

    return 0;
}
