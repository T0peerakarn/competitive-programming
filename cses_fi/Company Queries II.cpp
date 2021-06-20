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
		dfs(v, l+1);
		pa[0][v] = u;
	}
}

int lca(int u, int v)
{
	if(lv[u] < lv[v]) swap(u, v);
	for(int i=19 ; i>=0 ; i--) if(lv[pa[i][u]] >= lv[v]) u = pa[i][u];
	if(u == v) return u;
	for(int i=19 ; i>=0 ; i--) if(pa[i][u] != pa[i][v]) u = pa[i][u], v = pa[i][v];
	return pa[0][u];
}

int main()
{
	int n, q;
	scanf(" %d %d",&n,&q);
	for(int i=2 ; i<=n ; i++)
	{
		int d;
		scanf(" %d",&d);
		g[d].push_back(i);
	}
	dfs(1, 1);
	for(int i=1 ; i<20 ; i++) for(int j=1 ; j<=n ; j++) pa[i][j] = pa[i-1][pa[i-1][j]];
	while(q--)
	{
		int u, v;
		scanf(" %d %d",&u,&v);
		printf("%d\n",lca(u, v));
	}
	return 0;
}
