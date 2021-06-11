#include <bits/stdc++.h>
using namespace std;

int dis[55][55], di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
char t[55][55];
queue<pair<pair<int, int>, int>> bfs;
bool visit[55][55];

int main()
{
	int n, m, si, sj, ei, ej;
	scanf(" %d %d",&n,&m);
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=m ; j++)
		{
			scanf(" %c",&t[i][j]);
			if(t[i][j] == 'D') ei=i, ej=j;
			else if(t[i][j] == 'S') si=i, sj=j;
			else if(t[i][j] == '*') bfs.push({{i, j}, -1});
		}

	dis[si][sj] = 0;
	visit[si][sj] = true;
	bfs.push({{si, sj}, 0});
	while(!bfs.empty())
	{
		int ni = bfs.front().first.first;
		int nj = bfs.front().first.second;
		int nw = bfs.front().second;
		bfs.pop();
		for(int k=0 ; k<4 ; k++)
		{
			int ii = ni+di[k], jj = nj+dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > m || t[ii][jj] == 'X') continue;
			if(nw == -1)
			{
				if(t[ii][jj] == 'D' || dis[ii][jj] == -1) continue ;
				dis[ii][jj] = -1;
				bfs.push({{ii, jj}, -1});
			}
			else
			{
				if(visit[ii][jj] || dis[ii][jj] == -1) continue;
				visit[ii][jj] = true;
				dis[ii][jj] = nw+1;
				bfs.push({{ii, jj}, nw+1});
			}
		}
	}
	printf((!visit[ei][ej]) ? "KAKTUS\n" : "%d\n",dis[ei][ej]);
	return 0;
}
