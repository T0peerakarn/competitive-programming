#include <bits/stdc++.h>
using namespace std;

long long arr[355], qs[355], dp[355][355], trace[355][355];

int search(int ni, int nj, int ii)
{
	while(true)
	{
		if(ni == ii) return nj - trace[ni][nj] + 1;
		nj = trace[ni][nj]-1;
		ni--;
	}
}

void solve(int i, int m, int l, int r, int a, int b)
{
	if(l > r) return ;
	int mid = (l+r)>>1;
	dp[i][mid] = 1e15;
	for(int k=a ; k<=min(b, mid) ; k++)
	{
		long long table = (i > m) ? search(i-1, k-1, 2*m+1-i) : 0;
		if(dp[i-1][k-1] + (qs[mid]-qs[k-1])*(mid-k) + 2*table*(mid-k+1) < dp[i][mid])
		{
			dp[i][mid] = dp[i-1][k-1] + (qs[mid]-qs[k-1])*(mid-k) + 2*table*(mid-k+1);
			trace[i][mid] = k;
		}
	}
	solve(i, m, l, mid-1, a, trace[i][mid]);
	solve(i, m, mid+1, r, trace[i][mid], b);
}

int main()
{
	int n, m;
	scanf(" %d %d",&n,&m);
	for(int i=1 ; i<=n ; i++)
		scanf(" %lld",&arr[i]);
	sort(arr+1, arr+n+1);
	for(int i=1 ; i<=n ; i++)
	{
		qs[i] = arr[i] + qs[i-1];
		dp[1][i] = qs[i] * (i-1);
		trace[1][i] = 1;
	}
	for(int i=2 ; i<=m*2 ; i++)
		solve(i, m, 1, n, 1, n);
	printf("%lld\n",dp[2*m][n]);
	return 0;
}
