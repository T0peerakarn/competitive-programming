#include<bits/stdc++.h>
using namespace std;

int arr[110], qs[110];
int dp[2][2020][2020];
bool visit[2][2020][2020];

int cost(int a, int b, int c)
{
	return max(max(abs(a-b), abs(b-c)), abs(a-c));
}

int main()
{
	int n;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++)
	{
		scanf(" %d",&arr[i]);
		qs[i] = arr[i] + qs[i-1];
	}
	visit[0][0][0] = true;
	for(int i=1 ; i<=n ; i++)
	{
		for(int j=0 ; j<=1000 ; j++)
			for(int k=0 ; k<=1000 ; k++)
				visit[i%2][j][k] = false;
		for(int j=0 ; j<=1000 ; j++)
			for(int k=0 ; k<=1000 ; k++)
				if(visit[(i-1)%2][j][k])
				{
					visit[i%2][j+arr[i]][k] = visit[i%2][j][k+arr[i]] = visit[i%2][j][k] = true;
					dp[i%2][j+arr[i]][k] = cost(j+arr[i], k, qs[i] - j - arr[i] - k);
					dp[i%2][j][k+arr[i]] = cost(j, k+arr[i], qs[i] - j - k - arr[i]);
					dp[i%2][j][k] = cost(j, k, qs[i] - j - k);
				}
	}
	int ans = 1e9;
	for(int j=0 ; j<=2000 ; j++)
		for(int k=0 ; k<=2000 ; k++)
			if(visit[n%2][j][k]) ans = min(ans, dp[n%2][j][k]);
	printf("%d\n",ans);
	return 0;
}
