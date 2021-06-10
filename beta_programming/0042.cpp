#include <bits/stdc++.h>
using namespace std;

int main()
{
	int q;
	scanf(" %d",&q);
	while(q--)
	{
		int n;
		scanf(" %d",&n);
		long double ans = 1;
		for(int i=0 ; i<n ; i++) ans *= 2;
		printf("%.0LF\n",ans);
	}
	return 0;
}
