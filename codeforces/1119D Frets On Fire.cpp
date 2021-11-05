#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf(" %d",&n);
    vector<long long> tmp, v;
    set<long long> st;
    while(n--)
    {
        long long d;
        scanf(" %lld",&d);
        if(st.count(d)) continue;
        st.insert(d);
        tmp.push_back(d);
    }
    sort(tmp.begin(), tmp.end());
    for(int i=1 ; i<tmp.size() ; i++) v.push_back(tmp[i] - tmp[i-1]);
    sort(v.begin(), v.end());
    vector<long long> qs = v;
    for(int i=1 ; i<qs.size() ; i++) qs[i] += qs[i-1];
    int q;
    scanf(" %d",&q);
    while(q--)
    {
        long long a, b;
        scanf(" %lld %lld",&a,&b);
        long long ans = (b-a+1) * tmp.size();
        int l=-1, r=v.size()-1;
        while(l != r)
        {
            int mid = (l+r+1)>>1;
            (v[mid] <= (b-a+1)) ? l = mid : r = mid-1;
        }
        if(l != -1) ans -= (l+1)*(b-a+1) - qs[l];
        printf("%lld\n",ans);
    }
    return 0;
}
