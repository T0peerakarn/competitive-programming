#include <bits/stdc++.h>
using namespace std;

#define N 1000005

int cnt_id, cnt_scc;
int id[N], low[N], scc[N];
long long val[N], sum[N], dp[N];
bool onStack[N];
vector<int> g[N], gt[N];
vector<pair<int, int>> edge;
stack<int> node, topo;
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

long long opt(int u)
{
	if(dp[u] != -1) return dp[u];
	if(gt[u].empty()) return -1e18;
	long long ret = 0;
	for(auto v : gt[u]) ret = max(ret, opt(v));
	return dp[u] = sum[u] + ret;
}

int main()
{
	int n, m, s, e;
	scanf(" %d %d %d %d",&n,&m,&s,&e);
	for(int i=1 ; i<=n ; i++) scanf(" %lld",&val[i]);
	while(m--)
	{
		int u, v;
		scanf(" %d %d",&u,&v);
		g[u].push_back(v);
		edge.push_back({u, v});
	}
	for(int i=1 ; i<=n ; i++) if(!id[i]) dfs(i);
	for(int i=1 ; i<=n ; i++) sum[scc[i]] += val[i];
	for(auto x : edge)
	{
		int u = scc[x.first], v = scc[x.second];
		if(u == v || mp[u].count(v)) continue;
		mp[u][v] = 1;
		gt[v].push_back(u);
	}
	memset(dp, -1, sizeof dp);
	dp[scc[s]] = sum[scc[s]];
	printf("%lld\n",opt(scc[e]));
	return 0;
}
