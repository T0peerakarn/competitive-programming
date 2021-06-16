#include <bits/stdc++.h>
using namespace std;

#define N 100005

int cnt_id, cnt_scc;
int id[N], low[N], scc[N];
bool onStack[N];
vector<int> g[N];
stack<int> node;

void dfs(int u)
{
	id[u] = low[u] = ++cnt_id;
	onStack[u] = true;
	node.push(u);
	for(auto x : g[u])
	{
		if(!id[x])
		{
			dfs(x);
			low[u] = min(low[u], low[x]);
		}
		else if(onStack[x]) low[u] = min(low[u], id[x]);
	}
	if(id[u] == low[u])
	{
		cnt_scc++;
		while(true)
		{
			int now = node.top();
			node.pop();
			scc[now] = cnt_scc;
			onStack[now] = false;
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
	}
	for(int i=1 ; i<=n ; i++) if(!id[i]) dfs(i);
	printf("%d\n",cnt_scc);
	for(int i=1 ; i<=n ; i++) printf("%d ",scc[i]);
	return 0;
}
