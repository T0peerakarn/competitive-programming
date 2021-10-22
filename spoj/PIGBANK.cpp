#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int dp[N];
bool visit[N];

void solve()
{
    for(int i=1 ; i<=10000 ; i++)
    {
        dp[i] = 1e18;
        visit[i] = false;
    }
    dp[0] = 0;
    visit[0] = true;
    int e, f, n;
    scanf(" %d %d %d",&e,&f,&n);
    while(n--)
    {
        int v, w;
        scanf(" %d %d",&v,&w);
        for(int i=0 ; i+w<=f-e ; i++) if(visit[i])
        {
            dp[i+w] = min(dp[i+w], dp[i] + v);
            visit[i+w] = true;
        }
    }
    printf((visit[f-e]) ? "The minimum amount of money in the piggy-bank is %d.\n" : "This is impossible.\n",dp[f-e]);
}

int main()
{
    int t;
    scanf(" %d",&t);
    while(t--) solve();
}
