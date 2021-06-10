#include <bits/stdc++.h>
using namespace std;

int room[10005], que[1005];

int main()
{
	int r, n, sz = 0;
	scanf(" %d %d",&r,&n);
	for(int i=1 ; i<=n ; i++)
	{
		int a, b;
		scanf(" %d %d",&a,&b);
		room[b] = a;
	}
	while(true)
	{
		char c;
		scanf(" %c",&c);
		if(c == 'X')
		{
			printf("0\n");
			return 0;
		}
		else if(c == 'E')
		{
			int d, p = 0;
			scanf(" %d",&d);
			for(int i=1 ; i<=sz ; i++) if(room[d] == room[que[i]]) p = i;
			if(p)
			{
				for(int i=sz ; i>p ; i--) que[i+1] = que[i];
				que[p+1] = d;
				sz++;
			}
			else
			{
				que[++sz] = d;
			}
		}
		else
		{
			if(sz == 0) printf("empty\n");
			else
			{
				printf("%d\n",que[1]);
				for(int i=2 ; i<=sz ; i++) que[i-1] = que[i];
				sz--;
			}
		}
	}
	return 0;
}
