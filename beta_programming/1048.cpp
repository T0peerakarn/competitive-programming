#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k, n;
	scanf(" %d %d",&k,&n);
	long long ans = 0;
	for(long long i=1 ; n>0 ; i++, n/=2)
	{
		ans += i*(n/2);
		if(n%2) ans += i;
	}
	printf("%lld\n",ans);
	return 0;
}
