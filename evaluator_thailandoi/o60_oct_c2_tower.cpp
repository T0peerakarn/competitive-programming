#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

struct SEG{
    int mx, frq, l, r;
};

int laz[N*4];
SEG seg[N*4];

void build(int l, int r, int idx)
{
    if(l == r)
    {
        seg[idx] = {0, 1, l, r};
        return ;
    }
    int mid = (l+r)>>1;
    build(l, mid, idx<<1), build(mid+1, r, idx<<1|1);
    if(seg[idx<<1].mx == seg[idx<<1|1].mx)
    {
        seg[idx].mx = seg[idx<<1].mx;
        seg[idx].frq = seg[idx<<1].frq + seg[idx<<1|1].frq - (seg[idx<<1].r + 1 == seg[idx<<1|1].l);
        seg[idx].l = seg[idx<<1].l;
        seg[idx].r = seg[idx<<1|1].r;
    }
    else seg[idx] = (seg[idx<<1].mx > seg[idx<<1|1].mx) ? seg[idx<<1] : seg[idx<<1|1];
}

void push_lazy(int l, int r, int idx)
{
    seg[idx].mx += laz[idx];
    if(l != r)
    {
        laz[idx<<1] += laz[idx];
        laz[idx<<1|1] += laz[idx];
    }
    laz[idx] = 0;
}

void update(int l, int r, int idx, int a, int b, int x)
{
    push_lazy(l, r, idx);
    if(r < a || b < l) return ;
    if(a <= l && r <= b)
    {
        laz[idx] += x;
        push_lazy(l, r, idx);
        return ;
    }
    int mid = (l+r)>>1;
    update(l, mid, idx<<1, a, b, x), update(mid+1, r, idx<<1|1, a, b, x);
    if(seg[idx<<1].mx == seg[idx<<1|1].mx)
    {
        seg[idx].mx = seg[idx<<1].mx;
        seg[idx].frq = seg[idx<<1].frq + seg[idx<<1|1].frq - (seg[idx<<1].r + 1 == seg[idx<<1|1].l);
        seg[idx].l = seg[idx<<1].l;
        seg[idx].r = seg[idx<<1|1].r;
    }
    else seg[idx] = (seg[idx<<1].mx > seg[idx<<1|1].mx) ? seg[idx<<1] : seg[idx<<1|1];
}

int main()
{
    int n, q;
    scanf(" %d %d",&n,&q);
    build(1, n, 1);
    while(q--)
    {
        int a, b, x;
        scanf(" %d %d %d",&a,&b,&x);
        update(1, n, 1, a, b, x);
        printf("%d %d\n",seg[1].mx,seg[1].frq);
    }
}
