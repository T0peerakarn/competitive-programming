#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define N 200005

int cnt_hld, cnt_pos;
int val[N], lv[N], sub[N], pa[20][N], root[N], grp[N], arr[N], pos[N], seg[N*4];
vector<int> g[N];

void dfs(int u, int l)
{
	lv[u] = l;
	sub[u] = 1;
	for(auto v : g[u])
	{
		if(lv[v]) continue;
		dfs(v, l+1);
		sub[u] += sub[v];
		pa[0][v] = u;
	}
}

void hld(int u)
{
	if(!root[cnt_hld]) root[cnt_hld] = u;
	grp[u] = cnt_hld;
	arr[cnt_pos] = val[u];
	pos[u] = cnt_pos--;
	int heavy_node = 0;
	for(auto v : g[u])
	{
		if(lv[u]+1 != lv[v]) continue;
		if(sub[v] >= sub[u]/2) heavy_node = v;
	}
	if(heavy_node) hld(heavy_node);
	for(auto v : g[u])
	{
		if(lv[u]+1 != lv[v] || v == heavy_node) continue;
		cnt_hld++;
		hld(v);
	}
}

int lca(int u, int v)
{
	if(lv[u] < lv[v]) swap(u, v);
	for(int i=19 ; i>=0 ; i--) if(lv[pa[i][u]] >= lv[v]) u = pa[i][u];
	if(u == v) return u;
	for(int i=19 ; i>=0 ; i--) if(pa[i][u] != pa[i][v]) u = pa[i][u], v = pa[i][v];
	return pa[0][u];
}

void build(int l, int r, int idx)
{
	if(l == r) return void(seg[idx] = arr[l]);
	int mid = (l+r)>>1;
	build(l, mid, idx<<1), build(mid+1, r, idx<<1|1);
	seg[idx] = max(seg[idx<<1], seg[idx<<1|1]);
}

void update(int l, int r, int idx, int p, int v)
{
	if(l == r) return void(seg[idx] = v);
	int mid = (l+r)>>1;
	(p <= mid) ? update(l, mid, idx<<1, p, v) : update(mid+1, r, idx<<1|1, p, v);
	seg[idx] = max(seg[idx<<1], seg[idx<<1|1]);
}

int query(int l, int r, int idx, int a, int b)
{
	if(r < a || b < l) return 0;
	if(a <= l && r <= b) return seg[idx];
	int mid = (l+r)>>1;
	return max(query(l, mid, idx<<1, a, b), query(mid+1, r, idx<<1|1, a, b));
}

int solve(int u, int v, int n)
{
	int l = lca(u, v), ret = 0;
	while(true)
	{
		if(grp[u] != grp[l])
		{
			ret = max(ret, query(1, n, 1, pos[u], pos[root[grp[u]]]));
			u = pa[0][root[grp[u]]];
		}
		else
		{
			ret = max(ret, query(1, n, 1, pos[u], pos[l]));
			break;
		}
	}
	while(true)
	{
		if(grp[v] != grp[l])
		{
			ret = max(ret, query(1, n, 1, pos[v], pos[root[grp[v]]]));
			v = pa[0][root[grp[v]]];
		}
		else
		{
			ret = max(ret, query(1, n, 1, pos[v], pos[l]));
			break;
		}
	}
	return ret;
}

int main()
{
	int n, q;
	scanf(" %d %d",&n,&q);
	for(int i=1 ; i<=n ; i++) scanf(" %d",&val[i]);
	for(int i=1 ; i<n ; i++)
	{
		int u, v;
		scanf(" %d %d",&u,&v);
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 1);
	for(int i=1 ; i<20 ; i++) for(int j=1 ; j<=n ; j++) pa[i][j] = pa[i-1][pa[i-1][j]];
	cnt_hld = 1;
	cnt_pos = n;
	hld(1);
	build(1, n, 1);
	while(q--)
	{
		int op, a, b;
		scanf(" %d %d %d",&op,&a,&b);
		if(op == 1) update(1, n, 1, pos[a], b);
		else printf("%d\n",solve(a, b, n));
	}
	return 0;
}
