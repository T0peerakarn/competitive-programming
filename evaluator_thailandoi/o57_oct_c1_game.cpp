#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+5;

int cnt_id, cnt_scc;
int id[N], low[N], scc[N], rnk[N], ans[N];
bool OnStack[N], root[N], scc_edge[N][N];
stack<int> stk;
vector<int> g[N], g_scc[N];
vector<pair<int, int>> edge;

void dfs(int u)
{
    id[u] = low[u] = ++cnt_id;
    OnStack[u] = true;
    stk.push(u);
    for(int v : g[u])
    {
        if(!id[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(OnStack[v]) low[u] = min(low[u], id[v]);
    }
    if(id[u] == low[u])
    {
        cnt_scc++;
        root[cnt_scc] = true;
        while(true)
        {
            int now = stk.top();
            OnStack[now] = false;
            stk.pop();
            scc[now] = cnt_scc;
            if(now == u) break;
        }
    }
}

void solve(int u, int lv)
{
    rnk[u] = lv;
    for(int v : g_scc[u]) solve(v, max(lv+1, rnk[v]));
}

int main()
{
    int n, m;
    scanf(" %d %d",&n,&m);
    while(m--)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        u++, v++;
        g[u].push_back(v);
        edge.push_back({u, v});
    }
    for(int i=1 ; i<=n ; i++) if(!id[i]) dfs(i);
    for(pair<int, int> x : edge)
    {
        int u = scc[x.first], v = scc[x.second];
        if(u == v || scc_edge[u][v]) continue;
        scc_edge[u][v] = true;
        g_scc[u].push_back(v);
        root[v] = false;
    }
    for(int i=1 ; i<=cnt_scc ; i++) if(root[i]) solve(i, 1);
    for(int i=1 ; i<=n ; i++) ans[rnk[scc[i]]]++;
    for(int i=1 ; ans[i] != 0 ; i++) printf("%d ",ans[i]);
    return 0;
}
