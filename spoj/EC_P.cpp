#include <bits/stdc++.h>
using namespace std;

#define N 705

int cnt_id;
int id[N], low[N];
vector<int> g[N];
vector<pair<int, int>> ans;

void Init()
{
	cnt_id = 0;
	ans.clear();
	for(int i=1 ; i<=700 ; i++)
	{
		id[i] = 0;
		low[i] = 0;
		g[i].clear();
	}
}

void dfs(int u, int p)
{
	id[u] = low[u] = ++cnt_id;
	for(auto v : g[u])
	{
		if(v == p) continue;
		if(!id[v])
		{
			dfs(v, u);
			if(id[u] < low[v]) ans.push_back({min(u, v), max(u, v)});
			low[u] = min(low[u], low[v]);
		}
		low[u] = min(low[u], id[v]);
	}
}

int main()
{
	int q;
	scanf(" %d",&q);
	for(int qq=1 ; qq<=q ; qq++)
	{
		Init();
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
		sort(ans.begin(), ans.end());
		printf("Caso #%d\n",qq);
		if(ans.empty()) printf("Sin bloqueos\n");
		else
		{
			printf("%d\n",ans.size());
			for(auto x : ans) printf("%d %d\n",x.first,x.second);
		}
	}
	return 0;
}
