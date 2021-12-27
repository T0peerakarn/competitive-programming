#include <bits/stdc++.h>
using namespace std;

const int N = 505;

long long p[N];
pair<long long, int> dp[N][N];

int main()
{
    int n, m, q;

    scanf(" %d %d %d",&n,&m,&q);
    for(int i=1 ; i<=n ; i++) scanf(" %lld",&p[i]);

    for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=n ; j++) dp[i][j] = {p[i] + p[j], 2};
    
    while(m--)
    {
        int a, b;
        long long c;
        scanf(" %d %d %lld",&a,&b,&c);
        if(c < dp[a][b].first) dp[a][b] = dp[b][a] = {c, 2};
    }

    for(int k=1 ; k<=n ; k++) for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=n ; j++) if(dp[i][k].first + dp[k][j].first < dp[i][j].first || (dp[i][k].first + dp[k][j].first == dp[i][j].first && dp[i][k].second + dp[k][j].second > dp[i][j].second)) dp[i][j] = {dp[i][k].first + dp[k][j].first, dp[i][k].second + dp[k][j].second};

    while(q--)
    {
        int a, b;
        scanf(" %d %d",&a,&b);
        printf("%lld %d\n",dp[a][b].first,dp[a][b].second);
    }
    return 0;
}
