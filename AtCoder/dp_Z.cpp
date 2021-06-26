#include <bits/stdc++.h>
using namespace std;

#define N 200005
#define H 1000005

struct Line
{
	long long m, c;
	long long operator()(long long x) {return m*x+c;}
};

long long h[N], dp[N];
Line seg[H*4];

void build(int l, int r, int idx)
{
	seg[idx] = {-2*h[1], h[1]*h[1]};
	if(l == r) return ;
	int mid = (l+r)>>1;
	build(l, mid, idx<<1), build(mid+1, r, idx<<1|1);
}

long long query(int l, int r, int idx, int p)
{
	if(l == r) return seg[idx](p);
	int mid = (l+r)>>1;
	long long ret = (p <= mid) ? query(l, mid, idx<<1, p) : query(mid+1, r, idx<<1|1, p);
	return min(seg[idx](p), ret);
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
	long long c;
	scanf(" %d %lld",&n,&c);
	for(int i=1 ; i<=n ; i++) scanf(" %lld",&h[i]);
	build(1, H, 1);
	for(int i=2 ; i<=n ; i++)
	{
		dp[i] = c + h[i]*h[i] + query(1, H, 1, h[i]);
		update(1, H, 1, {-2*h[i], dp[i]+h[i]*h[i]});
	}
	printf("%lld\n",dp[n]);
	return 0;
}
