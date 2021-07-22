#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int k;
int sub[N];
bool processed[N];
long long ans;
long long cnt[N];
vector<int> g[N];

int get_sub(int u, int p)
{
    sub[u] = 1;
    for(int v : g[u]) if(v != p && !processed[v]) sub[u] += get_sub(v, u);
    return sub[u];
}

int get_centroid(int u, int p, int n)
{
    for(int v : g[u]) if(v != p && !processed[v] && sub[v] > n/2) return get_centroid(v, u, n);
    return u;
}

void solve(int u, int p, bool update, int lv)
{
    if(lv > k) return ;
    if(update) cnt[lv]++;
    else ans += cnt[k-lv];
    for(int v : g[u]) if(v != p && !processed[v]) solve(v, u, update, lv+1);
}

void build_centroid(int u)
{
    u = get_centroid(u, 0, get_sub(u, 0));
    processed[u] = true;
    cnt[0] = 1;
    for(int v : g[u]) if(!processed[v])
    {
        solve(v, u, false, 1);
        solve(v, u, true, 1);
    }
    for(int i=0 ; cnt[i] ; i++) cnt[i] = 0;
    for(int v : g[u]) if(!processed[v]) build_centroid(v);
}

int main()
{
    int n;
    scanf(" %d %d",&n,&k);
    for(int i=1 ; i<n ; i++)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        g[u].push_back(v), g[v].push_back(u);
    }
    build_centroid(1);
    printf("%lld\n",ans);
    return 0;
}
