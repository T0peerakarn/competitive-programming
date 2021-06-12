#include <bits/stdc++.h>
using namespace std;

int arr[2][110][110];

int main()
{
	int n, m, tot = 0;
	scanf(" %d %d",&n,&m);
	for(int k=0 ; k<2 ; k++)
		for(int i=1 ; i<=n ; i++)
			for(int j=1 ; j<=m ; j++)
			{
				scanf(" %d",&arr[k][i][j]);
				if(k == 0) tot += arr[k][i][j];
			}
	int ans = 0;
	for(int i=1 ; i<=n ; i++)
	{
		int dif = 0;
		for(int j=1 ; j<=m ; j++) dif += arr[1][i-1][j] + arr[1][i+1][j] - arr[0][i][j];
		ans = max(ans, tot+dif);
	}
	for(int j=1 ; j<=m ; j++)
	{
		int dif = 0;
		for(int i=1 ; i<=n ; i++) dif += arr[1][i][j-1] + arr[1][i][j+1] - arr[0][i][j];
		ans = max(ans, tot+dif);
	}
	printf("%d\n",ans);
	return 0;
}
