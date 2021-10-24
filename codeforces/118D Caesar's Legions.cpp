#include <bits/stdc++.h>
using namespace std;

#define mod 100000000

int N1, N2, K1, K2;
long long dp[105][105][15][15];

long long opt(int n1, int n2, int k1, int k2)
{
    if(n1 < 0 || n2 < 0 || k1 < 0 || k2 < 0) return 0;
    if(dp[n1][n2][k1][k2] != -1) return dp[n1][n2][k1][k2];
    if(n1 == 0) return dp[n1][n2][k1][k2] = (n2 <= k2) ? 1 : 0;
    if(n2 == 0) return dp[n1][n2][k1][k2] = (n1 <= k1) ? 1 : 0;
    long long ret = 0;
    ret += opt(n1-1, n2, k1-1, K2);
    ret %= mod;
    ret += opt(n1, n2-1, K1, k2-1);
    ret %= mod;
    return dp[n1][n2][k1][k2] = ret;
}

int main()
{
    scanf(" %d %d %d %d",&N1,&N2,&K1,&K2);
    memset(dp, -1, sizeof dp);
    printf("%lld\n",opt(N1, N2, K1, K2));
    return 0;
}
