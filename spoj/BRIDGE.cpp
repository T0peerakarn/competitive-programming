#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;

int x[N], dp[N];

int solve()
{
    int n, len = 0;
    scanf(" %d",&n);
    vector<pair<int, int>> v;
    for(int i=0 ; i<n ; i++) scanf(" %d",&x[i]);
    for(int i=0 ; i<n ; i++)
    {
        int y;
        scanf(" %d",&y);
        v.push_back({x[i], y});
    }
    sort(v.begin(), v.end());
    for(int i=0 ; i<n ; i++)
    {
        int l=0, r=len;
        while(l != r)
        {
            int mid = (l+r+1)>>1;
            (v[i].second >= dp[mid]) ? l = mid : r = mid-1;
        }
        if(l == len) len++;
        dp[l+1] = v[i].second;
    }
    return len;
}

int main()
{
    int t;
    scanf(" %d",&t);
    while(t--) printf("%d\n",solve());
}
