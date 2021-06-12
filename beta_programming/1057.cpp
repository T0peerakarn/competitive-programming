#include <bits/stdc++.h>
using namespace std;

bool visit[1010];
vector<int> g[1010];

bool dfs(int u)
{
	if(visit[u]) return false;
	visit[u] = true;
	bool ret = true;
	for(auto x : g[u]) ret &= dfs(x);
	return ret;
}

int main()
{
	int n;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++)
	{
		int d;
		scanf(" %d",&d);
		while(d--)
		{
			int j;
			scanf(" %d",&j);
			g[i].push_back(j);
		}
	}
	for(int i=1 ; i<=n ; i++)
	{
		for(int j=1 ; j<=n ; j++) visit[j] = false;
		printf(dfs(i) ? "NO\n" : "YES\n");
	}
	return 0;
}
