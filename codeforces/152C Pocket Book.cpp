#include <bits/stdc++.h>
using namespace std;

const int N = 105;
#define mod 1000000007

set<char> st[N];

int main()
{
    int n, m;
    scanf(" %d %d",&n,&m);
    for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=m ; j++)
    {
        char c;
        scanf(" %c",&c);
        st[j].insert(c);
    }
    long long ans = 1;
    for(int j=1 ; j<=m ; j++)
    {
        ans *= st[j].size();
        ans %= mod;
    }
    printf("%lld\n",ans);
    return 0;
}
