#include <bits/stdc++.h>
using namespace std;

struct event
{
    int p, h, c;
    bool operator < (const event & o) const {return p < o.p;}
};

long long ans;
long long fw[1000005];

void update(int i, int v)
{
    while(i <= 1000000)
    {
        fw[i] += v;
        i += -i&i;
    }
}

long long query(int i)
{
    long long ret = 0;
    while(i)
    {
        ret += fw[i];
        i -= -i&i;
    }
    return ret;
}

int get_l(int t)
{
    int l=1, r=1000000;
    while(l != r)
    {
        int mid = (l+r)>>1;
        (query(mid) <= t) ? r = mid : l = mid+1;
    }
    return l;
}

int get_r(int t)
{
    int l=1, r=1000000;
    while(l != r)
    {
        int mid = (l+r+1)>>1;
        (query(mid) >= t) ? l = mid : r = mid-1;
    }
    return l;
}

long long get_height(int t)
{
    int l = get_l(t), r = get_r(t);
    return (query(l) == t) ? r-l+1 : 0;
}

int main()
{
    int n, t;
    scanf(" %d %d",&n,&t);
    vector<event> v;
    for(int i=1 ; i<=n ; i++)
    {
        int s, h, w, c;
        scanf(" %d %d %d %d",&s,&h,&w,&c);
        v.push_back({s, h, c});
        v.push_back({s+w, h, -c});
    }
    sort(v.begin(), v.end());
    for(int i=0 ; i<2*n ; i++)
    {
        if(i) ans += (v[i].p - v[i-1].p) * get_height(t);
        update(1, v[i].c);
        update(v[i].h+1, -v[i].c);
    }
    printf("%lld\n",ans);
    return 0;
}
