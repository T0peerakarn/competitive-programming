#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf(" %d",&n);
    long long ans = 1;
    for(int i=n-1, j=1 ; i>n-12 ; i--)
    {
        ans *= i;
        if(j <= 11 && ans%j == 0)
        {
            ans /= j;
            j++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
