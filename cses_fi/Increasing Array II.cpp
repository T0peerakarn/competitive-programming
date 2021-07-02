#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf(" %d",&n);
	long long y_intercept = 0, x = 0;
	priority_queue<long long> slope;
	for(int i=1 ; i<=n ; i++)
	{
		int d;
		scanf(" %d",&d);
		y_intercept += abs(d);
		if(!slope.empty()) slope.pop();
		slope.push(d);
		slope.push(d);
	}
	slope.pop();
	stack<long long> rev;
	while(!slope.empty())
	{
		rev.push(slope.top());
		slope.pop();
	}
	for(int i=n ; i>=1 ; i--)
	{
		if(x <= rev.top())
		{
			y_intercept -= i * (rev.top() - x);
			x = rev.top();
		}
		rev.pop();
	}
	printf("%lld\n",y_intercept);
	return 0;
}
