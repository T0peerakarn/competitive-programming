#include <bits/stdc++.h>
using namespace std;

int arr[808][808], tmp[808][808];

int main()
{
    int n, k;
    scanf(" %d %d",&n,&k);
    for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=n ; j++) scanf(" %d",&arr[i][j]);
    int l=0, r=1e9;
    while(l != r)
    {
        int mid = (l+r)>>1;
        for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=n ; j++)
        {
            tmp[i][j] = (arr[i][j] <= mid) ? 1 : 0;
            tmp[i][j] += tmp[i-1][j] + tmp[i][j-1] - tmp[i-1][j-1];
            if(i >= k && j >= k)
            {
                int v = tmp[i][j] - tmp[i-k][j] - tmp[i][j-k] + tmp[i-k][j-k];
                if(k*k/2 - (k&1 ? 0 : 1) < v)
                {
                    r = mid;
                    goto out;
                }
            }
        }
        l = mid+1;
        out: ;
    }
    printf("%d\n",l);
    return 0;
}
