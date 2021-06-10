#include <bits/stdc++.h>
using namespace std;

char t[22][22];

int main()
{
	int n, m;
	scanf(" %d %d",&n,&m);
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=m ; j++)
			scanf(" %c",&t[i][j]);
	for(int j=1 ; j<=m ; j++)
	{
		int d, p = 0;
		scanf(" %d",&d);
		for(int i=1 ; i<=n ; i++)
		{
			if(t[i][j] == 'O') break;
			p = i;
		}
		for(int i=p ; i>=1 && d>0 ; i--, d--)
			t[i][j] = '#';
	}
	for(int i=1 ; i<=n ; i++)
	{
		for(int j=1 ; j<=m ; j++)
			printf("%c",t[i][j]);
		printf("\n");
	}
	return 0;
}
