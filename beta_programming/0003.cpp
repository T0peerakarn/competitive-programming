#include <bits/stdc++.h>
using namespace std;

int arr[105][105];

int main()
{
	int n, m;
	scanf(" %d %d",&n,&m);
	for(int k=0 ; k<2 ; k++)
		for(int i=1 ; i<=n ; i++)
			for(int j=1 ; j<=m ; j++)
			{
				int d;
				scanf(" %d",&d);
				arr[i][j] += d;
			}
	for(int i=1 ; i<=n ; i++)
	{
		for(int j=1 ; j<=m ; j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	return 0;
}
