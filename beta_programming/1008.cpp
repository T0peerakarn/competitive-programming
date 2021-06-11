#include <bits/stdc++.h>
using namespace std;

int arr[300];

int main()
{
	int n, L = 300, R = 0;
	scanf(" %d",&n);
	while(n--)
	{
		int l, h, r;
		scanf(" %d %d %d",&l,&h,&r);
		L = min(L, l), R = max(R, r);
		for(int i=l ; i<r ; i++) arr[i] = max(arr[i], h);
	}
	for(int i=L ; i<=R ; i++) if(arr[i] != arr[i-1]) printf("%d %d ",i,arr[i]);
	return 0;
}
