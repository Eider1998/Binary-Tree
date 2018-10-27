#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#define Null -1
using namespace std;

struct Tree
{
    char name;
    int left, right;
};

Tree ary1[100], ary2[110];
int creat_tree(Tree ary[], int n)
{
    int i, test[100];
    char ml, qr, name;
    for(i = 0; i < n; i++)
    {
        test[i] = 1;
    }
    for(i = 0; i < n; i++)
    {
        cin >> name >> ml >> qr;
        ary[i].name = name;
        if(ml != '-')
        {
            ary[i].left = ml - '0';
            test[ary[i].left] = 0;
        }

        else
        {
            ary[i].left = -1;
        }

        if(qr != '-')
        {
            ary[i].right = qr - '0';
            test[ary[i].right] = 0;
        }

        else
        {
            ary[i].right = -1;
        }
    }


    i = 0;
    while(!test[i])
    {
        i++;
    }

    return i;
}

int check_node(int a, int b)
{
    Tree t1 = ary1[a];
    Tree t2 = ary2[b];
    if(a == Null && b == Null)
    {
        return 1;
    }

    else if(a != Null && b != Null)
    {
        if(ary1[a].name != ary2[b].name)
        {
            return 0;
        }

        else
        {
            if(ary1[t1.left].name == ary2[t2.left].name)
            {
                return check_node(t1.right, t2.right);
            }

            else
            {
                return check_node(t1.left, t2.right) && check_node(t1.right, t2.left);
            }
        }
    }

    else
    {
        return 0;
    }


}

int main(void)
{
    int n1, n2, t1, t2;
    while(~scanf("%d", &n1))
    {
        if(!n1)
        {
            scanf("%d", &n2);
            if(!n2)
            {
                printf("Yes\n");
            }

            else
            {
                printf("No\n");
            }
        }

        else
        {
            t1 = creat_tree(ary1, n1);
            scanf("%d", &n2);
            t2 = creat_tree(ary2, n2);
            if(check_node(t1, t2))
            {
                printf("Yes\n");
            }

            else
            {
                printf("No\n");
            }
        }
    }

    return 0;
}
