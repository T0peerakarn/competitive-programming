#include <bits/stdc++.h>
using namespace std;

const int N = 1505;

long long arr[N][N], dp[5][N][N], c13[N][N], c24[N][N], c12[N][N], c34[N][N];

int main()
{
    int n, m;
    scanf(" %d %d",&n,&m);
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=m ; j++)
            scanf(" %lld",&arr[i][j]);

    for(int i=1 ; i<=n ; i++)
    {
        dp[1][1][1] = arr[1][1];
        for(int j=1 ; j<=m ; j++)
        {
            if(i == 1 && j == 1) continue;
            long long opt = 1e18;
            if(i != 1) opt = min(opt, dp[1][i-1][j]);
            if(j != 1) opt = min(opt, dp[1][i][j-1]);
            dp[1][i][j] = opt + arr[i][j];
        }
        dp[2][1][m] = arr[1][m];
        for(int j=m ; j>=1 ; j--)
        {
            if(i == 1 && j == m) continue;
            long long opt = 1e18;
            if(i != 1) opt = min(opt, dp[2][i-1][j]);
            if(j != m) opt = min(opt, dp[2][i][j+1]);
            dp[2][i][j] = opt + arr[i][j];
        }
    }
    for(int i=n ; i>=1 ; i--)
    {
        dp[3][n][1] = arr[n][1];
        for(int j=1 ; j<=m ; j++)
        {
            if(i == n && j == 1) continue;
            long long opt = 1e18;
            if(i != n) opt = min(opt, dp[3][i+1][j]);
            if(j != 1) opt = min(opt, dp[3][i][j-1]);
            dp[3][i][j] = opt + arr[i][j];
        }
        dp[4][n][m] = arr[n][m];
        for(int j=m ; j>=1 ; j--)
        {
            if(i == n && j == m) continue;
            long long opt = 1e18;
            if(i != n) opt = min(opt, dp[4][i+1][j]);
            if(j != m) opt = min(opt, dp[4][i][j+1]);
            dp[4][i][j] = opt + arr[i][j];
        }
    }

    for(int j=1 ; j<=m ; j++)
        for(int i=1 ; i<=n ; i++)
        {
            c13[i][j] = dp[1][i][j] + dp[3][i][j] - arr[i][j];
            if(j != 1) c13[i][j] = min(c13[i][j], c13[i][j-1] + arr[i][j]);
        }
    for(int j=m ; j>=1 ; j--)
        for(int i=1 ; i<=n ; i++)
        {
            c24[i][j] = dp[2][i][j] + dp[4][i][j] - arr[i][j];
            if(j != m) c24[i][j] = min(c24[i][j], c24[i][j+1] + arr[i][j]);
        }
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=m ; j++)
        {
            c12[i][j] = dp[1][i][j] + dp[2][i][j] - arr[i][j];
            if(i != 1) c12[i][j] = min(c12[i][j], c12[i-1][j] + arr[i][j]);
        }
    for(int i=n ; i>=1 ; i--)
        for(int j=1 ; j<=m ; j++)
        {
            c34[i][j] = dp[3][i][j] + dp[4][i][j] - arr[i][j];
            if(i != n) c34[i][j] = min(c34[i][j], c34[i+1][j] + arr[i][j]);
        }

    long long ans = 1e18;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<m ; j++)
            ans = min(ans, c13[i][j] + c24[i][j+1]);
    for(int j=1 ; j<=m ; j++)
        for(int i=1 ; i<n ; i++)
            ans = min(ans, c12[i][j] + c34[i+1][j]);
    printf("%lld\n",ans);
    return 0;
}
