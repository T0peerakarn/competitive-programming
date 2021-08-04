#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long dp[2][1000005];

int main()
{
    dp[0][0] = dp[0][1] = dp[1][1] = 1;
    for(int i=2 ; i<=1000000 ; i++)
    {
        dp[0][i] = (2*dp[0][i-1] + dp[1][i-1])%mod;
        dp[1][i] = (4*dp[1][i-1] + dp[0][i-1])%mod;
    }
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n;
        scanf(" %d",&n);
        printf("%lld\n",(dp[0][n]+dp[1][n])%mod);
    }    
    return 0;
}
