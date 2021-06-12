#include <bits/stdc++.h>
using namespace std;

double dp[1050000];
vector<int> state[22];

int main()
{
	dp[0] = 100;
	int n;
	scanf(" %d",&n);
	for(int i=1 ; i<(1<<n) ; i++) state[__builtin_popcount(i)].push_back(i);
	for(int i=1 ; i<=n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			double v;
			scanf(" %lf",&v);
			v /= 100;
			for(auto s : state[i]) if(s&(1<<j)) dp[s] = max(dp[s], dp[s-(1<<j)]*v);
		}
	}
	printf("%.12lf\n",dp[(1<<n)-1]);
	return 0;
}
