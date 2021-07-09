#include <bits/stdc++.h>
using namespace std;

char str[131100];

int opt(int l, int r, char c)
{
    if(l == r) return (str[l] == c) ? 0 : 1;
    int mid = (l+r)>>1;
    int L = opt(l, mid, c+1), R = opt(mid+1, r, c+1);
    for(int i=l ; i<=mid ; i++) if(str[i] != c) R++;
    for(int i=mid+1 ; i<=r ; i++) if(str[i] != c) L++;
    return min(L, R);
}

void solve()
{
    int n;
    scanf(" %d",&n);
    scanf(" %s",str+1);
    printf("%d\n",opt(1, n, 'a'));
}

int main()
{
    int t;
    scanf(" %d",&t);
    while(t--) solve();
    return 0;
}
