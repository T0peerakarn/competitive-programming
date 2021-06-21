#include<bits/stdc++.h>
using namespace std;

struct BFS
{
	int i, j;
};

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
char t[2020][2020];
queue<BFS> bfs;

int main()
{
	int n, ans = 0;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=n ; j++)
			scanf(" %c",&t[i][j]);
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=n ; j++)
			if(t[i][j] == 'X')
			{
				ans++;
				bfs.push({i, j});
				t[i][j] = '_';
				while(!bfs.empty())
				{
					int ni = bfs.front().i;
					int nj = bfs.front().j;
					bfs.pop();
					for(int k=0 ; k<4 ; k++)
					{
						int ii = ni+di[k], jj = nj+dj[k];
						if(ii < 1 || jj < 1 || ii > n || jj > n || t[ii][jj] != 'X') continue ;
						t[ii][jj] = '_';
						bfs.push({ii, jj});
					}
				}
			}
	printf("%d\n",ans);
	return 0;
}
