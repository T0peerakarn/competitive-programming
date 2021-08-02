#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    long long sum = 0;
    priority_queue<long long, vector<long long>, greater<long long>> heap;
    scanf(" %d",&q);
    while(q--)
    {
        int op;
        scanf(" %d",&op);
        if(op == 3)
        {
            printf("%lld\n",heap.top()+sum);
            heap.pop();
        }
        else
        {
            long long x;
            scanf(" %lld",&x);
            if(op == 1) heap.push(x-sum);
            else sum += x;
        }
    }
    return 0;
}
