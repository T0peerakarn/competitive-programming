#include <bits/stdc++.h>
#include "train.h"
using namespace std;

long long mx1[800000], mx2[800000], mn[800000], laz[800000];

void build(int l, int r, int idx)
{
	if(l == r)
	{
		mx1[idx] = mn[idx] = (l == 0) ? 0 : 2e9;
		mx2[idx] = -1;
		return ;
	}
	int mid = (l+r)>>1;
	build(l, mid, idx<<1), build(mid+1, r, idx<<1|1);
	if(mx1[idx<<1] == mx1[idx<<1|1]) mx1[idx] = mx2[idx] = mx1[idx<<1];
	else if(mx1[idx<<1] > mx1[idx<<1|1])
	{
		mx1[idx] = mx1[idx<<1];
		mx2[idx] = max(mx2[idx<<1], mx1[idx<<1|1]);
	}
	else
	{
		mx1[idx] = mx1[idx<<1|1];
		mx2[idx] = max(mx2[idx<<1|1], mx1[idx<<1]);
	}
	mn[idx] = min(mn[idx<<1], mn[idx<<1|1]);
}

void lazy(int l, int r, int idx)
{
	if(laz[idx] == 0) return ;
	long long val = laz[idx];
	laz[idx] = 0;
	if(val >= mx1[idx]) return ;
	else if(val >= mx2[idx])
	{
		mx1[idx] = val;
		if(l == r) mn[idx] = val;
		else laz[idx<<1] = laz[idx<<1|1] = val;
	}
	else
	{
		if(l != r) laz[idx<<1] = laz[idx<<1|1] = val;
	}
}

long long query(int l, int r, int idx, int a, int b)
{
	lazy(l, r, idx);
	if(r < a || b < l) return 2e9;
	if(a <= l && r <= b) return mn[idx];
	int mid = (l+r)>>1;
	return min(query(l, mid, idx<<1, a, b), query(mid+1, r, idx<<1|1, a, b));
}

void update(int l, int r, int idx, int a, int b, long long v)
{
	lazy(l, r, idx);
	if(r < a || b < l || mx1[idx] <= v) return ;
	if(a <= l && r <= b && v >= mx2[idx])
	{
		laz[idx] = v;
		lazy(l, r, idx);
		return ;
	}
	int mid = (l+r)>>1;
	update(l, mid, idx<<1, a, b, v), update(mid+1, r, idx<<1|1, a, b, v);
	if(mx1[idx<<1] == mx1[idx<<1|1]) mx1[idx] = mx2[idx] = mx1[idx<<1];
	else if(mx1[idx<<1] > mx1[idx<<1|1])
	{
		mx1[idx] = mx1[idx<<1];
		mx2[idx] = max(mx2[idx<<1], mx1[idx<<1|1]);
	}
	else
	{
		mx1[idx] = mx1[idx<<1|1];
		mx2[idx] = max(mx2[idx<<1|1], mx1[idx<<1]);
	}
	mn[idx] = min(mn[idx<<1], mn[idx<<1|1]);
}

int find_min_cost(int N, int M,
		  vector<int>& s,
		  vector<int>& t,
		  vector<int>& c)
{
	build(0, N-1, 1);
	for(int i=0 ; i<M ; i++)
	{
		long long v = query(0, N-1, 1, s[i], t[i]);
		if(v == 2e9) continue;
		update(0, N-1, 1, s[i], t[i], v+c[i]);
	}
	long long ret = query(0, N-1, 1, N-1, N-1);
	return (ret == 2e9) ? -1 : ret;
}
