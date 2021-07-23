#include "emergency.h"
#include <bits/stdc++.h>
using namespace std;

int child_mx1[200005], child_mx2[200005], dp[200005];
bool h[200005];
vector<pair<int, int>> g[200005];

void dfs(int u, int p)
{
		for(auto x : g[u])
		{
			if(x.first == p) continue;
			dfs(x.first, u);
			if(child_mx1[x.first])
			{
				if(child_mx1[x.first] + x.second >= child_mx1[u])
				{
					child_mx2[u] = child_mx1[u];
					child_mx1[u] = child_mx1[x.first] + x.second;
				}
				else if(child_mx1[x.first] + x.second > child_mx2[u])
				{
					child_mx2[u] = child_mx1[x.first] + x.second;
				}
			}
			else if(h[x.first])
			{
				if(x.second >= child_mx1[u])
				{
					child_mx2[u] = child_mx1[u];
					child_mx1[u] = x.second;
				}
				else if(x.second > child_mx2[u])
				{
					child_mx2[u] = x.second;
				}
			}
		}
}

void update(int u, int p, int mx)
{
	dp[u] = max(child_mx1[u], mx);

	int cnt = 0;
	for(auto x : g[u])
	{
		if(x.first == p) continue;
		cnt++;
	}

	if(cnt == 1)
	{
		for(auto x : g[u])
		{
			if(x.first == p) continue;
			int v = 0;
			if(mx) v = max(v, mx+x.second);
			if(h[u]) v = max(v, x.second);
			update(x.first, u, v);
		}
	}
	else
	{
		for(auto x : g[u])
		{
			if(x.first == p) continue;
			int v = 0;
			if(mx) v = max(v, mx+x.second);
			if(h[u]) v = max(v, x.second);
			if(child_mx1[u] && child_mx2[u])
			{
				if(child_mx1[x.first] && child_mx1[x.first] + x.second == child_mx1[u]) v = max(v, child_mx2[u]+x.second);
				else if(h[x.first] && x.second == child_mx1[u]) v = max(v, child_mx2[u]+x.second);
				else v = max(v, child_mx1[u]+x.second);
			}
			else if(child_mx1[u])
			{
				if(!child_mx1[x.first] || child_mx1[x.first] + x.second != child_mx1[u]) v = max(v, child_mx1[u]+x.second);
			}
			update(x.first, u, v);
		}
	}
}

int furthest(int N, int H, int K, int roads[][2], int lengths[], int hospitals[], int centers[])
{
	for(int i=0 ; i<N-1 ; i++)
	{
		g[roads[i][0]].push_back({roads[i][1], lengths[i]});
		g[roads[i][1]].push_back({roads[i][0], lengths[i]});
	}

	for(int i=0 ; i<H ; i++)
		h[hospitals[i]] = true;

	dfs(0, -1);
	update(0, -1, 0);

	int ret = 0;
	for(int i=0 ; i<K ; i ++)
		ret = max(ret, dp[centers[i]]);
	return ret;
}
