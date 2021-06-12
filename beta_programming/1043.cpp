#include <bits/stdc++.h>
using namespace std;

map<int, int> ans;

int main()
{
	for(int i=2 ; i<=10000 ; i++)
	{
		long long tmp = i*i;
		int cnt = 2;
		while(true)
		{
			ans[tmp] = max(ans[tmp], cnt);
			tmp *= i;
			cnt++;
			if(tmp > 100000000) break;
		}
	}
	int n;
	scanf(" %d",&n);
	while(n--)
	{
		int d;
		scanf(" %d",&d);
		if(ans.count(d)) printf("%d\n",ans[d]);
		else printf("NO\n");
	}
	return 0;
}
