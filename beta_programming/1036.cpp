#include <bits/stdc++.h>
using namespace std;

long long dp[300];

int main()
{
	int n, p;
	scanf(" %d %d",&n,&p);
	for(int i=1 ; i<(1<<p) ; i++) dp[i] = 1e15;
	while(n--)
	{
		long long w;
		scanf(" %lld",&w);
		int state = 0;
		for(int i=0 ; i<p ; i++)
		{
			int d;
			scanf(" %d",&d);
			state *= 2;
			state += d;
		}
		for(int i=0 ; i<(1<<p) ; i++) dp[i|state] = min(dp[i|state], dp[i] + w);
	}
	printf("%lld\n",dp[(1<<p)-1]);
	return 0;
}
