#include <bits/stdc++.h>
using namespace std;

const int N = 4e3+5;

long long cost[N][N], dp[2][N];

void solve(int k, int l, int r, int a, int b)
{
    if(l > r) return;
    int mid = (l+r)>>1, pos;
    long long opt = 1e18;
    for(int i=a ; i<=mid && i<=b ; i++) if(dp[(k-1)%2][i-1] + cost[i][mid] < opt)
    {
        opt = dp[(k-1)%2][i-1] + cost[i][mid];
        pos = i;
    }
    dp[k%2][mid] = opt;
    solve(k, l, mid-1, a, pos);
    solve(k, mid+1, r, pos, b);
}

int main()
{
    int n, k;
    scanf(" %d %d",&n,&k);
    for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=n ; j++) 
    {
        char c;
        scanf(" %c",&c);
        cost[i][j] = c-'0';
    }
    for(int sz=3 ; sz<=n ; sz++) for(int i=1 ; i+sz-1<=n ; i++) cost[i][i+sz-1] += cost[i+1][i+sz-1] + cost[i][i+sz-2] - cost[i+1][i+sz-2];
    for(int i=1 ; i<=n ; i++) dp[1][i] = cost[1][i];
    for(int i=2 ; i<=k ; i++) solve(i, i, n, i, n);
    printf("%lld\n",dp[k%2][n]);
    return 0;
}
