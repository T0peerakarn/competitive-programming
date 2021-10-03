#include <bits/stdc++.h>
using namespace std;

const int N = 2e6+5;

struct Rectangle{
    int x, y1, y2, v;
    bool operator < (const Rectangle & o) const
    {
        return x < o.x;
    }
};

long long seg[N*4], laz[N*4];
vector<Rectangle> event;

void update(int l, int r, int idx, int a, int b, int v)
{
    if(r < a || b < l) return ;
    if(a <= l && r <= b)
    {
        laz[idx] += v;
        seg[idx] = (laz[idx]) ? r-l+1 : (l == r) ? 0 : seg[idx<<1] + seg[idx<<1|1];
        return ;
    }
    int mid = (l+r)>>1;
    update(l, mid, idx<<1, a, b, v), update(mid+1, r, idx<<1|1, a, b, v);
    seg[idx] = (laz[idx]) ? r-l+1 : (l == r) ? 0 : seg[idx<<1] + seg[idx<<1|1];
}

int main()
{
    int n;
    long long ans = 0;
    scanf(" %d",&n);
    for(int i=1 ; i<=n ; i++)
    {
        int x1, y1, x2, y2;
        scanf(" %d %d %d %d",&x1,&y1,&x2,&y2);
        event.push_back({x1, y1+1000000+1, y2+1000000, 1});
        event.push_back({x2, y1+1000000+1, y2+1000000, -1});
    }
    sort(event.begin(), event.end());
    for(int i=0 ; i<n+n ; i++)
    {
        if(i) ans += (event[i].x - event[i-1].x) * seg[1];
        update(1, 2000000, 1, event[i].y1, event[i].y2, event[i].v);
    }
    printf("%lld\n",ans);
    return 0;
}
