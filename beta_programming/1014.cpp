#include <bits/stdc++.h>
using namespace std;

int arr[5000], cnt[2];

int main()
{
	int w, h, n;
	scanf(" %d %d %d",&w,&h,&n);
	while(n--)
	{
		int x, a;
		scanf(" %d %d",&x,&a);
		arr[x]++;
		arr[x+a]--;
	}
	for(int i=0 ; i<w ; i++)
	{
		if(i) arr[i] += arr[i-1];
		if(arr[i] < 2) cnt[arr[i]]++;
	}
	printf("%d %d\n",cnt[0]*h,cnt[1]*h);
	return 0;
}  
