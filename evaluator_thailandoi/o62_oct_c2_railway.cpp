#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define N 100100

int lv[N], ans[N];
pair<int, int> pa[N];
vector<int> weight;
vector<pair<int, int>> g[N], requirement;
vector<pair<pair<int, int>, int>> query;

void dfs(int u, int l)
{
	lv[u] = l;
	for(auto x : g[u])
	{
		if(lv[x.first]) continue;
		pa[x.first] = {u, x.second};
		dfs(x.first, l+1);
	}
}

int get_mx(int u, int v)
{
	int ret = 0;
	if(lv[u] < lv[v]) swap(u, v);
	while(lv[u] > lv[v])
	{
		ret = max(ret, pa[u].second);
		u = pa[u].first;
	}
	while(u != v)
	{
		ret = max(ret, max(pa[u].second, pa[v].second));
		u = pa[u].first, v = pa[v].first;
	}
	return ret; 
}

int main()
{
	int n, m;
	scanf(" %d %d",&n,&m);

	for(int i=1 ; i<=n-1 ; i++)
	{
		int u, v, w;
		scanf(" %d %d %d",&u,&v,&w);
		g[u].pb({v, w}), g[v].pb({u, w});
	}

	dfs(1, 1);

	for(int i=n ; i<=m ; i++)
	{
		int u, v, w;
		scanf(" %d %d %d",&u,&v,&w);
		weight.pb(w);
		query.pb({{u, v}, i-n});
	}

	for(auto x : query)
		requirement.pb({get_mx(x.first.first, x.first.second), x.second});

	sort(weight.begin(), weight.end());
	sort(requirement.begin(), requirement.end());

	for(int i=0 ; i<=m-n ; i++)
	{
		if(requirement[i].first >= weight[i])
		{
			printf("0\n");
			return 0;
		}
		ans[requirement[i].second] = weight[i];
	}

	printf("1\n");
	for(int i=0 ; i<=m-n ; i++)
		printf("%d\n",ans[i]);

	return 0;
}
