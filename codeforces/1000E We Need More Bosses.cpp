#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;

int cnt_id, cnt_scc, ans;
int id[N], low[N], scc[N], mx1[N], mx2[N];
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
        int now;
        do
        {
            now = stk.top();
            stk.pop();
            scc[now] = cnt_scc;
        } while (now != u);   
    }
}

void dfs_tree_1(int u, int p)
{
    for(int v : gt[u])
    {
        if(v == p) continue;
        dfs_tree_1(v, u);
        if(mx1[v] + 1 >= mx1[u])
        {
            mx2[u] = mx1[u];
            mx1[u] = mx1[v] + 1;
        }
        else if(mx1[v] + 1 >= mx2[u])
        {
            mx2[u] = mx1[v] + 1;
        }
    }
}

void dfs_tree_2(int u, int p, int w)
{
    ans = max(ans, mx1[u] + w);
    int children = gt[u].size() - (u != 1);
    for(int v : gt[u])
    {
        if(v == p) continue;
        if(children == 1) dfs_tree_2(v, u, w+1);
        else (mx1[v] + 1 == mx1[u]) ? dfs_tree_2(v, u, max(mx2[u], w)+1) : dfs_tree_2(v, u, max(mx1[u], w)+1);
    }
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
        edge.push_back({u, v});
    }
    dfs_scc(1, 0);
    for(pair<int, int> x : edge)
    {
        int u = scc[x.first], v = scc[x.second];
        if(u == v || st[u].count(v)) continue;
        st[u].insert(v);
        st[v].insert(u);
        gt[u].push_back(v);
        gt[v].push_back(u);
    }
    dfs_tree_1(1, 0);
    dfs_tree_2(1, 0, 0);
    printf("%d\n",ans);
    return 0;
}
