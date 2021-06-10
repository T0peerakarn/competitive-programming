#include <bits/stdc++.h>
using namespace std;

int cnt[10005];

int main()
{
	int n, mx = 0;
	scanf(" %d",&n);
	while(n--)
	{
		int d;
		scanf(" %d",&d);
		cnt[d]++;
		mx = max(mx, cnt[d]);
	}	
	for(int i=1 ; i<=10000 ; i++)
		if(cnt[i] == mx) printf("%d ",i);
	return 0;
}
