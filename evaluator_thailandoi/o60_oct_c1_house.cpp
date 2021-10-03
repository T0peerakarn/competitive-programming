#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int inf = 1000000000;

struct SEG{
    long long ans, best_l, best_r, sum;
};

SEG seg[N*4];

void build(int l, int r, int idx)
{
    if(l == r)
    {
        long long d;
        scanf(" %lld",&d);
        seg[idx] = {max(0ll, d), max(0ll, d), max(0ll, d), d};
        return ;
    }
    int mid = (l+r)>>1;
    build(l, mid, idx<<1), build(mid+1, r, idx<<1|1);
    long long ANS = max(max(seg[idx<<1].ans, seg[idx<<1|1].ans), seg[idx<<1].best_r + seg[idx<<1|1].best_l);
    long long BEST_L = max(seg[idx<<1].best_l, seg[idx<<1].sum + seg[idx<<1|1].best_l);
    long long BEST_R = max(seg[idx<<1|1].best_r, seg[idx<<1|1].sum + seg[idx<<1].best_r);
    long long SUM = seg[idx<<1].sum + seg[idx<<1|1].sum;
    seg[idx] = {ANS, BEST_L, BEST_R, SUM};
}

SEG query(int l, int r, int idx, int a, int b)
{
    if(r < a || b < l) return {-inf, -inf, -inf, 0};
    if(a <= l && r <= b) return seg[idx];
    int mid = (l+r)>>1;
    SEG L = query(l, mid, idx<<1, a, b), R = query(mid+1, r, idx<<1|1, a, b);
    if(L.ans == -1e9) return R;
    if(R.ans == -1e9) return L;
    long long ANS = max(max(L.ans, R.ans), L.best_r + R.best_l);
    long long BEST_L = max(L.best_l, L.sum + R.best_l);
    long long BEST_R = max(R.best_r, R.sum + L.best_r);
    long long SUM = L.sum + R.sum;
    return {ANS, BEST_L, BEST_R, SUM};
}

int main()
{
    int n, q;
    scanf(" %d %d",&n,&q);
    build(1, n, 1);
    while(q--)
    {
        int l, r;
        scanf(" %d %d",&l,&r);
        l++, r++;
        printf("%lld\n",query(1, n, 1, l, r).ans);
    }
}
