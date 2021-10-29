#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

int n, cnt_id, cnt_node, chain, ptr;
int id[N], low[N], sz[N], lv[N], jmp[20][N], root[N], group[N], pos[N], rpos[N];
long long w[N], seg[N*4];
bool ap[N];
vector<int> g[N], gt[N];
vector<vector<int>> comps;
stack<int> stk;
multiset<int> st[N];

void dfs_ap(int u, int p)
{
    id[u] = low[u] = ++cnt_id;
    stk.push(u);
    for(int v : g[u])
    {
        if(v == p) continue;
        if(!id[v])
        {
            dfs_ap(v, u);
            low[u] = min(low[u], low[v]);
            if(id[u] <= low[v])
            {
                ap[u] = (id[u] > 1 || id[v] > 2);
                comps.push_back({u});
                while(comps.back().back() != v)
                {
                    comps.back().push_back(stk.top());
                    stk.pop();
                }
            }
        }
        else low[u] = min(low[u], id[v]);
    }
}

void build_tree()
{
    dfs_ap(1, 0);
    for(int i=1 ; i<=n ; i++) if(ap[i]) id[i] = ++cnt_node;
    for(vector<int> comp : comps)
    {
        int node = ++cnt_node;
        for(int u : comp)
        {
            if(ap[u])
            {
                gt[node].push_back(id[u]);
                gt[id[u]].push_back(node);
            }
            else id[u] = cnt_node;
        }
    }
}

void build_weight()
{
    for(int i=1 ; i<=n ; i++)
    {
        st[id[i]].insert(w[i]);
        if(ap[i]) for(int v : gt[id[i]]) st[v].insert(w[i]);
    }
}

void dfs_tree(int u, int l)
{
    sz[u] = 1, lv[u] = l;
    for(int v : gt[u])
    {
        if(lv[v]) continue;
        dfs_tree(v, l+1);
        sz[u] += sz[v];
        jmp[0][v] = u;
    }
}

void hld(int u, int p)
{
    if(!root[chain]) root[chain] = u;
    group[u] = chain;
    pos[u] = ptr;
    rpos[ptr] = u;
    ptr--;
    int vv = 0;
    for(int v : gt[u])
    {
        if(v == p) continue;
        if(sz[v] > sz[vv]) vv = v;
    }
    if(vv) hld(vv, u);
    for(int v : gt[u])
    {
        if(v == p || v == vv) continue;
        chain++;
        hld(v, u);
    }
}

void build_seg(int l, int r, int idx)
{
    if(l == r) return void(seg[idx] = *st[rpos[l]].begin());
    int mid = (l+r)>>1;
    build_seg(l, mid, idx<<1), build_seg(mid+1, r, idx<<1|1);
    seg[idx] = min(seg[idx<<1], seg[idx<<1|1]);
}

void build_hld()
{
    chain = 1, ptr = cnt_node;
    dfs_tree(1, 1);
    hld(1, 0);
    build_seg(1, cnt_node, 1);
    for(int i=1 ; i<20 ; i++) for(int j=1 ; j<=cnt_node ; j++) jmp[i][j] = jmp[i-1][jmp[i-1][j]];
}

void update_seg(int l, int r, int idx, int p)
{
    if(l == r) return void(seg[idx] = *st[rpos[l]].begin());
    int mid = (l+r)>>1;
    (p <= mid) ? update_seg(l, mid, idx<<1, p) : update_seg(mid+1, r, idx<<1|1, p);
    seg[idx] = min(seg[idx<<1], seg[idx<<1|1]);
}

int lca(int u, int v)
{
    if(lv[u] < lv[v]) swap(u, v);
    for(int i=19 ; i>=0 ; i--) if(lv[jmp[i][u]] >= lv[v]) u = jmp[i][u];
    if(u == v) return u;
    for(int i=19 ; i>=0 ; i--) if(jmp[i][u] != jmp[i][v]) u = jmp[i][u], v = jmp[i][v];
    return jmp[0][u];
}

long long query_seg(int l, int r, int idx, int a, int b)
{
    if(r < a || b < l) return 1e18;
    if(a <= l && r <= b) return seg[idx];
    int mid = (l+r)>>1;
    return min(query_seg(l, mid, idx<<1, a, b), query_seg(mid+1, r, idx<<1|1, a, b));
}

void update_weight(int u, long long x)
{
    st[id[u]].erase(st[id[u]].lower_bound(w[u]));
    st[id[u]].insert(x);
    update_seg(1, cnt_node, 1, pos[id[u]]);
    if(ap[u])
    {
        for(int v : gt[id[u]])
        {
            st[v].erase(st[v].lower_bound(w[u]));
            st[v].insert(x);
            update_seg(1, cnt_node, 1, pos[v]);
        }
    }
    w[u] = x;
}

long long solve(int u, int v)
{
    if(u == v) return w[u];
    u = id[u], v = id[v];
    long long ret = 1e18;
    int LCA = lca(u, v);
    while(true)
    {
        if(group[u] == group[LCA])
        {
            ret = min(ret, query_seg(1, cnt_node, 1, pos[u], pos[LCA]));
            break;
        }
        else
        {
            ret = min(ret, query_seg(1, cnt_node, 1, pos[u], pos[root[group[u]]]));
            u = jmp[0][root[group[u]]];
        }
    }
    while(true)
    {
        if(group[v] == group[LCA])
        {
            ret = min(ret, query_seg(1, cnt_node, 1, pos[v], pos[LCA]));
            break;
        }
        else
        {
            ret = min(ret, query_seg(1, cnt_node, 1, pos[v], pos[root[group[v]]]));
            v = jmp[0][root[group[v]]];
        }
    }
    return ret;
}

int main()
{
    int m, q;
    scanf(" %d %d %d",&n,&m,&q);
    for(int i=1 ; i<=n ; i++) scanf(" %lld",&w[i]);
    while(m--)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    build_tree();
    build_weight();
    build_hld();
    while(q--)
    {
        int op;
        scanf(" %d",&op);
        if(op == 1)
        {
            int u;
            long long x;
            scanf(" %d %lld",&u,&x);
            update_weight(u, x);
        }
        else
        {
            int u, v;
            scanf(" %d %d",&u,&v);
            printf("%lld\n",solve(u, v));
        }
    }
    return 0;
}
