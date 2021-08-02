#include <bits/stdc++.h>
using namespace std;

#define mod 998244353

long long dp[5050][5050];
vector<int> g[5050];

int main()
{
    int n, m, k;
    scanf(" %d %d %d",&n,&m,&k);
    while(m--)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        g[u].push_back(v), g[v].push_back(u);
    }
    long long prv = 1, now = 0;
    dp[0][1] = 1;
    for(int i=1 ; i<=k ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            dp[i][j] = prv - dp[i-1][j];
            dp[i][j] %= mod;
            dp[i][j] += mod;
            dp[i][j] %= mod;
            for(int k : g[j])
            {
                dp[i][j] -= dp[i-1][k];
                dp[i][j] %= mod;
                dp[i][j] += mod;
                dp[i][j] %= mod;
            }
            now += dp[i][j];
            now %= mod;
        }
        prv = now;
        now = 0;
    }
    printf("%lld\n",dp[k][1]);
    return 0;
}
