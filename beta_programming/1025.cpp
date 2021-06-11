#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
	return (a%b == 0) ? b : gcd(b, a%b);
}

int main()
{
	int n;
	scanf(" %d",&n);
	n -= 2;
	long long a, b;
	scanf(" %lld %lld",&a,&b);
	long long num = a*b / gcd(a, b);
	while(n--)
	{
		long long d;
		scanf(" %lld",&d);
		num = num*d / gcd(num, d);
	}
	printf("%lld\n",num);
	return 0;
}
