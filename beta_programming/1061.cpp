#include <bits/stdc++.h>
using namespace std;

int arr[20][20];
bool visit[20][20];

int main()
{
	int n, si, sj, mx = -5;
	scanf(" %d %d %d",&n,&sj,&si);
	sj--, si--;
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++)
			scanf(" %d",&arr[i][j]);
	queue<pair<int, int>> bfs;
	bfs.push({si, sj});
	visit[si][sj] = true;
	while(!bfs.empty())
	{
		int ni = bfs.front().first;
		int nj = bfs.front().second;
		bfs.pop();
		mx = max(mx, arr[ni][nj]);
		if(ni+1 < n && arr[ni+1][nj] != 100 && arr[ni+1][nj] > arr[ni][nj] && !visit[ni+1][nj])
		{
			visit[ni+1][nj] = true;
			bfs.push({ni+1, nj});
		}
		if(ni-1 >= 0 && arr[ni-1][nj] != 100 && arr[ni-1][nj] > arr[ni][nj] && !visit[ni-1][nj])
		{
			visit[ni-1][nj] = true;
			bfs.push({ni-1, nj});
		}
		if(nj+1 < n && arr[ni][nj+1] != 100 && arr[ni][nj+1] > arr[ni][nj] && !visit[ni][nj+1])
		{
			visit[ni][nj+1] = true;
			bfs.push({ni, nj+1});
		}
		if(nj-1 >= 0 && arr[ni][nj-1] != 100 && arr[ni][nj-1] > arr[ni][nj] && !visit[ni][nj-1])
		{
			visit[ni][nj-1] = true;
			bfs.push({ni, nj-1});
		}
	}
	printf("%d\n",mx);
	return 0;
}
