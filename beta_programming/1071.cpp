#include <bits/stdc++.h>
using namespace std;

int t[1010][1010];

int query(int x, int y, int r)
{
	int ret = 0;
	for(int i=max(0, x-r) ; i<=min(1000, x+r) ; i++)
		for(int j=max(0, y-r) ; j<=min(1000, y+r) ; j++)
		{
			ret += t[i][j];
			t[i][j] = 0;
		}
	return ret;
}

int main()
{
	int n, m;
	scanf(" %d %d",&n,&m);
	while(n--)
	{
		int x, y;
		scanf(" %d %d",&x,&y);
		t[x][y]++;
	}
	while(m--)
	{
		int x, y, r;
		scanf(" %d %d %d",&x,&y,&r);
		printf("%d\n",query(x, y, r));
	}
	return 0;
}
