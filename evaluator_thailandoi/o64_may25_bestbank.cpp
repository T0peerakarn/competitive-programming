#include "bestbank.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
static const int N = 1e5+5;
static const ll inf = 5e18;

bool QueryMode;

struct Line
{
    mutable ll m, c, p;
    bool operator < (const Line & o) const {return QueryMode ? p < o.p : m < o.m;}
};

struct LineContainer : multiset<Line>
{
    ll divide(ll a, ll b) {return a/b - ((a^b) < 0 && a%b);}

    bool intersect(iterator x, iterator y)
    {
        if(y == end())
        {
            x->p = inf;
            return false;
        }
        if(x->m == y->m) x->p = (x->c > y->c) ? inf : -inf;
        else x->p = divide(y->c - x->c, x->m - y->m);
        return x->p >= y->p;
    }

    void add(ll m, ll c)
    {
        auto nxt = insert({m, c, 0}), now = nxt++, prv = now;
        while(intersect(now, nxt)) nxt = erase(nxt);
        if(prv != begin() && intersect(--prv, now)) intersect(prv, now = erase(now));
        while((now = prv) != begin() && (--prv)->p >= now->p) intersect(prv, erase(now));
    }

    ll query(ll x)
    {
        if(empty()) return -inf;
        QueryMode = true;
        auto l = *lower_bound({0, 0, x});
        QueryMode = false;
        return l.m * x + l.c;
    }
};

int sub[N], lv[N], pa[N];
ll dis[N][20], dp[N];
bool processed[N];
vector<pair<int, ll>> g[N];
LineContainer cht[N];

int get_sub(int u, int p)
{
    sub[u] = 1;
    for(auto x : g[u]) if(x.first != p && !processed[x.first]) sub[u] += get_sub(x.first, u);
    return sub[u];
}

int get_centroid(int u, int p, int n)
{
    for(auto x : g[u]) if(x.first != p && !processed[x.first] && sub[x.first] > n/2) return get_centroid(x.first, u, n);
    return u;
}

void get_distance(int u, int p, int l)
{
    for(auto x : g[u]) if(x.first != p && !processed[x.first])
    {
        dis[x.first][l] = dis[u][l] + x.second;
        get_distance(x.first, u, l);
    }
}

int build_centroid(int u, int p)
{
    u = get_centroid(u, 0, get_sub(u, 0));
    processed[u] = true;
    get_distance(u, 0, lv[u] = lv[p]+1);
    for(auto x : g[u]) if(!processed[x.first]) pa[build_centroid(x.first, u)] = u;
    return u;
}

void update_bank(int P, int F,ll L)
{
    for(int u=++P ; u ; u=pa[u]) cht[u].add(-F, -L-dis[P][lv[u]]); 
}

ll find_best_bank(int S, int Y)
{
    long long ret = inf;
    for(int u=++S ; u ; u=pa[u]) ret = min(ret, -cht[u].query(Y/100)+dis[S][lv[u]]);
    return ret;
}

void initialize(int N, int K, vector<vector<int>> R, vector<vector<ll>> B)
{
    for(int i=1 ; i<=N ; i++) dp[i] = inf;
    for(int i=0 ; i<N-1 ; i++)
    {
        g[R[i][0]+1].push_back({R[i][1]+1, R[i][2]});
        g[R[i][1]+1].push_back({R[i][0]+1, R[i][2]});
    }
    build_centroid(1, 0);
    for(int i=0 ; i<K ; i++) update_bank(B[i][0], B[i][1], B[i][2]);
}
