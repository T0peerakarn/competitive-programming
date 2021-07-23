#include <bits/stdc++.h>
using namespace std;

int arr[2][105][105];
int dp[1205][105][105];
bool visit[1205][105][105];

int main()
{
	int n, m;
	scanf(" %d %d",&n,&m);
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=m ; j++)
		{
			int d;
			scanf(" %d",&d);
			while(true)
			{
				if(d%2) break;
				d/=2;
				arr[0][i][j]++;
			}
			while(true)
			{
				if(d%3) break;
				d/=3;
				arr[1][i][j]++;
			}
		}
	visit[arr[1][1][1]][1][1] = true;
	dp[arr[1][1][1]][1][1] = arr[0][1][1];
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=m ; j++)
			for(int k=arr[1][i][j] ; k<=1200 ; k++)
			{
				if(visit[k-arr[1][i][j]][i][j-1])
				{
					visit[k][i][j] = true;
					dp[k][i][j] = max(dp[k][i][j], dp[k-arr[1][i][j]][i][j-1] + arr[0][i][j]);
				}
				if(visit[k-arr[1][i][j]][i-1][j])
				{
					visit[k][i][j] = true;
					dp[k][i][j] = max(dp[k][i][j], dp[k-arr[1][i][j]][i-1][j] + arr[0][i][j]);
				}
			}
	int ans = 0;
	for(int k=0 ; k<=1200 ; k++)
		if(visit[k][n][m]) ans = max(ans, min(dp[k][n][m], k));
	printf("%d\n",ans);
	return 0;
}
