#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	scanf(" %lld",&n);
	long long l=1, r=n*n;
	while(l != r)
	{
		long long mid = (l+r)>>1, cnt = 0;
		for(long long i=1 ; i<=n ; i++) cnt += min(n, mid/i);
		(cnt > n*n/2ll) ? r = mid : l = mid+1;
	}
	printf("%lld\n",l);
	return 0;
}
