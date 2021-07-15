#include <bits/stdc++.h>
using namespace std;

long long dp[55][2505];

int main()
{
    dp[0][0] = 1;
    int n, m;
    scanf(" %d %d",&n,&m);
    for(int i=1 ; i<=n ; i++)
    {
        int v;
        scanf(" %d",&v);
        for(int j=n ; j>=1 ; j--) for(int k=2500 ; k>=v ; k--) dp[j][k] += dp[j-1][k-v];
    }
    long long ans = 0;
    for(int i=1 ; i<=n ; i++) ans += dp[i][i*m];
    printf("%lld\n",ans);
    return 0;
}
