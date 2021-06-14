#include <bits/stdc++.h>
using namespace std;

int dp[4][1010][1010];
char t[1010][1010];

int compute(int i, int j)
{
	if(t[i][j] == '0') return 0;
	int ret = 0;
	ret = max(ret, dp[0][i-1][j] + 1 + dp[2][i+1][j]);
	ret = max(ret, dp[1][i][j-1] + 1 + dp[3][i][j+1]);
	ret = max(ret, max(dp[0][i-1][j], dp[2][i+1][j]) + 1 + max(dp[1][i][j-1], dp[3][i][j+1]));
	return ret;
}

int main()
{
	int q;
	scanf(" %d",&q);
	while(q--)
	{
		memset(dp, 0, sizeof dp);
		int n, m;
		scanf(" %d %d",&n,&m);
		for(int i=1 ; i<=n ; i++)
			for(int j=1 ; j<=m ; j++)
				scanf(" %c",&t[i][j]);
		for(int i=1 ; i<=n ; i++)
			for(int j=1 ; j<=m ; j++)
			{
				dp[0][i][j] = (t[i][j] == '1') ? dp[0][i-1][j] + 1 : 0;
				dp[1][i][j] = (t[i][j] == '1') ? dp[1][i][j-1] + 1 : 0;
			}
		for(int i=n ; i>=1 ; i--)
			for(int j=m ; j>=1 ; j--)
			{
				dp[2][i][j] = (t[i][j] == '1') ? dp[2][i+1][j] + 1 : 0;
				dp[3][i][j] = (t[i][j] == '1') ? dp[3][i][j+1] + 1 : 0;
			}
		int ans = 0;
		for(int i=1 ; i<=n ; i++)
			for(int j=1 ; j<=m ; j++)
				ans = max(ans, compute(i, j));
		printf("%d\n",ans);
	}
	return 0;
}
