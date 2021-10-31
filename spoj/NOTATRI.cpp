#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int arr[N];

int main()
{
    while(true)
    {
        int n;
        scanf(" %d",&n);
        if(!n) return 0;
        long long ans = 0;
        for(int i=1 ; i<=n ; i++) scanf(" %d",&arr[i]);
        sort(arr+1, arr+n+1);
        for(int i=1 ; i<=n ; i++) for(int j=i+1 ; j<=n ; j++)
        {
            int l=j+1, r=n+1;
            while(l != r)
            {
                int mid = (l+r)>>1;
                (arr[i] + arr[j] < arr[mid]) ? r = mid : l = mid+1;
            }
            ans += n-l+1;
        }
        printf("%lld\n",ans);
    }
}
