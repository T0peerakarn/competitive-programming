#include <bits/stdc++.h>
using namespace std;

#define N 100005

int cnt_id, cnt_scc;
int low[N], id[N], scc[N];
bool onStack[N], visit[N];
stack<int> node; 
vector<int> g[N];

void dfs(int u)
{
	node.push(u);
	onStack[u] = true;
	low[u] = id[u] = ++cnt_id;
	for(auto x : g[u])
	{
		if(!id[x])
		{
			dfs(x);
			low[u] = min(low[u], low[x]);
		}
		else if(onStack[x]) low[u] = min(low[u], id[x]);
	}
	if(low[u] == id[u])
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

void Try(int u)
{
	visit[u] = true;
	for(auto x : g[u]) if(!visit[x]) Try(x);
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
	for(int i=2 ; i<=n ; i++)
		if(scc[i] != scc[i-1])
		{
			int a = i-1, b = i;
			Try(a);
			if(visit[b]) swap(a, b);
			printf("NO\n%d %d\n",a,b);
			return 0;
		}
	printf("YES\n");
	return 0;
}
