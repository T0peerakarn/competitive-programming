#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
const int N = 2e5+5;

struct DIJK
{
    int node;
    long long weight;
    bool operator < (const DIJK & o) const {return weight > o.weight;}
};

long long dis[N], dp[N];
bool reached[N];
vector<int> g[N];
priority_queue<DIJK> dijk;

long long opt(int u)
{
    if(dp[u] != -1) return dp[u];
    long long ret = 0;
    for(int v : g[u]) if(dis[v]+1 == dis[u])
    {
        ret += opt(v);
        ret %= mod;
    }
    return dp[u] = ret;
}

int main()
{
    int n, m;
    scanf(" %d %d",&n,&m);
    while(m--)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        g[u].push_back(v), g[v].push_back(u);
    }    
    for(int i=2 ; i<=n ; i++)
    {
        dis[i] = 1e9;
        dp[i] = -1;
    }
    dp[1] = 1;
    dijk.push({1, 0});
    while(!dijk.empty())
    {
        int nown = dijk.top().node;
        dijk.pop();
        if(reached[nown]) continue;
        reached[nown] = true;
        for(int x : g[nown]) if(dis[x] > dis[nown] + 1)
        {
            dis[x] = dis[nown] + 1;
            dijk.push({x, dis[x]});
        }
    }
    printf((reached[n]) ? "%lld\n" : "0\n",opt(n));
    return 0;
}
