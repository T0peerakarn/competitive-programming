#include <bits/stdc++.h>
using namespace std;

#define N 100005

int cnt_id;
int id[N], low[N];
vector<int> g[N], ans;

void dfs(int u, int p)
{
	id[u] = low[u] = ++cnt_id;
	int children = 0;
	for(auto v : g[u])
	{
		if(v == p) continue;
		children++;
		if(!id[v])
		{
			dfs(v, u);
			if((u != 1 || (u == 1 && children > 1)) && id[u] <= low[v]) ans.push_back(u);
			low[u] = min(low[u], low[v]);
		}
		low[u] = min(low[u], id[v]);
	}
}

int main()
{
	int n, m;
	scanf(" %d %d",&n,&m);
	while(m--)
	{
		int u, v;
		scanf(" %d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	printf("%d\n",ans.size());
	for(auto x : ans) printf("%d ",x);
	return 0;
}
