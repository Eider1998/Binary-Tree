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
		r = pre[r];//找老大ing！
	}

	i = x;
	while(pre[i] != r)//把他们的老大，都设置成刚刚找到的老大
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;//找到老大啦！
}

void mix(int x, int y)//为了互相不打架，还是把两个不同人的老大设置成一个！
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
			t[find(i)] = 1;//找有几个连通路径！
		}

		for(ans = 0, i = 1; i <= n; i++)
		{
			if(t[i])
			{
				ans++;
			}
		}

		printf("%d\n", ans - 1);//若有三个联通路径，则再加上两个就都连上了呀~~
	}

	return 0;
}
