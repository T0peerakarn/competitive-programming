#include <bits/stdc++.h>
using namespace std;

int fac[11];

int main()
{
    fac[0] = 1;
    for(int i=1 ; i<=10 ; i++) fac[i] = fac[i-1]*i;
    int p, ans = 0;
    scanf(" %d",&p);
    for(int i=10 ; i>=1 ; i--)
    {
        int c = min(100, p/fac[i]);
        p -= c*fac[i];
        ans += c;
    }
    printf("%d\n",ans);
    return 0;
}
