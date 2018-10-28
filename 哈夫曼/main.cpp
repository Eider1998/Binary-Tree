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
   for(i = 1; i < n; i++)//һ�������n-1�μ���
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

   p = head-> next;//��Ϊ���һ�������sum�ֻᱻ����head֮������ɾ����㼴��
   free(p);
//���㵽����ʣ��һ��ͷ�ڵ㣬�����һ���洢��Ԫ
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
            Huffman[str[i]]++;//�˴�����Warnning�����ǲ�Ӱ�죬���Զ����int
        }

        for(i = 0; i < 128; i++)//��Ϊ��ASCII��һ����128���ַ�����
        {
            if(Huffman[i])
            {
                Add(head, Huffman[i]);
                findx++;//��Ϊ��������ĸҲ��=�����б���ַ������Կ����ж��ٲ�ͬ�ַ�
            }
        }
        la = n * 8;
        lh = Huffsum(head, findx);
        printf("%d %d %.1lf\n", la, lh, (1.0 * la) / lh);
    }

    return 0;
}
