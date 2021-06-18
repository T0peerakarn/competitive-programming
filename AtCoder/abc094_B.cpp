#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, x, l = 0, r = 0;
	scanf(" %d %d %d",&n,&m,&x);
	while(m--)
	{
		int d;
		scanf(" %d",&d);
		if(d < x) l++;
		else if(x < d) r++;
	}
	printf("%d\n",min(l, r));
	return 0;
}
