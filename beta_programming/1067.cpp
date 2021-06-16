#include <bits/stdc++.h>
using namespace std;

int arr[110][110], di[5] = {0, -1, 0, 1, 0}, dj[5] = {0, 0, 1, 0, -1};
bool visit[110][110];

int main()
{
	int n, m, q;
	scanf(" %d %d %d",&m,&n,&q);
	for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=m ; j++) scanf(" %d",&arr[i][j]);
	while(q--)
	{
		for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=m ; j++) visit[i][j] = false;
		int ni, nj;
		scanf(" %d %d",&nj,&ni);
		visit[ni][nj] = true;
		while(true)
		{
			int k = arr[ni][nj];
			ni += di[k], nj += dj[k];
			if(visit[ni][nj])
			{
				printf("NO\n");
				break;
			}
			else if(ni == 0)
			{
				printf("N\n");
				break;
			}
			else if(ni == n+1)
			{
				printf("S\n");
				break;
			}
			else if(nj == 0)
			{
				printf("W\n");
				break;
			}
			else if(nj == m+1)
			{
				printf("E\n");
				break;
			}
			visit[ni][nj] = true;
		}
	}
	return 0;
}
