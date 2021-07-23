#include "castle.h"
#include <bits/stdc++.h>
using namespace std;

int parent[100005];
bool visit[100005], special[100100], destroy[100100];
pair<int, int> parent_edge[100005];
vector<pair<int, int>> g[100005];
vector<pair<pair<int, int>, int>> sp_edge;

void dfs(int u, int p)
{
	visit[u] = true;
	for(auto x : g[u])
	{
		if(visit[x.first]) continue;
		parent_edge[x.first] = {u, x.second};
		special[x.second] = false;
		dfs(x.first, u);
	}
}

int jump(int u)
{
	while(true)
	{
		if(parent_edge[u].first == -1) return u;
		if(destroy[parent_edge[u].second]) return u;
		u = parent_edge[u].first;
	}
}

int fp(int u)
{
	return (u == parent[u]) ? u : parent[u] = fp(parent[u]);
}

int main()
{
	int n, m, q, y;
	vector<int> a, b;

	castle_init(n, m, q, y);
	castle_read_map(a, b);

	for(int i=0 ; i<m ; i++)
	{
		special[i] = true;
		g[a[i]].push_back({b[i], i});
		g[b[i]].push_back({a[i], i});
	}

	parent_edge[0] = {-1, -1};
	dfs(0, -1);

	for(int i=0 ; i<m ; i++)
		if(special[i]) sp_edge.push_back({{a[i], b[i]}, i});

	for(int i=0 ; i<n ; i++)
		parent[i] = i;

	while(q--)
	{
		int t, u, v;
		castle_read_event(t, u, v);
		if(t == 1) destroy[u] = true;
		else
		{
			queue<int> cleaner;
			for(auto edge : sp_edge)
			{
				if(destroy[edge.second]) continue;
				int p1 = fp(jump(edge.first.first)), p2 = fp(jump(edge.first.second));
				if(p1 != p2)
				{
					parent[p1] = p2;
					cleaner.push(p1), cleaner.push(p2);
				}
			}
			int ans = (fp(jump(u)) == fp(jump(v))) ? 1 : 0;
			castle_answer(ans);
			while(!cleaner.empty())
			{
				parent[cleaner.front()] = cleaner.front();
				cleaner.pop();
			}
		}
	}
	return 0;
}
