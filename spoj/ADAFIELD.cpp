#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;


void solve()
{
    int n, m, q;
    scanf(" %d %d %d",&n,&m,&q);
    set<long long> st[2];
    map<long long, long long> mp[2];
    priority_queue<long long> heap[2];
    st[0].insert(0);
    st[0].insert(n);
    st[1].insert(0);
    st[1].insert(m);
    heap[0].push(n);
    heap[1].push(m);
    for(int i=0 ; i<q ; i++)
    {
        long long a, b;
        scanf(" %lld %lld",&a,&b);
        if(!st[a].count(b))
        {
            long long l = *(--st[a].upper_bound(b)), r = *st[a].upper_bound(b);
            st[a].insert(b);
            heap[a].push(b-l);
            heap[a].push(r-b);
            mp[a][r-l]++;
            while(!heap[a].empty() && mp[a][heap[a].top()] > 0)
            {
                mp[a][heap[a].top()]--;
                heap[a].pop();
            }
        }
        printf("%lld\n",heap[0].top()*heap[1].top());
    }

}

int main()
{
    int t;
    scanf(" %d",&t);
    while(t--) solve();
    return 0;
}
