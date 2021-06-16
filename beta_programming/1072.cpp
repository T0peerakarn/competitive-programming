#include <bits/stdc++.h>
using namespace std;

int arr[500005];

int idx(int x, int s, int d, int n) {return (d) ? ((s <= x) ? -s+x+1 : n-s+x+1) : ((x <= s) ? -x+s+1 : n-x+s+1);}

int main()
{
	int n, q, s = 1, d = 1;
	scanf(" %d %d",&n,&q);
	for(int i=1 ; i<=n ; i++) scanf(" %d",&arr[i]);
	while(q--)
	{
		char c;
		scanf(" %c",&c);
		if(c == 'a')
		{
			int x, y;
			scanf(" %d %d",&x,&y);
			swap(arr[idx(x, s, d, n)], arr[idx(y, s, d, n)]);
		}
		else if(c == 'b')
		{
			int x, y;
			scanf(" %d %d",&x,&y);
			arr[idx(x, s, d, n)] = y;
		}
		else if(c == 'c')
		{
			int x;
			scanf(" %d",&x);
			s = (s <= x) ? x+1-s : n+x+1-s;
			d ^= 1;
		}
		else
		{
			int x;
			scanf(" %d",&x);
			printf("%d\n",arr[idx(x, s, d, n)]);
		}
	}
	return 0;
}
