#include <bits/stdc++.h>
using namespace std;

int a[1010], b[1010], dp[1010][1010];

int main()
{
    int n, m;
    scanf(" %d %d",&n,&m);
    for(int i=1 ; i<=n ; i++) scanf(" %d",&a[i]), dp[i][0] = i;
    for(int j=1 ; j<=m ; j++) scanf(" %d",&b[j]), dp[0][j] = j;
    for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=m ; j++)
    {
        if(a[i] != b[j]) dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i-1][j], dp[i][j-1])+1);
        else dp[i][j] = dp[i-1][j-1];
    }
    printf("%d\n",dp[n][m]);
    return 0;
}
