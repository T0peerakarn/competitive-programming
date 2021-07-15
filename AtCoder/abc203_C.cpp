#include <bits/stdc++.h>
using namespace std;

struct DATA
{
    long long pos, money;
    bool operator < (const DATA & o) const
    {
        return pos > o.pos;
    }
};

int main()
{
    int n;
    long long k;
    priority_queue<DATA> heap;
    scanf(" %d %lld",&n,&k);
    while(n--)
    {
        long long p, m;
        scanf(" %lld %lld",&p,&m);
        heap.push({p, m});
    }
    while(!heap.empty())
    {
        if(k >= heap.top().pos) k += heap.top().money;
        heap.pop();
    }
    printf("%lld\n",k);
    return 0;
}
