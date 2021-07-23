#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast")

const int N = 1e5+5;

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int cnt;
int sub[N], dis[N][20], pa[N], lv[N];
bool processed[N];
vector<int> g[N];
ordered_set<pair<int, int>> t1[N], t2[N];

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

void get_distance(int u, int p, int l)
{
    for(int v : g[u]) if(v != p && !processed[v])
    {
        dis[v][l] = dis[u][l] + 1;
        get_distance(v, u, l);
    }
}

int build_centroid(int u, int p)
{
    u = get_centroid(u, 0, get_sub(u, 0));
    processed[u] = true;
    get_distance(u, 0, lv[u] = lv[p]+1);
    for(int v : g[u]) if(!processed[v]) pa[build_centroid(v, u)] = u;
    return u;
}

void update(int u, int k)
{
    t1[u].insert({k, ++cnt});
    for(int now=pa[u], prv=u ; now ; now=pa[now], prv=pa[prv]) if(k >= dis[u][lv[now]])
    {
        t1[now].insert({k-dis[u][lv[now]], ++cnt});
        t2[prv].insert({k-dis[u][lv[now]], ++cnt});
    }
}

int query(int u)
{
    int ret = t1[u].size();
    for(int now=pa[u], prv=u ; now ; now=pa[now], prv=pa[prv])
    {
        ret += t1[now].size() - t1[now].order_of_key({dis[u][lv[now]], 0});
        ret -= t2[prv].size() - t2[prv].order_of_key({dis[u][lv[now]], 0});
    }
    return ret;
}

int main()
{
    int n, q;
    scanf(" %d %d",&n,&q);
    for(int i=1 ; i<n ; i++)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    build_centroid(1, 0);
    while(q--)
    {
        int op;
        scanf(" %d",&op);
        if(op == 1)
        {
            int u, k;
            scanf(" %d %d",&u,&k);
            update(u, k);
        }
        else
        {
            int u;
            scanf(" %d",&u);
            printf("%d\n",query(u));
        }
    }
    return 0;
}
