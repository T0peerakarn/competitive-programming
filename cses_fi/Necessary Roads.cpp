#include <bits/stdc++.h>
using namespace std;

#define N 100005

int cnt_id;
int id[N], low[N];
vector<int> g[N];
vector<pair<int, int>> ans;

void dfs(int u, int p)
{
	id[u] = low[u] = ++cnt_id;
	for(auto v : g[u])
	{
		if(v == p) continue;
		if(!id[v])
		{
			dfs(v, u);
			if(id[u] < low[v]) ans.push_back({u, v});
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
	for(auto x : ans) printf("%d %d\n",x.first,x.second);
	return 0;
}
