#include <bits/stdc++.h>
using namespace std;

int walk_x[5555], walk_y[5555];

int main()
{
	int n, m, k;
	scanf(" %d %d %d",&n,&m,&k);
	while(k--)
	{
		int x, y, r;
		scanf(" %d %d %d",&x,&y,&r);
		x += 100, y += 100;
		walk_x[x-r]++;
		walk_x[x+r+1]--;
		walk_y[y-r]++;
		walk_y[y+r+1]--;
	}
	int ans = 0;
	for(int i=1 ; i<=5100 ; i++)
	{
		walk_x[i] += walk_x[i-1];
		walk_y[i] += walk_y[i-1];
	}
	for(int i=0 ; i<=5100 ; i++) ans = max(ans, max(walk_x[i], walk_y[i]));
	printf("%d\n",ans);
	return 0;
}
