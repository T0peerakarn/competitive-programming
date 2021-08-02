#include <bits/stdc++.h>
using namespace std;

struct road
{
    int u, c, w;
};

typedef long long lli;

lli dp[303][2002];
vector<road> g[303];

lli solve(int u, int k)
{
    if(k < 0) return -1e18;
    if(dp[u][k] != -1) return dp[u][k];
    lli ret = solve(u, k-1);
    for(road x : g[u]) ret = max(ret, solve(x.u, k-x.w)+x.c);
    return dp[u][k] = ret;
}

int main()
{
    
    int n, m, k, s, t;
    scanf(" %d %d %d %d %d",&n,&m,&k,&s,&t);
    while(m--)
    {
        int u, v, c, w;
        scanf(" %d %d %d %d",&u,&v,&c,&w);
        g[u].push_back({v, c, w});
        g[v].push_back({u, c, w});
    }
    memset(dp, -1, sizeof dp);
    dp[s][0] = 0;
    long long ans = solve(t, k);
    printf((ans < 0) ? "Impossible" : "%lld\n",ans);
    return 0;
}
