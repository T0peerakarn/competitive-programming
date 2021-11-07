#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long mop(long long a, long long b)
{
    if(b == 1) return a;
    long long ret = (b%2) ? a : 1, t = mop(a, b>>1);
    ret *= t;
    ret %= mod;
    ret *= t;
    ret %= mod;
    return ret;
}

int main()
{
    long long n, m;
    scanf(" %lld %lld",&n,&m);
    printf("%lld\n",mop((mop(2, m)-1+mod)%mod, n));
    return 0;
}
