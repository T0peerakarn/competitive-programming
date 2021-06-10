#include <bits/stdc++.h>
using namespace std;

bool mark[1010];

int main()
{
	int n, k, cnt = 0;
	scanf(" %d %d",&n,&k);
	for(int i=2 ; i<=n ; i++)
	{
		if(mark[i]) continue;
		for(int j=i ; j<=n ; j+=i)
		{
			if(mark[j]) continue;
			mark[j] = true;
			cnt++;
			if(cnt == k)
			{
				printf("%d\n",j);
				return 0;
			}
		}
	}
	return 0;
}
