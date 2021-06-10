#include <bits/stdc++.h>
using namespace std;

int main()
{
	int ans = 0;
	for(int i=0 ; i<3 ; i++)
	{
		int d;
		scanf(" %d",&d);
		while(d != 1)
		{
			d /= 2;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
