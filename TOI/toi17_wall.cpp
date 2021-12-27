#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;

int comp[N][N], di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1}, cnt[N*N];
char t[N][N];
bool mark[N*N];

int main()
{
    int n, m, cnt_comp = 0, ans = 0;

    scanf(" %d %d",&n,&m);
    for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=m ; j++) scanf(" %c",&t[i][j]);

    for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=m ; j++) if(t[i][j] == '.')
    {
        comp[i][j] = ++cnt_comp;
        t[i][j] = ' ';
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
                if(ii < 1 || jj < 1 || ii > n || jj > m || t[ii][jj] != '.') continue;
                comp[ii][jj] = cnt_comp;
                t[ii][jj] = ' ';
                bfs.push({ii, jj});
            }
        }
    }
    
    for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=m ; j++) if(t[i][j] == 'X')
    {
        t[i][j] = 'x';
        queue<pair<int, int>> bfs;
        queue<int> cleaner;
        bfs.push({i, j});
        while(!bfs.empty())
        {
            int ni = bfs.front().first;
            int nj = bfs.front().second;
            bfs.pop();
            for(int k=0 ; k<4 ; k++)
            {
                int ii = ni+di[k], jj = nj+dj[k];
                if(ii < 1 || jj < 1 || ii > n || jj > m || t[ii][jj] != ' ') continue;
                if(!mark[comp[ii][jj]])
                {
                    mark[comp[ii][jj]] = true;
                    cleaner.push(comp[ii][jj]);
                }
                cnt[comp[ii][jj]]++;
            }
            for(int k=0 ; k<4 ; k++)
            {
                int ii = ni+di[k], jj = nj+dj[k];
                if(ii < 1 || jj < 1 || ii > n || jj > m || t[ii][jj] != 'X') continue;
                t[ii][jj] = 'x';
                bfs.push({ii, jj});
            }
        }
        while(!cleaner.empty())
        {
            ans = max(ans, cnt[cleaner.front()]);
            cnt[cleaner.front()] = 0;
            mark[cleaner.front()] = false;
            cleaner.pop();
        }
    }
    printf("%d\n",ans);
    return 0;
}
