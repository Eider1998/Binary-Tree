#include<bits/stdc++.h>
using namespace std;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
}*BiTree;

char str[51];
int i;
BiTree build(BiTree root, char str[], int n)
{
    if(str[i++] == ',')
    {
        root = NULL;
    }
    else
    {
        root = (BiTree)malloc(sizeof(BiTNode));
        root-> data = str[i - 1];
        root-> lchild = build(root-> lchild, str, n);
        root-> rchild = build(root-> rchild, str, n);
    }
    return root;
}

void cengxu(BiTree root)
{
    BiTree b[88];
    int front, base;
    front = base = 0;
    BiTree t1;
    if(root)
    {
        b[++base] = root;
    }
    while(front != base)
    {
        t1 = b[++front];
        printf("%c", t1-> data);
        if(t1-> lchild != NULL)
        {
            b[++base] = t1-> lchild;
        }
        if(t1-> rchild != NULL)
        {
            b[++base] = t1-> rchild;
        }
    }
}

int main(void)
{
        int t;
        BiTree root;
        scanf("%d", &t);
        while(t--)
        {
            i = 0;
            scanf("%s", str);
            root = build(root, str, strlen(str));
            cengxu(root);
            printf("\n");
        }

        return 0;
}
