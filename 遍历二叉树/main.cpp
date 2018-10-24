#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

char str[55];
int i;

char CreateTree(BiTree T)
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

void inorder(BiTree &T)
{
    if(T)
    {
        inorder(T-> lchild);
        printf("%c", T-> data);
        inorder(T-> rchild);
    }
}

void postorder(BiTree &T)
{
    if(T)
    {
        postorder(T-> lchild);
        postorder(T-> rchild);
        printf("%c", T-> data);
    }
}

int main(void)
{
    BiTree T;
    while(~scanf("%s", str))
    {
        i = 0;
        CreateTree(T);
        inorder(T);
        printf("\n");
        postorder(T);
        printf("\n");
    }

    return 0;
}
