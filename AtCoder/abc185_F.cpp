#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;

int seg[N*4];

void build(int l, int r, int idx)
{
    if(l == r) return void(scanf(" %d",&seg[idx]));
    int mid = (l+r)>>1;
    build(l, mid, idx<<1), build(mid+1, r, idx<<1|1);
    seg[idx] = seg[idx<<1] ^ seg[idx<<1|1];
}

void update(int l, int r, int idx, int p, int v)
{
    if(l == r) return void(seg[idx] ^= v);
    int mid = (l+r)>>1;
    (p <= mid) ? update(l, mid, idx<<1, p, v) : update(mid+1, r, idx<<1|1, p, v);
    seg[idx] = seg[idx<<1] ^ seg[idx<<1|1];
}

int query(int l, int r, int idx, int a, int b)
{
    if(r < a || b < l) return 0;
    if(a <= l && r <= b) return seg[idx];
    int mid = (l+r)>>1;
    return query(l, mid, idx<<1, a, b) ^ query(mid+1, r, idx<<1|1, a, b);
}

int main()
{
    int n, q;
    scanf(" %d %d",&n,&q);
    build(1, n, 1);
    while(q--)
    {
        int t, a, b;
        scanf(" %d %d %d",&t,&a,&b);
        if(t == 1) update(1, n, 1, a, b);
        else printf("%d\n",query(1, n, 1, a, b));
    }    
    return 0;
}
