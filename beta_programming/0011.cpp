#include <bits/stdc++.h>
using namespace std;

bool mark[50];

int main()
{
	int ans = 0;
	for(int i=0 ; i<10 ; i++)
	{
		int d;
		scanf(" %d",&d);
		d %= 42;
		if(mark[d]) continue;
		mark[d] = 1;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
