#include <bits/stdc++.h>
using namespace std;

int dp[10005];
vector<int> g[10005];

int main()
{
	int k, n, m, ans = 1;
	scanf(" %d %d %d",&k,&n,&m);
	while(m--)
	{
		int u, v;
		scanf(" %d %d",&u,&v);
		g[u].push_back(v);
	}
	dp[1] = k+1;
	for(int i=1 ; i<=n ; i++)
	{
		if(dp[i] == 0) continue;
		ans = max(ans, i);
		for(auto x : g[i]) dp[x] = max(dp[x], dp[i]-1);
	}
	printf("%d\n",ans);
	return 0;
}
