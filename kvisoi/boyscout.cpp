#include <bits/stdc++.h>
using namespace std;

int arr[100005], dp[100005];

int main()
{
	int n;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++) scanf(" %d",&arr[i]);
	int len = 0;
	for(int i=n ; i>=1 ; i--)
	{
		int l=0, r=len;
		while(l != r)
		{
			int mid = (l+r+1)>>1;
			(dp[mid] <= arr[i]) ? l = mid : r = mid-1;
		}
		if(l == len) len++;
		dp[l+1] = arr[i];
	}
	printf("%d\n",len);
	return 0;
}
