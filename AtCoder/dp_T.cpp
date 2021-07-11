#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
const int N = 3e3+5;

long long dp[N][N];
char str[N];

int main()
{
    int n;
    scanf(" %d %s",&n,str+1);
    dp[1][1] = 1;
    for(int i=2 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            dp[i-1][j] += dp[i-1][j-1];
            dp[i-1][j] %= mod;
        }
        for(int j=1 ; j<=i ; j++) dp[i][j] = (str[i-1] == '>') ? ((dp[i-1][n] - dp[i-1][j-1] + mod)%mod) : dp[i-1][j-1];
    }
    long long ans = 0;
    for(int i=1 ; i<=n ; i++)
    {
        ans += dp[n][i];
        ans %= mod;
    }
    printf("%lld\n",ans);
    return 0;
}
