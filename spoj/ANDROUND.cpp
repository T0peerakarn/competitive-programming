#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, k;
int arr[N], seg[N*4];

void build(int l, int r, int idx)
{
    if(l == r) return void(seg[idx] = arr[l]);
    int mid = (l+r)>>1;
    build(l, mid, idx<<1), build(mid+1, r, idx<<1|1);
    seg[idx] = seg[idx<<1] & seg[idx<<1|1];
}

int query(int l, int r, int idx, int a, int b)
{
    if(r < a || b < l) return INT_MAX;
    if(a <= l && r <= b) return seg[idx];
    int mid = (l+r)>>1;
    return query(l, mid, idx<<1, a, b) & query(mid+1, r, idx<<1|1, a, b);
}

void solve()
{
    scanf(" %d %d",&n,&k);
    for(int i=1 ; i<=n ; i++)
    {
        scanf(" %d",&arr[i]);
        arr[n+i] = arr[n+n+i] = arr[i];
    }
    build(1, n+n+n, 1);
    k = min(k, n);
    for(int i=n+1 ; i<=n+n ; i++) printf("%d ",query(1, n+n+n, 1, i-k, i+k));
    printf("\n");
}

int main()
{
    int t;
    scanf(" %d",&t);
    while(t--) solve();
    return 0;
}
