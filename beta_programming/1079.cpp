#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int mod = 2009;

int dp[N];

int main()
{
	int n, k;
	scanf(" %d %d",&n,&k);
	dp[0] = 1;
	deque<int> sw = {0};
	int sum = 1;
	for(int i=1 ; i<=n ; i++)
	{
		while(!sw.empty() && sw.front()+k < i)
		{
			sum -= dp[sw.front()];
			sum %= mod;
			sum += mod;
			sum %= mod;
			sw.pop_front();
		}
		dp[i] = sum;
		sw.push_back(i);
		sum += dp[i];
		sum %= mod;
		sum += mod;
		sum %= mod;
	}
	printf("%d\n",dp[n]);
	return 0;
}
