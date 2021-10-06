#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

#define mod 1000000007

vector<pair<int, long long>> v[N];

int main()
{
    int n, len = 0;
    scanf(" %d",&n);
    for(int i=1 ; i<=n ; i++)
    {
        int d;
        scanf(" %d",&d);
        int l=0, r=len;
        while(l != r)
        {
            int mid = (l+r+1)>>1;
            (d > v[mid].back().first) ? l = mid : r = mid-1;
        }
        if(l == len) len++;
        long long frq = ((v[l+1].empty() ? 0 : v[l+1].back().second) + (l == 0 ? 1 : v[l].back().second))%mod;
        if(l && v[l][0].first >= d)
        {
            int ll=0, rr=v[l].size()-1;
            while(ll != rr)
            {
                int mm = (ll+rr+1)>>1;
                (v[l][mm].first >= d) ? ll = mm : rr = mm-1;
            }
            frq -= v[l][ll].second;
            frq %= mod;
            frq += mod;
            frq %= mod;
        }
        v[l+1].push_back({d, frq});
    }
    printf("%d %lld\n",len,v[len].back().second);
    return 0;
}
