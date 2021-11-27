#include <bits/stdc++.h>
using namespace std;

const int N = 505;

long long arr[N];

void solve()
{
    int n, m;
    scanf(" %d %d",&n,&m);
    long long l = 0, r = 1e15;
    for(int i=1 ; i<=n ; i++)
    {
        scanf(" %lld",&arr[i]);
        l = max(l, arr[i]);
    }
    while(l != r)
    {
        long long mid = (l+r)>>1, cap = 0;
        int cnt = 0;
        for(int i=1 ; i<=n ; i++)
        {
            if(arr[i] > cap)
            {
                cap = mid;
                cnt += 1;
            }
            cap -= arr[i];
        }
        (cnt <= m) ? r = mid : l = mid+1;
    }
    stack<int> ans;
    for(long long i=n, cap=0, group=0 ; i>=1 ; i--)
    {
        if(i == m-group) cap = 0;
        if(cap < arr[i])
        {
            cap = l;
            if(group) ans.push(-1);
            group += 1;
        }
        cap -= arr[i];
        ans.push(arr[i]);
    }
    while(!ans.empty())
    {
        printf((ans.top() == -1) ? "/ " : "%d ",ans.top());
        ans.pop();
    }
    printf("\n");
}

int main()
{
    int t;
    scanf(" %d",&t);
    while(t--) solve();
    return 0;
}
