#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
#define mod 1000000007

int cnt_id, cnt_scc;
int id[N], low[N], scc[N], sz[N], col[N], dp[N], lv[N], jmp[20][N];
long long ans[N];
vector<int> g[N], gt[N];
vector<pair<int, int>> edge;
stack<int> stk;
set<int> st[N];

void dfs_scc(int u, int p)
{
    id[u] = low[u] = ++cnt_id;
    stk.push(u);
    for(int v : g[u])
    {
        if(v == p) continue;
        if(!id[v])
        {
            dfs_scc(v, u);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], id[v]);
    }
    if(id[u] == low[u])
    {
        cnt_scc++;
        while(true)
        {
            int now = stk.top();
            stk.pop();
            scc[now] = cnt_scc;
            sz[cnt_scc]++;
            if(now == u) break;
        }
    }
}

void dfs_tree(int u, int l, int sum)
{
    col[u] = (sz[u] > 1) ? 1 : 0;
    dp[u] = col[u] + sum;
    lv[u] = l;
    for(int v : gt[u])
    {
        if(lv[v]) continue;
        dfs_tree(v, l+1, dp[u]);
        jmp[0][v] = u;
    }
}

int lca(int u, int v)
{
    if(lv[u] < lv[v]) swap(u, v);
    for(int i=19 ; i>=0 ; i--) if(lv[jmp[i][u]] >= lv[v]) u = jmp[i][u];
    if(u == v) return u;
    for(int i=19 ; i>=0 ; i--) if(jmp[i][u] != jmp[i][v]) u = jmp[i][u], v = jmp[i][v];
    return jmp[0][u];
}

int main()
{
    ans[0] = 1;
    for(int i=1 ; i<=100000 ; i++)
    {
        ans[i] = ans[i-1]*2;
        ans[i] %= mod;
    }
    int n, m;
    scanf(" %d %d",&n,&m);
    while(m--)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        edge.push_back({u, v});
    }
    dfs_scc(1, 0);
    for(auto x : edge)
    {
        int u = scc[x.first], v = scc[x.second];
        if(u == v || st[u].count(v)) continue;
        st[u].insert(v);
        st[v].insert(u);
        gt[u].push_back(v);
        gt[v].push_back(u);
    }
    dfs_tree(1, 1, 0);
    for(int i=1 ; i<20 ; i++) for(int j=1 ; j<=cnt_scc ; j++) jmp[i][j] = jmp[i-1][jmp[i-1][j]];
    int q;
    scanf(" %d",&q);
    while(q--)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        u = scc[u], v = scc[v];
        int LCA = lca(u, v);
        printf("%lld\n",ans[dp[u] + dp[v] - 2*dp[LCA] + col[LCA]]);
    }
    return 0;
}
