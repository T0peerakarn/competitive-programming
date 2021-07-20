#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int capacity[N][N], pa[N], pb[N];
bool edge[N][N], ans[N][N];
vector<int> g[N];

void AddEdge(int u, int v)
{
    if(edge[u][v]) return;
    edge[u][v] = true;
    g[u].push_back(v);
    g[v].push_back(u);
    capacity[u][v] = 1;
}

int bfs(int s, int t, int n)
{
    for(int i=0 ; i<n ; i++) pa[i] = -1;
    queue<int> bfs;
    bfs.push(s);
    pa[s] = 0;
    while(!bfs.empty())
    {
        int u = bfs.front();
        bfs.pop();
        if(u == t) return 1;
        for(int v : g[u]) if(capacity[u][v] && pa[v] == -1)
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
        int u = t, g = 0;
        while(u != s)
        {
            if(u != t)
            {
                if(g)
                {
                    pb[u] = g;
                    g = 0;
                }
                else g = u;
            }
            capacity[pa[u]][u]--;
            capacity[u][pa[u]]++;
            u = pa[u];
        }
    }
    return ret;
}

int main()
{   
    int n, m, k;
    scanf(" %d %d %d",&n,&m,&k);
    while(k--)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        AddEdge(0, u);
        AddEdge(u, v+n);
        AddEdge(v+n, n+m+1);
    }    
    printf("%d\n",maxflow(0, n+m+1, n+m+2));
    for(int i=1 ; i<=n ; i++) if(pb[i]) printf("%d %d\n",i,pb[i]-n);
    return 0;
}
