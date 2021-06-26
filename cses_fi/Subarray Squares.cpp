#include <bits/stdc++.h>
using namespace std;

#define N 3005

long long qs[N], dp[N][N];

void solve(int k, int l, int r, int a, int b)
{
	if(r < l) return;
	int mid = (l+r)>>1;
	int pos;
	long long opt = 1e18;
	for(int i=a ; i<=min(b, mid) ; i++)
	{
		long long val = dp[k-1][i-1] + (qs[mid]-qs[i-1])*(qs[mid]-qs[i-1]);
		if(val < opt)
		{
			opt = val;
			pos = i;
		}
	}
	dp[k][mid] = opt;
	solve(k, l, mid-1, a, pos);
	solve(k, mid+1, r, pos, b);
}

int main()
{
	int n, k;
	scanf(" %d %d",&n,&k);
	for(int i=1 ; i<=n ; i++)
	{
		scanf(" %lld",&qs[i]);
		qs[i] += qs[i-1];
		dp[1][i] = qs[i]*qs[i];
	}
	for(int i=2 ; i<=k ; i++) solve(i, i, n, i, n);
	printf("%lld\n",dp[k][n]);
	return 0;
}
