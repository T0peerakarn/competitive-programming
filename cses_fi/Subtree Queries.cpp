#include <bits/stdc++.h>
using namespace std;

#define N 200005

int cnt;
int pos[N], sub[N];
long long val[N], arr[N], seg[N*4];
vector<int> g[N];

void dfs(int u, int p)
{
	pos[u] = ++cnt;
	arr[cnt] = val[u];
	sub[u] = 1;
	for(auto v : g[u])
	{
		if(v == p) continue;
		dfs(v, u);
		sub[u] += sub[v];
	}
}

void build(int l, int r, int idx)
{
	if(l == r) return void(seg[idx] = arr[l]);
	int mid = (l+r)>>1;
	build(l, mid, idx<<1), build(mid+1, r, idx<<1|1);
	seg[idx] = seg[idx<<1] + seg[idx<<1|1];
}

void update(int l, int r, int idx, int p, long long x)
{
	if(l == r) return void(seg[idx] = x);
	int mid = (l+r)>>1;
	(p <= mid) ? update(l, mid, idx<<1, p, x) : update(mid+1, r, idx<<1|1, p, x);
	seg[idx] = seg[idx<<1] + seg[idx<<1|1];
}

long long query(int l, int r, int idx, int a, int b)
{
	if(r < a || b < l) return 0;
	if(a <= l && r <= b) return seg[idx];
	int mid = (l+r)>>1;
	return query(l, mid, idx<<1, a, b) + query(mid+1, r, idx<<1|1, a, b);
}

int main()
{
	int n, q;
	scanf(" %d %d",&n,&q);
	for(int i=1 ; i<=n ; i++) scanf(" %lld",&val[i]);
	for(int i=1 ; i<n ; i++)
	{
		int u, v;
		scanf(" %d %d",&u,&v);
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 0);
	build(1, n, 1);
	while(q--)
	{
		int op;
		scanf(" %d",&op);
		if(op == 1)
		{
			int u;
			long long x;
			scanf(" %d %lld",&u,&x);
			update(1, n, 1, pos[u], x);
		}
		else
		{
			int u;
			scanf(" %d",&u);
			printf("%lld\n",query(1, n, 1, pos[u], pos[u]+sub[u]-1));
		}
	}
	return 0;
}
