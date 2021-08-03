#include <bits/stdc++.h>
using namespace std;

int arr[1010], dp[303][1010];

int main()
{
    int n, k;
    scanf(" %d %d",&n,&k);
    for(int i=1 ; i<=n ; i++)
    {
        scanf(" %d",&arr[i]);
        dp[1][i] = arr[i] += arr[i-1];
    }
    for(int i=2 ; i<=k ; i++) for(int j=i ; j<=n ; j++)
    {
        dp[i][j] = 1e9;
        for(int k=j ; k>=i ; k--) dp[i][j] = min(dp[i][j], max(dp[i-1][k-1], arr[j]-arr[k-1]));
    }
    printf("%d\n",dp[k][n]);
    return 0;
}
