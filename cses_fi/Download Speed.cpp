#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int pa[N];
long long capacity[N][N];
vector<int> g[N];

long long path(int s, int t, int n)
{
    for(int i=1 ; i<=n ; i++) pa[i] = -1;
    pa[s] = 0;
    queue<pair<int, long long>> bfs;
    bfs.push({s, 1e9});
    while(!bfs.empty())
    {
        int u = bfs.front().first;
        long long w = bfs.front().second;
        bfs.pop();
        if(u == t) return w;
        for(int v : g[u]) if(capacity[u][v] && pa[v] == -1)
        {
            pa[v] = u;
            bfs.push({v, min(w, capacity[u][v])});
        }
    }
    return 0;
}

long long maxflow(int s, int t, int n)
{
    long long ret = 0, flow;
    while(flow = path(s, t, n))
    {
        ret += flow;
        int i = t;
        while(i != s)
        {
            capacity[pa[i]][i] -= flow;
            capacity[i][pa[i]] += flow;
            i = pa[i];
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
        long long w;
        scanf(" %d %d %lld",&u,&v,&w);
        g[u].push_back(v);
        g[v].push_back(u);
        capacity[u][v] += w;
    }
    printf("%lld\n",maxflow(1, n, n));
    return 0;
}
