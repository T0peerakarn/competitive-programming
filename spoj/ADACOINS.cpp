#include<bits/stdc++.h>
using namespace std;

int ans[100005];
bitset<100005> bit;
// bit[i] = {1 : i exist, 0 : i DNE}

int main()
{
    bit[0] = 1;
    int n, q;
    scanf(" %d %d",&n,&q);
    for(int i=1 ; i<=n ; i++)
    {
        int d;
        scanf(" %d",&d);
        bit |= (bit << d);
    }
    for(int i=1 ; i<=100000 ; i++)
        ans[i] = ans[i-1] + bit[i];
    while(q--)
    {
        int a, b;
        scanf(" %d %d",&a,&b);
        printf("%d\n",ans[b] - ans[a-1]);
    }
    return 0;
}
