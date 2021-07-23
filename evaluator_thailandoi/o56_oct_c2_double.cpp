#include <bits/stdc++.h>
using namespace std;

int arr[100100];
map<int, int> mp;

int main()
{
	int n;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++)
	{
		scanf(" %d",&arr[i]);
		arr[i] += arr[i-1];
	}

	//A
	for(int i=1 ; i<=n ; i++)
		if(arr[n] - arr[i] == arr[i])
		{
			printf("%d\n",i);
			return 0;
		}

	//AB
	int a=1000000, b=1000000;
	for(int i=1 ; i<=n ; i++)
		mp[arr[i]] = i;
	for(int i=1 ; i<=n ; i++)
	{
		if(arr[i] < arr[n] - arr[i]) continue;
		int x = arr[i], y = arr[n] - arr[i];
		if((x-y)%2 == 0 && mp.count((x-y)>>1))
		{
			if(a > mp[(x-y)>>1])
			{
				a = mp[(x-y)>>1];
				b = i;
			}
			else if(a == mp[(x-y)>>1])
				b = min(b, i);
		}
	}
	printf((a == 1000000) ? "NO\n" : "%d %d\n",a,b);
	return 0;
}
