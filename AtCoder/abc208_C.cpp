#include <bits/stdc++.h>
using namespace std;

long long ans[200005];

int main()
{
    long long n, k;
    scanf(" %lld %lld",&n,&k);
    vector<pair<int, int>> v;
    for(int i=0 ; i<n ; i++)
    {
        int a;
        scanf(" %d",&a);
        v.push_back({a, i});
        ans[i] = k/n;
    }
    sort(v.begin(), v.end());
    k %= n;
    for(int i=0 ; i<n && k>0 ; i++, k--) ans[v[i].second]++;
    for(int i=0 ; i<n ; i++) printf("%lld\n",ans[i]);
    return 0;
}
