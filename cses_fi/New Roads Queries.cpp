#include <bits/stdc++.h>
using namespace std;

#define N 200005

int l[N], r[N], pa[N];
vector<int> event[N];
vector<pair<int, int>> edge = {{0, 0}}, query = {{0, 0}};

int fp(int u) {return (u == pa[u]) ? u : pa[u] = fp(pa[u]);}

int main()
{
	int n, m, q;
	scanf(" %d %d %d",&n,&m,&q);
	for(int i=1 ; i<=m ; i++)
	{
		int u, v;
		scanf(" %d %d",&u,&v);
		edge.push_back({u, v});
	}
	for(int i=1 ; i<=q ; i++)
	{
		int u, v;
		scanf(" %d %d",&u,&v);
		query.push_back({u, v});
		if(u != v) l[i] = 1, r[i] = m+1;
	}
	bool working = true;
	while(working)
	{
		working = false;
		for(int i=1 ; i<=n ; i++) pa[i] = i;
		for(int i=1 ; i<=q ; i++)
		{
			if(l[i] == r[i]) continue;
			working = true;
			int mid = (l[i] + r[i])>>1;
			event[mid].push_back(i);
		}
		for(int i=1 ; i<=m ; i++)
		{
			pa[fp(edge[i].first)] = fp(edge[i].second);
			for(auto it : event[i]) (fp(query[it].first) == fp(query[it].second)) ? r[it] = i : l[it] = i+1;
			event[i].clear();
		}
	}
	for(int i=1 ; i<=q ; i++)
	{
		if(l[i] == m+1) l[i] = -1;
		printf("%d\n",l[i]);
	}
	return 0;
}
