#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;

int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
char t[N][N];
bool water[N][N];

int main()
{
    int n, m, ans = 0;

    scanf(" %d %d",&n,&m);
    for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=m ; j++) scanf(" %c",&t[i][j]);

    water[1][1] = true;
    queue<pair<int, int>> bfs;
    bfs.push({1, 1});
    while(!bfs.empty())
    {
        int ni = bfs.front().first;
        int nj = bfs.front().second;
        bfs.pop();
        for(int k=0 ; k<4 ; k++)
        {
            int ii = ni+di[k], jj = nj+dj[k];
            if(ii < 1 || jj < 1 || ii > n || jj > m || t[ii][jj] != '.' || water[ii][jj]) continue;
            water[ii][jj] = true;
            bfs.push({ii, jj});
        }
    }
    
    for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=m ; j++) if(t[i][j] == 'X')
    {
        int cnt = 0;
        t[i][j] = 'x';
        queue<pair<int, int>> bfs;
        bfs.push({i, j});
        while(!bfs.empty())
        {
            int ni = bfs.front().first;
            int nj = bfs.front().second;
            bfs.pop();
            for(int k=0 ; k<4 ; k++)
            {
                int ii = ni+di[k], jj = nj+dj[k];
                if(ii < 1 || jj < 1 || ii > n || jj > m) continue;
                if(water[ii][jj]) cnt++;
                else if(t[ii][jj] == 'X')
                {
                    t[ii][jj] = 'x';
                    bfs.push({ii, jj});
                }
            }
        }
        ans = max(ans, cnt);
    }
    printf("%d\n",ans);
    return 0;
}
