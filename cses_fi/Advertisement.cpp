#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	long long ans = 0;
	scanf(" %d",&n);
	stack<pair<long long, long long>> stk;
	for(int i=1 ; i<=n ; i++)
	{
		long long w = 0, h;
		scanf(" %lld",&h);
		while(!stk.empty() && stk.top().second >= h)
		{
			w += stk.top().first;
			ans = max(ans, w*stk.top().second);
			stk.pop();
		}
		stk.push({w+1, h});
	}
	long long w = 0;
	while(!stk.empty())
	{
		ans = max(ans, (w+stk.top().first)*stk.top().second);
		w += stk.top().first;
		stk.pop();
	}
	printf("%lld\n",ans);
	return 0;
}
