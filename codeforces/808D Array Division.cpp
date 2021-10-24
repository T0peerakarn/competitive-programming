#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

long long arr[N], qs[N];
map<long long, int> pre, suf;

int main()
{
    int n;
    scanf(" %d",&n);
    for(int i=1 ; i<=n ; i++)
    {
        scanf(" %lld",&arr[i]);
        suf[arr[i]]++;
        qs[i] = qs[i-1] + arr[i];
    }
    if(qs[n]%2)
    {
        printf("NO\n");
        return 0;
    }
    long long sum = qs[n]/2;
    for(int i=1 ; i<=n ; i++)
    {
        suf[arr[i]]--;
        pre[arr[i]]++;
        if(qs[i] < sum)
        {
            if(suf[sum-qs[i]] > 0)
            {
                printf("YES\n");
                return 0;
            }
        }
        else if(qs[i] > sum)
        {
            if(pre[qs[i]-sum] > 0)
            {
                printf("YES\n");
                return 0;
            }
        }
        else
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
