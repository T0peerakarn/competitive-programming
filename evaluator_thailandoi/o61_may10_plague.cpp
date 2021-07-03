#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_pbds;

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+5;

int cnt;
int sub[N], lv[N], pa[20][N], jmp[20][N], dis[20][N];
vector<int> g[N], gt[N];
bool visit[N];
ordered_set<pair<int, int>> t1[N], t2[N];

int get_sub(int u, int p)
{
	sub[u] = 1;
	for(auto v : g[u])
	{
		if(v == p || visit[v]) continue;
		sub[u] += get_sub(v, u);
	}
	return sub[u];
}

int get_centroid(int u, int p, int n)
{
	bool ch = (n-sub[u] <= n/2);
	int uu = 0;
	for(auto v : g[u])
	{
		if(v == p || visit[v]) continue;
		if(sub[v] > n/2)
		{
			uu = v;
			ch = false;
		}
	}
	return (ch) ? u : get_centroid(uu, u, n);
}

void gen_distance(int u, int p, int l)
{
	for(auto v : g[u])
	{
		if(v == p || visit[v]) continue;
		dis[l][v] = dis[l][u]+1;
		gen_distance(v, u, l);
	}
}

int build_centroid(int u, int p)
{
	int centroid = get_centroid(u, p, get_sub(u, p));
	visit[centroid] = true;
	lv[centroid] = lv[p]+1;
	gen_distance(centroid, 0, lv[centroid]);
	for(auto v : g[centroid])
	{
		if(visit[v]) continue ;
		pa[1][build_centroid(v, centroid)] = centroid;
	}
	return centroid;
}

int main()
{
	int n, q;
	scanf(" %d %d",&n,&q);
	for(int i=1 ; i<n ; i++)
	{
		int u, v;
		scanf(" %d %d",&u,&v);
		g[u].push_back(v), g[v].push_back(u);
	}
	build_centroid(1, 0);
	for(int i=1 ; i<=n ; i++)
	{
		pa[0][i] = i;
		for(int j=2 ; j<20 ; j++) pa[j][i] = pa[1][pa[j-1][i]];
	}
	while(q--)
	{
		int op, a, b;
		scanf(" %d",&op);
		if(op == 1)
		{
			scanf(" %d %d",&a,&b);
			t1[a].insert(make_pair(b, ++cnt));
			for(int i=1 ; pa[i][a] != 0 ; i++)
			{
				if(b < dis[lv[pa[i][a]]][a]) continue ;
				t1[pa[i][a]].insert(make_pair(b-dis[lv[pa[i][a]]][a], ++cnt));
				t2[pa[i-1][a]].insert(make_pair(b-dis[lv[pa[i][a]]][a], ++cnt));
			}
		}
		else
		{
			scanf(" %d",&a);
			int ans = t1[a].size() - t1[a].order_of_key(make_pair(0, 0));
			for(int i=1 ; pa[i][a] != 0 ; i++)
			{
				ans += t1[pa[i][a]].size() - t1[pa[i][a]].order_of_key(make_pair(dis[lv[pa[i][a]]][a], 0));
				ans -= t2[pa[i-1][a]].size() - t2[pa[i-1][a]].order_of_key(make_pair(dis[lv[pa[i][a]]][a], 0));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}

/*
6 6
1 2
3 2
2 5
5 6
4 5
1 6 2
2 2
1 3 1
1 6 1
2 2
2 5 
*/
