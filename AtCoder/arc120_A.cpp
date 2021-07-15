#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

long long arr[N], mx[N];

int main()
{
    int n;
    scanf(" %d",&n);
    for(int i=1 ; i<=n ; i++)
    {
        scanf(" %lld",&arr[i]);
        mx[i] = max(arr[i], mx[i-1]);
        arr[i] += arr[i-1];
    }
    for(int i=1 ; i<=n ; i++)
    {
        arr[i] += arr[i-1];
        printf("%lld\n",arr[i]+mx[i]*i);
    }
    return 0;
}
