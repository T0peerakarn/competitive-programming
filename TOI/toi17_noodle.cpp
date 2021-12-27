#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, m, k;
long long arr[N];

bool solve(long long mid)
{
    int cnt_m = 0, cnt_k = 0;
    long long sum = 0;
    priority_queue<long long> heap;
    for(int i=1 ; i<=n ; i++)
    {
        sum += arr[i];
        cnt_k++;
        heap.push(-arr[i]);
        if(cnt_k > k)
        {
            sum += heap.top();
            heap.pop();
            cnt_k--;
        }
        if(sum >= mid && cnt_k == k)
        {
            cnt_m++;
            sum = 0;
            cnt_k = 0;
            while(!heap.empty()) heap.pop();
        }
    }
    return cnt_m >= m;
}

int main()
{
    scanf(" %d %d %d",&n,&m,&k);
    for(int i=1 ; i<=n ; i++) scanf(" %lld",&arr[i]);

    long long l=0, r=1e15;
    while(l != r)
    {
        long long mid = (l+r+1)>>1;
        (solve(mid)) ? l = mid : r = mid-1;
    }
    printf("%lld\n",l);
    return 0;
}
