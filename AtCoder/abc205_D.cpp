#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[100005];
map<long long, int> mp;

bool Try(long long num, long long no)
{
	int l=0, r=n;
	while(l != r)
	{
		int mid = (l+r+1)>>1;
		(arr[mid] < num) ? l = mid : r = mid-1;
	}
	return (num-l >= no);
}

long long Fix(long long num)
{
	if(!mp.count(num)) return num;
	int pos = mp[num];
	int l=pos, r=n;
	while(l != r)
	{
		int mid = (l+r+1)>>1;
		(arr[mid] - num == mid - pos) ? l = mid : r = mid-1;
	}
	return arr[l]+1;
}

long long Solve()
{
	long long d, l, r;
	scanf(" %lld",&d);
	l=1, r=2e18;
	while(l != r)
	{
		long long mid = (l+r)>>1;
		(Try(mid, d)) ? r = mid : l = mid+1;
	}
	return Fix(l);
}

int main()
{
	int q;
	scanf(" %d %d",&n,&q);
	for(int i=1 ; i<=n ; i++)
	{
		scanf(" %lld",&arr[i]);
		mp[arr[i]] = i;
	}
	while(q--) printf("%lld\n",Solve());
	return 0;
}
