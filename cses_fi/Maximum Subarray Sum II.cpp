#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

long long arr[N];

int main()
{
    int n, a, b;
    long long ans = -1e18;
    scanf(" %d %d %d",&n,&a,&b);
    for(int i=1 ; i<=n ; i++)
    {
        scanf(" %lld",&arr[i]);
        arr[i] += arr[i-1];
    }    
    deque<pair<long long, int>> sw = {{0, 0}};
    for(int i=1 ; i<=n ; i++)
    {
        while(!sw.empty() && sw.front().second+b < i) sw.pop_front();
        if(i > a)
        {
            while(!sw.empty() && sw.back().first >= arr[i-a]) sw.pop_back();
            sw.push_back({arr[i-a], i-a});
        }
        if(i >= a) ans = max(ans, arr[i]-sw.front().first);
    }
    printf("%lld\n",ans);
    return 0;
}
