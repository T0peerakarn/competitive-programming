#include <bits/stdc++.h>
using namespace std;

#define N 200005

struct Line
{
	long long m, c;
	long long operator() (long long x) {return m*x+c;}
};

long long s[N], f[N], dp[N];
Line seg[4000000];

void build(int l, int r, int idx, Line now)
{
	seg[idx] = now;
	if(l == r) return ;
	int mid = (l+r)>>1;
	build(l, mid, idx<<1, now), build(mid+1, r, idx<<1|1, now);
}

long long query(int l, int r, int idx, long long x)
{
	if(l == r) return seg[idx](x);
	int mid = (l+r)>>1;
	long long ret = (x <= mid) ? query(l, mid, idx<<1, x) : query(mid+1, r, idx<<1|1, x);
	return min(ret, seg[idx](x));
}

void update(int l, int r, int idx, Line now)
{
	if(l == r)
	{
		if(now(l) < seg[idx](l)) seg[idx] = now;
		return ;
	}
	int mid = (l+r)>>1;
	if(now.m > seg[idx].m) swap(now, seg[idx]);
	if(now(mid) < seg[idx](mid))
	{
		swap(now, seg[idx]);
		update(l, mid, idx<<1, now);
	}
	else update(mid+1, r, idx<<1|1, now);
}

int main()
{
	int n;
	long long x;
	scanf(" %d %lld",&n,&x);
	for(int i=1 ; i<=n ; i++) scanf(" %lld",&s[i]);
	for(int i=1 ; i<=n ; i++) scanf(" %lld",&f[i]);
	build(1, 1000000, 1, {x, 0});
	for(int i=1 ; i<=n ; i++)
	{
		dp[i] = query(1, 1000000, 1, s[i]);
		update(1, 1000000, 1, {f[i], dp[i]});
	}
	printf("%lld\n",dp[n]);
	return 0;
}
