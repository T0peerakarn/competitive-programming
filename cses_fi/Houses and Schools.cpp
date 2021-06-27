#include <bits/stdc++.h>
using namespace std;

#define N 3005

long long arr[N], cost[N][N], dp[N][N];

void solve(int k, int l, int r, int a, int b)
{
	if(r < l) return;
	int mid = (l+r)>>1, pos;
	long long opt = 1e18;
	for(int i=a ; i<mid && i<=b ; i++)
	{
		long long now = dp[k-1][i] + cost[i][mid];
		if(now < opt)
		{
			opt = now;
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
	for(long long i=1, sum = 0, upd = 0; i<=n ; i++)
	{
		scanf(" %lld",&arr[i]);
		upd += arr[i];
		dp[1][i] = sum;
		sum += upd;
	}
	for(int i=1 ; i<=n ; i++)
	{
		deque<pair<long long, int>> sw;
		long long sum = 0, upd = 0;
		for(int j=i+1 ; j<=n ; j++)
		{
			cost[i][j] = sum;
			while(!sw.empty() && sw.front().second < j)
			{
				upd -= sw.front().first;
				sw.pop_front();
			}
			sw.push_back({arr[j], j+j-i-1});
			upd += arr[j];
			sum += upd;
		}
	}
	for(int i=2 ; i<=k ; i++) solve(i, i, n, i-1, n);
	long long ans = 1e18;
	for(long long i=n, sum = 0, upd = 0; i>=k ; i--)
	{
		ans = min(ans, dp[k][i] + sum);
		upd += arr[i];
		sum += upd;
	}
	printf("%lld\n",ans);
	return 0;
}
