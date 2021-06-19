#include <bits/stdc++.h>
using namespace std;

#define N 10005

int cnt_id;
int id[N], low[N];
bool ap[N];
vector<int> g[N];

void Init()
{
	cnt_id = 0;
	for(int i=1 ; i<=10000 ; i++)
	{
		id[i] = 0;
		low[i] = 0;
		ap[i] = false;
		g[i].clear();

	}
}

void dfs(int u, int p)
{
	int children = 0;
	id[u] = low[u] = ++cnt_id;
	for(auto x : g[u])
	{
		if(x == p) continue;
		children++;
		if(!id[x])
		{
			dfs(x, u);
			if((u != 1 || (u == 1 && children > 1)) && id[u] <= low[x]) ap[u] = true;
			low[u] = min(low[u], low[x]);
		}
		low[u] = min(low[u], id[x]);
	}
}

int main()
{
	while(true)
	{
		Init();
		int n, m;
		scanf(" %d %d",&n,&m);
		if(n == 0 && m == 0) return 0;
		while(m--)
		{
			int u, v;
			scanf(" %d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 0);
		int ans = 0;
		for(int i=1 ; i<=n ; i++) if(ap[i]) ans++;
		printf("%d\n",ans);
	}	
	return 0;
}
