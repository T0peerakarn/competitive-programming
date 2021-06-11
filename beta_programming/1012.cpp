#include <bits/stdc++.h>
using namespace std;

int cnt[6];

int main()
{
	int n;
	scanf(" %d",&n);
	while(n--)
	{
		for(int i=1 ; i<=5 ; i++)
		{
			int d;
			scanf(" %d",&d);
			cnt[i] += d;
		}
	}
	int ans = cnt[1] * 8 + cnt[2] * 6 + cnt[3] * 4 + cnt[4] * 2 + cnt[5];
	printf("%d\n",ans/8 + (ans%8 ? 1 : 0));
	return 0;
}
