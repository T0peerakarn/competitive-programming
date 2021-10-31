#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
#define mod 1000000000

struct EDGE
{
    int u, v;
    long long w;
    bool operator < (const EDGE & o) const
    {
        return w > o.w;
    }
};

int pa[N];
long long sz[N];
vector<EDGE> edge;

int fp(int u) { return (u == pa[u]) ? u : pa[u] = fp(pa[u]); }

int main()
{
    int n, m;
    long long ans = 0;
    long long cpair = 0;
    scanf(" %d %d",&n,&m);
    for(int i=1 ; i<=n ; i++)
    {
        sz[i] = 1;
        pa[i] = i;
    }
    while(m--)
    {
        int u, v;
        long long w;
        scanf(" %d %d %lld",&u,&v,&w);
        edge.push_back({u, v, w});
    }
    sort(edge.begin(), edge.end());
    for(EDGE x : edge)
    {
        int u = fp(x.u), v = fp(x.v);
        long long w = x.w;
        if(u != v)
        {
            cpair += sz[u] * sz[v];
            cpair %= mod;
            pa[u] = v;
            sz[v] += sz[u];
            sz[v] %= mod;
        }
        ans += w * cpair;
        ans %= mod;
    }
    printf("%lld\n",ans);
    return 0;
}
