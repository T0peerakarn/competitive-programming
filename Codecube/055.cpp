#include <bits/stdc++.h>
using namespace std;

#define mod 9871

long long dp[1010][1010];

int main()
{
    dp[0][0] = 1;
    for(int i=1 ; i<=1000 ; i++) for(int j=1 ; j<=i ; j++)
    {
        dp[i][j] = dp[i-1][j-1] + j*dp[i-1][j];
        dp[i][j] %= mod;
    }
    int q;
    scanf(" %d",&q);
    while(q--)
    {
        int n, k;
        scanf(" %d %d",&n,&k);
        printf("%lld\n",dp[n][k]);
    }
    return 0;
}
