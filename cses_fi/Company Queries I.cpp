#include <bits/stdc++.h>
using namespace std;
 
#define N 200005
 
int lv[N], pa[20][N];
vector<int> g[N];
 
void dfs(int u, int l)
{
	lv[u] = l;
	for(auto v : g[u])
	{
		if(lv[v]) continue;
		dfs(v, l+1);
		pa[0][v] = u;
	}
}
 
int main()
{
	int n, q;
	scanf(" %d %d",&n,&q);
	for(int i=2 ; i<=n ; i++)
	{
		int d;
		scanf(" %d",&d);
		pa[0][i] = d;
	}
	// dfs(1, 1);
	for(int i=1 ; i<20 ; i++) for(int j=1 ; j<=n ; j++) pa[i][j] = pa[i-1][pa[i-1][j]];
	while(q--)
	{
		int u, k;
		scanf(" %d %d",&u,&k);
		for(int i=0 ; i<20 ; i++) if((1<<i)&k) u = pa[i][u];
		if(u == 0) u = -1;
		printf("%d\n",u);
	}
	return 0;
} 
