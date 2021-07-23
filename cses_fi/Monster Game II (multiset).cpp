#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
static const ll inf = LLONG_MAX;

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
        if(empty()) return inf;
        QueryMode = true;
        auto l = *lower_bound({0, 0, x});
        QueryMode = false;
        return l.m * x + l.c;
    }
};
 
int main()
{
    int n;
    long long x;
    scanf(" %d %lld",&n,&x);
    
    vector<long long> s(n), f(n), dp(n);
    for(int i=0 ; i<n ; i++) scanf(" %lld",&s[i]);
    for(int i=0 ; i<n ; i++) scanf(" %lld",&f[i]);
 
    LineContainer cht;
    cht.add(-x, 0);
    for(int i=0 ; i<n ; i++)
    {
        dp[i] = -cht.query(s[i]);
        cht.add(-f[i], -dp[i]);
    }
    printf("%lld\n",dp[n-1]);
    return 0;
}
