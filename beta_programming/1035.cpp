#include <bits/stdc++.h>
using namespace std;

bool prime[2000005], palindrome[2000005];

bool check(int num)
{
	vector<int> v;
	while(num)
	{
		v.push_back(num%10);
		num/=10;
	}
	int sz = v.size();
	for(int i=0 ; i<sz ; i++) if(v[i] != v[sz-i-1]) return false;
	return true;
}

int main()
{
	memset(prime, true, sizeof prime);
	for(int i=2 ; i<=2000000 ; i++)
	{
		if(!prime[i]) continue;
		for(int j=i+i ; j<=2000000 ; j+=i) prime[j] = false;
	}
	for(int i=2 ; i<=2000000 ; i++)
	{
		if(!prime[i]) continue;
		palindrome[i] = check(i);
	}
	int n;
	scanf(" %d",&n);
	for(int i=n ; i<=2000000 ; i++)
		if(prime[i] && palindrome[i])
		{
			printf("%d\n",i);
			return 0;
		}
	return 0;
}
