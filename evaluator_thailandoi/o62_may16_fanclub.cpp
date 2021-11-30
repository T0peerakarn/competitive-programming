#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

struct SEG
{
    long long ans, mxr, mxl, sumb;
};

int sz;
int pa[N], id[N];
long long A[N], B[N];
bool OnPath[N];
SEG seg[N*4];

vector<pair<int, long long>> g[N];

void dfs1(int u, int p)
{
    pa[u] = p;
    for(auto x : g[u])
    {
        if(x.first == p) continue;
        dfs1(x.first, u);
    }
}

long long get_longest(int u, int p)
{
    long long mx = 0;
    for(auto x : g[u])
    {
        if(x.first == p) continue;
        mx = max(mx, get_longest(x.first, u) + x.second);
    }
    return mx;
}

void dfs2(int u, int p)
{
    for(auto x : g[u])
    {
        if(x.first == p) continue;
        if(OnPath[x.first])
        {
            dfs2(x.first, u);
            B[id[u]] = x.second;
        }
        else A[id[u]] = max(A[id[u]], get_longest(x.first, u) + x.second);
    }
}

SEG merge(SEG a, SEG b)
{
    long long ANS = max(max(a.ans, b.ans), a.mxr + b.mxl);
    long long MXR = max(b.mxr, a.mxr + b.sumb);
    long long MXL = max(a.mxl, a.sumb + b.mxl);
    long long SUMB = a.sumb + b.sumb;
    return {ANS, MXR, MXL, SUMB};
}

void build(int l, int r, int idx)
{
    if(l == r) return void(seg[idx] = {0, A[l]+B[l], A[l], B[l]});
    int mid = (l+r)>>1;
    build(l, mid, idx<<1), build(mid+1, r, idx<<1|1);
    seg[idx] = merge(seg[idx<<1], seg[idx<<1|1]);
}

SEG query(int l, int r, int idx, int a, int b)
{
    if(r < a || b < l) return {-1000000000, -1000000000, -1000000000, 0};
    if(a <= l && r <= b) return seg[idx];
    int mid = (l+r)>>1;
    SEG L = query(l, mid, idx<<1, a, b), R = query(mid+1, r, idx<<1|1, a, b);
    return merge(L, R);
}

long long solve(int u, int v)
{
    if(id[u] > id[v]) swap(u, v);
    return query(1, sz, 1, id[u], id[v]).ans;
}

int main()
{
    int n, q, a, b;

    scanf(" %d %d %d %d",&n,&q,&a,&b);
    for(int i=1 ; i<n ; i++)
    {
        int u, v;
        long long w;
        scanf(" %d %d %lld",&u,&v,&w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dfs1(a, 0);

    stack<int> rev;
    for(int i=b ; i!=a ; i=pa[i]) rev.push(i);
    rev.push(a);

    for( ; !rev.empty() ; rev.pop())
    {
        id[rev.top()] = ++sz;
        OnPath[rev.top()] = true;
    }        

    dfs2(a, 0);

    build(1, sz, 1);

    while(q--)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        printf("%lld\n",solve(u, v));
    }
    return 0;
}
