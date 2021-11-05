#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, k;
    scanf(" %lld %lld %lld",&n,&m,&k);
    long long l=1, r=1e18;
    while(l != r)
    {
        long long mid = (l+r)>>1, cnt = 0;
        for(long long i=1 ; i<=n ; i++) cnt += (mid >= i*m) ? m : mid/i;
        (cnt >= k) ? r = mid : l = mid+1;
    }
    printf("%lld\n",l);
    return 0;
}
