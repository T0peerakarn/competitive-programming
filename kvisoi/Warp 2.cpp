#include <bits/stdc++.h>
using namespace std;

#define N 150005

int pa[30][N];

int main()
{
	int n, q;
	scanf(" %d %d",&n,&q);
	for(int i=1 ; i<=n ; i++) scanf(" %d",&pa[0][i]);
	for(int i=1 ; i<30 ; i++) for(int j=1 ; j<=n ; j++) pa[i][j] = pa[i-1][pa[i-1][j]];
	while(q--)
	{
		int u, k;
		scanf(" %d %d",&u,&k);
		k++;
		for(int i=29 ; i>=0 ; i--) if((1<<i)&k) u = pa[i][u];
		printf("%d\n",u);
	}
	return 0;
}
