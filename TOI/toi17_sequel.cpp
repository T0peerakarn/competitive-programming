#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

long long arr[N], qs[320][N];

long long query(int l, int r, int k)
{
    if(k >= 320)
    {
        long long ret = 0;
        for(int i=l ; i<=r ; i+=k) ret += arr[i];
        return ret;
    }
    else
    {
        while(r%k != l%k) r--;
        return qs[k][r] - ((l > k) ? qs[k][l-k] : 0);
    }
}

int main()
{
    int n, q;
    vector<long long> ans;
    scanf(" %d %d",&n,&q);

    for(int i=1 ; i<=n ; i++) scanf(" %lld",&arr[i]);

    for(int i=1 ; i<320 ; i++) for(int j=1 ; j<=n ; j++) qs[i][j] = arr[j] + ((j-i > 0) ? qs[i][j-i] : 0);

    while(q--)
    {
        int l, k, r;
        scanf(" %d %d %d",&l,&k,&r);
        ans.push_back(query(l, r, k));
    }
    
    for(auto x : ans) printf("%lld ",x);
    return 0;
}
