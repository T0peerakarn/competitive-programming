#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long dp[10][100005];
char str[100005];
vector<char> v = {'x', 'c', 'h', 'o', 'k', 'u', 'd', 'a', 'i'};

int main()
{
    scanf(" %s",str+1);
    int n = strlen(str+1);
    dp[0][0] = 1;
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=0 ; j<=8 ; j++) dp[j][i] = dp[j][i-1];
        for(int j=1 ; j<=8 ; j++) if(str[i] == v[j])
        {
            dp[j][i] += dp[j-1][i-1];
            dp[j][i] %= mod;
        }
    }
    printf("%lld\n",dp[8][n]);
    return 0;
}
