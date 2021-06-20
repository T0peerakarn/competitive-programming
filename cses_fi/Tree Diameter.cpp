#include <bits/stdc++.h>
using namespace std;

#define N 200005

int ans;
int mx1[N], mx2[N];
vector<int> g[N];

void dfs1(int u, int p)
{
	for(auto v : g[u])
	{
		if(v == p) continue;
		dfs1(v, u);
		if(mx1[v]+1 >= mx1[u])
		{
			mx2[u] = mx1[u];
			mx1[u] = mx1[v] + 1;
		}
		else if(mx1[v]+1 > mx2[u]) mx2[u] = mx1[v]+1;
	}
}

void dfs2(int u, int p, int w)
{
	ans = max(ans, w+mx1[u]);
	int children = g[u].size() - (u == 1 ? 0 : 1);
	for(auto v : g[u])
	{
		if(v == p) continue;
		int ww = w+1;
		if(children > 1)
		{
			if(mx2 && mx1[v]+1 == mx1[u]) ww = max(ww, mx2[u]+1);
			else ww = max(ww, mx1[u]+1);
		}
		dfs2(v, u, ww);
	}
}

int main()
{
	int n;
	scanf(" %d",&n);
	for(int i=1 ; i<n ; i++)
	{
		int u, v;
		scanf(" %d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 0, 0);
	printf("%d\n",ans);
	return 0;
}
