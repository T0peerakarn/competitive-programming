#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, mn = 2e9, mx = -2e9;
	scanf(" %d",&n);
	while(n--)
	{
		int d;
		scanf(" %d",&d);
		mn = min(mn, d);
		mx = max(mx, d);
	}
	printf("%d\n%d\n",mn,mx);
	return 0;
}
