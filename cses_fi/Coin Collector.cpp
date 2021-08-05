#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int cnt_id, cnt_scc;
int id[N], low[N], scc[N], deg[N];
bool OnStack[N], root[N];
long long c[N], c_scc[N], dp[N];
vector<int> g[N], g_scc[N];
vector<pair<int, int>> edge;
stack<int> stk;
queue<int> topo;
map<pair<int, int>, int> mp;

void dfs(int u)
{
    id[u] = low[u] = ++cnt_id;
    stk.push(u), OnStack[u] = true;
    for(int v : g[u])
    {
        if(!id[v]) dfs(v), low[u] = min(low[u], low[v]);
        else if(OnStack[v]) low[u] = min(low[u], id[v]);
    }
    if(id[u] == low[u])
    {
        cnt_scc++;
        root[cnt_scc] = true;
        while(true)
        {
            int now = stk.top();
            stk.pop(), OnStack[now] = false;
            scc[now] = cnt_scc;
            c_scc[cnt_scc] += c[now];
            if(now == u) break;
        }
    }
}

int main()
{
    int n, m;
    scanf(" %d %d",&n,&m);
    for(int i=1 ; i<=n ; i++) scanf(" %lld",&c[i]);
    while(m--)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        g[u].push_back(v);
        edge.push_back({u, v});
    }
    for(int i=1 ; i<=n ; i++) if(!id[i]) dfs(i);
    for(auto x : edge)
    {
        int u = scc[x.first], v = scc[x.second];
        if(u == v || mp.count({u, v})) continue;
        mp[{u, v}] = 1;
        g_scc[u].push_back(v);
        deg[v]++;
        root[v] = false;
    }
    for(int i=1 ; i<=cnt_scc ; i++) if(root[i]) topo.push(i);
    while(!topo.empty())
    {
        int u = topo.front();
        topo.pop();
        dp[u] += c_scc[u];
        for(int v : g_scc[u])
        {
            deg[v]--;
            dp[v] = max(dp[v], dp[u]);
            if(!deg[v]) topo.push(v);
        }
    }
    long long ans = 0;
    for(int i=1 ; i<=cnt_scc ; i++) ans = max(ans, dp[i]);
    printf("%lld\n",ans);
    return 0;
}
