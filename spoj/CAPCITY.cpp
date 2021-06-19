#include <bits/stdc++.h>
using namespace std;

#define N 100005

int cnt_id, cnt_scc;
int id[N], low[N], scc[N], deg[N], sub[N];
bool onStack[N];
stack<int> node, topo;
vector<int> g[N], gt[N];
vector<pair<int, int>> edge;
map<int, int> mp[N];

void dfs(int u)
{
	id[u] = low[u] = ++cnt_id;
	node.push(u);
	onStack[u] = true;
	for(auto v : g[u])
	{
		if(!id[v])
		{
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else if(onStack[v]) low[u] = min(low[u], id[v]);
	}
	if(id[u] == low[u])
	{
		cnt_scc++;
		while(true)
		{
			int now = node.top();
			node.pop();
			onStack[now] = false;
			scc[now] = cnt_scc;
			if(now == u) break;
		}
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
		edge.push_back({u, v});
	}
	for(int i=1 ; i<=n ; i++) if(!id[i]) dfs(i);
	for(auto x : edge)
	{
		int u = scc[x.first], v = scc[x.second];
		if(u == v || mp[u].count(v)) continue;
		mp[u][v] = 1;
		gt[u].push_back(v);
		deg[v]++;
	}
	for(int i=1 ; i<=cnt_scc ; i++) if(deg[i] == 0) topo.push(i);
	while(!topo.empty())
	{
		int now = topo.top();
		sub[now]++;
		topo.pop();
		for(auto x : gt[now])
		{
			sub[x] += sub[now];
			deg[x]--;
			if(!deg[x]) topo.push(x);
		}
	}
	int scc_capital, cnt = 0;
	for(int i=1 ; i<=n ; i++) if(sub[scc[i]] == cnt_scc) scc_capital = scc[i];
	for(int i=1 ; i<=n ; i++) if(scc[i] == scc_capital) cnt++;
	printf("%d\n",cnt);
	for(int i=1 ; i<=n ; i++) if(scc[i] == scc_capital) printf("%d ",i);
	return 0;
}
