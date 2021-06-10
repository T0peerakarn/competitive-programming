#include <bits/stdc++.h>
using namespace std;

int dp[25][2];

int main()
{
	dp[0][0] = 1;
	dp[0][1] = 0;
	for(int i=1 ; i<25 ; i++)
	{
		dp[i][0] = 1 + dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	vector<int> query;
	while(true)
	{
		int d;
		scanf(" %d",&d);
		if(d == -1) break;
		query.push_back(d);
	}
	for(auto x : query)
		printf("%d %d\n",dp[x][0],1+dp[x][0]+dp[x][1]);
	return 0;
}
