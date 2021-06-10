#include <bits/stdc++.h>
using namespace std;

int s[11], b[11];

int main()
{
	int n, ans = 1e9;
	scanf(" %d",&n);
	for(int i=0 ; i<n ; i++)
		scanf(" %d %d",&s[i],&b[i]);
	for(int i=1 ; i<(1<<n) ; i++)
	{
		int S = 1, B = 0, tmp = i;
		for(int j=0 ; j<n ; j++) if((1<<j)&i) S *= s[j], B += b[j];
		ans = min(ans, abs(S-B));
	}
	printf("%d\n",ans);
	return 0;
}
