#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef long long ll;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+5;

ll qs[N];

int main()
{
    int n;
    ll k;
    scanf(" %d %lld",&n,&k);
    for(int i=1 ; i<=n ; i++)
    {
        scanf(" %lld",&qs[i]);
        qs[i] += qs[i-1];
    }
    ll l = -1e12, r = 1e12;
    while(l != r)
    {
        ll mid = (l+r+1)>>1, cnt = 0, sum = 0;
        ordered_set<pair<ll, ll>> t;
        t.insert({0, ++cnt});
        for(int i=1 ; i<=n ; i++)
        {
            sum += t.order_of_key({qs[i]-mid, N});
            t.insert({qs[i], ++cnt});
        } 
        (sum >= k) ? l = mid : r = mid-1;
    }
    printf("%lld\n",l);
    return 0;
}
