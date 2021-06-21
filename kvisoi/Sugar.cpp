#include<bits/stdc++.h>
using namespace std;

int arr[100100];

int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int n, l = 1e5, r = 1, ans = 0;
		scanf(" %d",&n);
		for(int i=1 ; i<=n ; i++)
		{
			scanf(" %d",&arr[i]);
			if(arr[i] == 1)
			{
				l = min(l, i);
				r = max(r, i);
			}
		}
		for(int i=l ; i<=r ; i++)
			if(arr[i] == 0) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
