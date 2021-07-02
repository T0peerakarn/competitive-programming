#include <bits/stdc++.h>
using namespace std;

const int N = 3e3+5;

long long arr[N];

int main()
{
	int n;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++)
	{
		scanf(" %lld",&arr[i]);
		arr[i] -= i;
	}
	long long y_intercept = 0, x = -3000;
	priority_queue<long long> slope;
	for(int i=1 ; i<=n ; i++)
	{
		y_intercept += abs(x-arr[i]);
		if(!slope.empty()) slope.pop();
		slope.push(arr[i]);
		slope.push(arr[i]);
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
		y_intercept -= i * (rev.top() - x);
		x = rev.top();
		rev.pop();
	}
	printf("%lld\n",y_intercept);
	return 0;
}
