#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int arr[N];
map<int, int> mp;

int main()
{
    int n;
    scanf(" %d",&n);
    for(int i=1 ; i<=n ; i++)
    {
        scanf(" %d",&arr[i]);
        arr[i] += arr[i-1];
        mp[arr[i]] = i;
    }

    if(arr[n]%2)
    {
        printf("NO\n");
        return 0;
    }

    for(int i=1 ; i<=n ; i++)
        if(arr[i] == arr[n]-arr[i])
        {
            printf("%d\n",i);
            return 0;
        }

    for(int i=1 ; i<=n ; i++)
        if(mp.count(arr[i]+arr[n]/2))
        {
            printf("%d %d\n",i,mp[arr[i]+arr[n]/2]);
            return 0;
        }

    printf("NO\n");
    return 0;
}
