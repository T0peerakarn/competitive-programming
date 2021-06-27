#include <bits/stdc++.h>
using namespace std;

#define N 5005

long long qs[N], dp[N][N], pos[N][N];

int main()
{
	int n;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++)
	{
		scanf(" %lld",&qs[i]);
		qs[i] += qs[i-1];
		dp[i][i] = 0;
		pos[i][i] = i;
	}
	for(int sz=2 ; sz<=n ; sz++)
		for(int i=1 ; i<=n ; i++)
		{
			int j = i+sz-1;
			if(j > n) break;
			dp[i][j] = 1e18;
			int l = pos[i][j-1], r = pos[i+1][j];
			if(r != j) r++;
			for(int k=l ; k<r ; k++)
			{
				long long now = dp[i][k] + dp[k+1][j] + qs[j] - qs[i-1];
				if(now < dp[i][j])
				{
					dp[i][j] = now;
					pos[i][j] = k;
				}
			}
		}
	printf("%lld\n",dp[1][n]);
	return 0;
}
