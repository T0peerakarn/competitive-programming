#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int lv[N], pa[20][N];
vector<int> g[N];

void dfs(int u, int l)
{
    lv[u] = l;
    for(int v : g[u])
    {
        if(lv[v]) continue ;
        dfs(v, l+1);
        pa[0][v] = u;
    }
}

int distance(int u, int v)
{
    int ret = 0;
    if(lv[u] < lv[v]) swap(u, v);
    for(int i=19 ; i>=0 ; i--) if(lv[pa[i][u]] >= lv[v]) ret += (1<<i), u = pa[i][u];
    if(u == v) return ret;
    for(int i=19 ; i>=0 ; i--) if(pa[i][u] != pa[i][v]) ret += (1<<(i+1)), u = pa[i][u], v = pa[i][v];
    return ret+2;
}

int main()
{
    int n, q;
    scanf(" %d %d",&n,&q);
    for(int i=1 ; i<n ; i++)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        g[u].push_back(v), g[v].push_back(u);
    }
    dfs(1, 1);
    for(int i=1 ; i<20 ; i++) for(int j=1 ; j<=n ; j++) pa[i][j] = pa[i-1][pa[i-1][j]];
    while(q--)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        printf((distance(u, v)%2) ? "Road\n" : "Town\n");
    }
    return 0;
}
