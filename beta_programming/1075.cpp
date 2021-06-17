#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> arr[100005];

int main()
{
	int n;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++) scanf(" %lld %lld",&arr[i].second,&arr[i].first);
	sort(arr+1, arr+n+1);
	pair<long long, long long> ans = arr[1];
	for(int i=2 ; i<=n ; i++)
	{
		arr[i].second += arr[i-1].second;
		if(ans.second * arr[i].first < arr[i].second * ans.first) ans = arr[i];
	}
	printf("%lld %lld\n",ans.second,ans.first);
	return 0;
}
