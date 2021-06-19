#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long l=0, r=1e9;
	while(l != r)
	{
		long long mid = (l+r)>>1;
		((mid*(mid+1))/2) >= n ? r = mid : l = mid+1;
	}
	cout << l;
	return 0;
}
