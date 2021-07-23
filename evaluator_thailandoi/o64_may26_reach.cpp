#include <bits/stdc++.h>
#include "reach.h"
using namespace std;

int n;
int seg[400000];

void build(int l, int r, int idx)
{
	if(l == r) return void(seg[idx] = (l) ? l-1 : 0);
	int mid = (l+r)>>1;
	build(l, mid, idx<<1), build(mid+1, r, idx<<1|1);
	seg[idx] = min(seg[idx<<1], seg[idx<<1|1]);
}

void update(int l, int r, int idx, int p, int v)
{
	if(!(l <= p && p <= r)) return ;
	if(l == r) return void(seg[idx] = min(seg[idx], v));
	int mid = (l+r)>>1;
	update(l, mid, idx<<1, p, v), update(mid+1, r, idx<<1|1, p, v);
	seg[idx] = min(seg[idx<<1], seg[idx<<1|1]);
}

int query(int l, int r, int idx, int a, int b)
{
	if(r < a || b < l) return 1e9;
	if(a <= l && r <= b) return seg[idx];
	int mid = (l+r)>>1;
	return min(query(l, mid, idx<<1, a, b), query(mid+1, r, idx<<1|1, a, b));
}

void initialize(int N)
{
	n = N;
	build(0, n-1, 1);
}

void add_arc(int u, int v)
{
	update(0, n-1, 1, v, u);
}

bool is_reachable(int u, int v, int t)
{
	if(t < u) return true;
	if(t <= v) return false;
	int mn = query(0, n-1, 1, v+1, t);
	return (mn < u) ? true : false;
}
