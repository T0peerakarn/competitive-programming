#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main()
{
    int n;
    long long ans = 1;
    scanf(" %d",&n);
    vector<long long> v(n);
    for(auto &x : v) scanf(" %lld",&x);
    sort(v.begin(), v.end());
    for(int i=0 ; i<n ; i++)
    {
        v[i] -= i;
        v[i] = max(v[i], 0ll);
        ans *= v[i];
        ans %= mod;
    }
    printf("%lld\n",ans);
    return 0;
}
