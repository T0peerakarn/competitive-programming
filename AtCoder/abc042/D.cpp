#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long fac[200005];

long long mop(long long a, long long b)
{
    if(b == 1) return a;
    long long ret = (b%2) ? a : 1, t = mop(a, b/2);
    ret *= t;
    ret %= mod;
    ret *= t;
    ret %= mod;
    return ret;
}

long long compute(int a, int b)
{
    long long ret = fac[a+b];
    ret *= mop(fac[a], mod-2);
    ret %= mod;
    ret *= mop(fac[b], mod-2);
    ret %= mod;
    return ret;
}

int main()
{
    fac[0] = 1;
    for(int i=1 ; i<=200000 ; i++)
    {
        fac[i] = fac[i-1]*i;
        fac[i] %= mod;
    }
    long long h, w, a, b, ans = 0;
    scanf(" %lld %lld %lld %lld",&h,&w,&a,&b);
    for(int i=b+1 ; i<=w ; i++)
    {
        ans += compute(h-a-1, i-1) * compute(a-1, w-i);
        ans %= mod;
    }
    printf("%lld\n",ans);
    return 0;
}
