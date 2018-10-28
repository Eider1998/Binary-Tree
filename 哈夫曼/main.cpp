#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}Huffnode;

void Add(struct node *head, int n)
{
    Huffnode *p, *q, *r;
    p = (Huffnode *)malloc(sizeof(Huffnode));
    p-> data = n;
    p-> next = NULL;
    q = head;
    r = head-> next;

    while(r && r-> data < p-> data)
    {
        q = r;
        r = r-> next;
    }

    q-> next = p;
    p-> next = r;
}

int Huffsum(struct node *head, int n)
{
   int sum, sumlenth, i;
   struct node *p, *q;
   sum = 0;
   sumlenth = 0;
   for(i = 1; i < n; i++)//一共需进行n-1次计算
   {
       p = head-> next;
       q = p-> next;
       sum = p-> data + q-> data;
       sumlenth += sum;
       head-> next = q-> next;
       free(p);
       free(q);
       Add(head, sum);
   }

   p = head-> next;//因为最后一个计算的sum又会被加入head之后，所以删除结点即可
   free(p);
//计算到最后就剩下一个头节点，和最后一个存储单元
   return sumlenth;
}

int main(void)
{
    char str[110];
    int i, n, Huffman[1100], la, lh, findx;
    Huffnode *head;
    while(~scanf("%s", str))
    {
        n = strlen(str);
        findx = 0;
        head = (Huffnode *)malloc(sizeof(Huffnode));
        head-> next = NULL;
        memset(Huffman, 0, sizeof(Huffman));
        for(i = 0; i < n; i++)
        {
            Huffman[str[i]]++;//此处会有Warnning，但是不影响，会自动变成int
        }

        for(i = 0; i < 128; i++)//因为在ASCII中一共有128个字符编码
        {
            if(Huffman[i])
            {
                Add(head, Huffman[i]);
                findx++;//因为可能有字母也肯=可能有别的字符，所以看看有多少不同字符
            }
        }
        la = n * 8;
        lh = Huffsum(head, findx);
        printf("%d %d %.1lf\n", la, lh, (1.0 * la) / lh);
    }

    return 0;
}
