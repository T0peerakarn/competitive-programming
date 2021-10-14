#include <bits/stdc++.h>
using namespace std;

const int N = 3e4+5;

struct SEG{
    int close, open;
};

SEG seg[N*4];

void build(int l, int r, int idx)
{
    if(l == r)
    {
        char c;
        scanf(" %c",&c);
        seg[idx] = {c == ')', c == '('};
        return ;
    }
    int mid = (l+r)>>1;
    build(l, mid, idx<<1), build(mid+1, r, idx<<1|1);
    int Pair = min(seg[idx<<1].open, seg[idx<<1|1].close);
    int Close = seg[idx<<1].close + seg[idx<<1|1].close - Pair;
    int Open = seg[idx<<1].open + seg[idx<<1|1].open - Pair;
    seg[idx] = {Close, Open};
}

void update(int l, int r, int idx, int p)
{
    if(!(l <= p && p <= r)) return ;
    if(l == r) return void(swap(seg[idx].close, seg[idx].open));
    int mid = (l+r)>>1;
    update(l, mid, idx<<1, p), update(mid+1, r, idx<<1|1, p);
    int Pair = min(seg[idx<<1].open, seg[idx<<1|1].close);
    int Close = seg[idx<<1].close + seg[idx<<1|1].close - Pair;
    int Open = seg[idx<<1].open + seg[idx<<1|1].open - Pair;
    seg[idx] = {Close, Open};
}

void solve()
{
    int n;
    scanf(" %d",&n);
    build(1, n, 1);
    int q;
    scanf(" %d",&q);
    while(q--)
    {
        int d;
        scanf(" %d",&d);
        if(d == 0) printf((!seg[1].close && !seg[1].open) ? "YES\n" : "NO\n");
        else update(1, n, 1, d);
    }
}

int main()
{
    for(int i=1 ; i<=10 ; i++)
    {
        printf("Test %d:\n",i);
        solve();
    }
}
