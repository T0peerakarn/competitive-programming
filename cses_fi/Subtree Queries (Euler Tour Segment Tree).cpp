#include <bits/stdc++.h>
using namespace std;
 
#define N 200005
 
int t;
int in[N], out[N];
long long val[N], arr[N*2], seg[N*8];
vector<int> g[N];
 
void dfs(int u, int p)
{
    in[u] = ++t;
    arr[t] = val[u];
    for(auto x : g[u])
        if(x != p) dfs(x, u);
    out[u] = ++t;
    arr[t] = val[u];
}
 
void build(int l, int r, int idx)
{
    if(l == r) return void(seg[idx] = arr[l]);
    int mid = (l+r)>>1;
    build(l, mid, idx<<1), build(mid+1, r, idx<<1|1);
    seg[idx] = seg[idx<<1] + seg[idx<<1|1];
}
 
void update(int l, int r, int idx, int p, long long v)
{
    if(!(l <= p && p <= r)) return ;
    if(l == r) return void(seg[idx] = v);
    int mid = (l+r)>>1;
    update(l, mid, idx<<1, p, v), update(mid+1, r, idx<<1|1, p, v);
    seg[idx] = seg[idx<<1] + seg[idx<<1|1];
}
 
long long query(int l, int r, int idx, int a, int b)
{
    if(r < a || b < l) return 0;
    if(a <= l && r <= b) return seg[idx];
    int mid = (l+r)>>1;
    return query(l, mid, idx<<1, a, b) + query(mid+1, r, idx<<1|1, a, b);
}
 
int main()
{
    int n, q;
    scanf(" %d %d",&n,&q);
    for(int i=1 ; i<=n ; i++)
        scanf(" %lld",&val[i]);
    for(int i=1 ; i<n ; i++)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        g[u].push_back(v), g[v].push_back(u);
    }
    dfs(1, 0);
    build(1, t, 1);
    while(q--)
    {
        int op;
        scanf(" %d",&op);
        if(op == 1)
        {
            int p;
            long long v;
            scanf(" %d %lld",&p,&v);
            update(1, t, 1, in[p], v);
            update(1, t, 1, out[p], v);
        }
        else
        {
            int p;
            scanf(" %d",&p);
            printf("%lld\n",query(1, t, 1, in[p], out[p])>>1);
        }
    }
    return 0;
}
