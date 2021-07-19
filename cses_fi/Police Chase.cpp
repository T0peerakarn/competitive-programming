#include <bits/stdc++.h>
using namespace std;

int cap[505][505], pa[505];
bool edge[505][505];
vector<int> g[505];

int bfs(int s, int t, int n)
{
    for(int i=1 ; i<=n ; i++) pa[i] = -1;
    queue<int> bfs;
    bfs.push(s);
    pa[s] = 0;
    while(!bfs.empty())
    {
        int u = bfs.front();
        bfs.pop();
        if(u == t) return 1;
        for(int v : g[u]) if(cap[u][v] && pa[v] == -1)
        {
            pa[v] = u;
            bfs.push(v);
        }
    }
    return 0;
}

int maxflow(int s, int t, int n)
{
    int ret = 0;
    while(bfs(s, t, n))
    {
        ret++;
        int u = t;
        while(u != s)
        {
            cap[pa[u]][u]--;
            cap[u][pa[u]]++;
            u = pa[u];
        }
    }
    return ret;
}

int main()
{
    int n, m;
    scanf(" %d %d",&n,&m);
    while(m--)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        cap[u][v] = cap[v][u] = 1;
        edge[u][v] = true;
    }
    printf("%d\n",maxflow(1, n, n));
    bfs(1, n, n);
    for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=n ; j++) if(pa[i] != -1 && pa[j] == -1 && edge[i][j]) printf("%d %d\n",i,j);
    return 0;
}
