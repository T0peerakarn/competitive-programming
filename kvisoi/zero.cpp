#include <bits/stdc++.h>
using namespace std;

#define N 100005

int arr[N];

int main()
{
	int n, t;
	scanf(" %d %d",&n,&t);
	for(int i=1 ; i<=n ; i++) scanf(" %d",&arr[i]);
	if(t == 1)
	{
		long long ans = 0;
		map<int, int> mp;
		mp[0] = 1;
		for(int i=1 ; i<=n ; i++)
		{
			arr[i] += arr[i-1];
			if(mp.count(arr[i])) ans += mp[arr[i]];
			mp[arr[i]]++;
		}
		printf("%lld\n",ans);
	}
	else
	{
		long long ans = 0;
		int last = 0;
		for(int i=1 ; i<=n ; i++)
		{
			if(arr[i] == 0) last = i;
			ans += last;
		} 
		printf("%lld\n",ans);
	}
	return 0;
}
  
