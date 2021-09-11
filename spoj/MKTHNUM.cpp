#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

vector<int> arr, seg[N*4];

void build(int l, int r, int idx)
{
    seg[idx].push_back(-2e9);
    if(l == r)
    {
        int d;
        scanf(" %d",&d);
        arr.push_back(d);
        seg[idx].push_back(d);
        return ;
    }
    int mid = (l+r)>>1;
    build(l, mid, idx<<1), build(mid+1, r, idx<<1|1);
    int i=0, j=0, sl=seg[idx<<1].size(), sr=seg[idx<<1|1].size();
    while(seg[idx<<1][i] == -2e9) i++;
    while(seg[idx<<1|1][j] == -2e9) j++;
    while(i<sl && j<sr)
    {
        if(seg[idx<<1][i] < seg[idx<<1|1][j]) seg[idx].push_back(seg[idx<<1][i++]);
        else seg[idx].push_back(seg[idx<<1|1][j++]);
    }
    while(i < sl) seg[idx].push_back(seg[idx<<1][i++]);
    while(j < sr) seg[idx].push_back(seg[idx<<1|1][j++]);
}

int query(int l, int r, int idx, int a, int b, int v)
{
    if(r < a || b < l) return 0;
    if(a <= l && r <= b)
    {
        int ll=0, rr=seg[idx].size()-1;
        while(ll != rr)
        {
            int mm = (ll+rr+1)>>1;
            (seg[idx][mm] <= v) ? ll = mm : rr = mm-1;
        }
        return ll;
    }
    int mid = (l+r)>>1;
    return query(l, mid, idx<<1, a, b, v) + query(mid+1, r, idx<<1|1, a, b, v);
}

int main()
{
    int n, q;
    scanf(" %d %d",&n,&q);
    build(1, n, 1);
    sort(arr.begin(), arr.end());
    while(q--)
    {
        int a, b, k;
        scanf(" %d %d %d",&a,&b,&k);
        int l=0, r=n-1;
        while(l != r)
        {
            int mid = (l+r)>>1;
            (query(1, n, 1, a, b, arr[mid]) >= k) ? r = mid : l = mid+1;
        }
        printf("%d\n",arr[l]);
    }
    return 0;
}MKTHNUM
