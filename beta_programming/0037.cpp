#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, l, k, c, total = 0;
	scanf(" %d %d %d %d %d",&n,&m,&l,&k,&c);
	total += l*k*c;
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=m ; j++)
		{
			int d;
			scanf(" %d",&d);
			total += d;
		}
	printf("%d\n",total/c + (total%c ? 1 : 0));
	return 0;
}
