#include <bits/stdc++.h>
using namespace std;
 
long long arr[45];
map<long long, int> mp;
 
int main()
{
	int n;
	long long x, ans = 0;
	scanf(" %d %lld",&n,&x);
	for(int i=0 ; i<n ; i++) scanf(" %lld",&arr[i]);
	int t = n/2;
	for(int i=0 ; i<(1<<t) ; i++)
	{
		int tmp = i;
		long long sum = 0;
		for(int j=0 ; j<t ; j++, tmp/=2) sum += arr[j]*(tmp%2);
		mp[sum]++;
	}
	for(int i=0 ; i<(1<<(n-t)) ; i++)
	{
		int tmp = i;
		long long sum = 0;
		for(int j=t ; j<n ; j++, tmp/=2) sum += arr[j]*(tmp%2);
		if(mp.count(x-sum)) ans += mp[x-sum];
	}
	printf("%lld\n",ans);
	return 0;
}
