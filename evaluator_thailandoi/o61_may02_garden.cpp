#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mod 1000003

int col[1010], dp[1010][1050];
vector<int> g[1010], idx[15];

int main()
{
	int n, m, c;
	scanf(" %d %d %d",&n,&m,&c);
	for(int i=0 ; i<n ; i++)
	{
		scanf(" %d",&col[i]);
		dp[i][1<<col[i]] = 1;
	}
	for(int i=0 ; i<m ; i++)
	{
		int u, v;
		scanf(" %d %d",&u,&v);
		g[u].pb(v), g[v].pb(u);
	}
	for(int i=0 ; i<(1<<c) ; i++)
		idx[__builtin_popcount(i)].push_back(i);
	for(int i=2 ; i<=c ; i++)
	{
		for(auto x : idx[i])
		{
			for(int j=0 ; j<n ; j++)
			{
				if((1<<col[j]) & x)
				{
					for(auto y : g[j])
					{
						dp[j][x] += dp[y][x-(1<<col[j])];
						dp[j][x] %= mod;
					}
				}
			}
		}
	}
	int ans = 0;
	for(int j=0 ; j<n ; j++)
	{
		ans += dp[j][(1<<c)-1];
		ans %= mod;
	}
	printf("%d\n",ans);
	return 0;
}
