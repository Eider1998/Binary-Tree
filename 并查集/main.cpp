#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pre[1000];
int find(int x)
{
	int r, i, j;
	r = x;
    while(r != pre[r])
	{
		r = pre[r];//���ϴ�ing��
	}

	i = x;
	while(pre[i] != r)//�����ǵ��ϴ󣬶����óɸո��ҵ����ϴ�
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;//�ҵ��ϴ�����
}

void mix(int x, int y)//Ϊ�˻��಻��ܣ����ǰ�������ͬ�˵��ϴ����ó�һ����
{
	int fx = find(x), fy = find(y);
	if(fx != fy)
	{
		pre[fy] = fx;
	}
}

int main(void)
{
	int n, m, i, t[1000], ans, x, y;

	while(scanf("%d %d", &n, &m) && n)
	{
        if(n == 0)
        {
            break;
        }
        for(i = 1; i <= n; i++)
		{
			pre[i] = i;
		}

		for(i = 1; i <= m; i++)
		{
			scanf("%d %d", &x, &y);
			mix(x, y);
		}
		memset(t, 0, sizeof(t));

		for(i = 1; i <= n; i++)
		{
			t[find(i)] = 1;//���м�����ͨ·����
		}

		for(ans = 0, i = 1; i <= n; i++)
		{
			if(t[i])
			{
				ans++;
			}
		}

		printf("%d\n", ans - 1);//����������ͨ·�������ټ��������Ͷ�������ѽ~~
	}

	return 0;
}
