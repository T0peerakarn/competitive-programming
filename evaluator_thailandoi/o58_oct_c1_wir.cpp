#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int p[N];

int main()
{
    int n, q;
    scanf(" %d %d",&n,&q);
    stack<pair<int, int>> stk;
    for(int i=1 ; i<=n ; i++)
    {
        int h;
        scanf(" %d",&h);
        while(!stk.empty() && stk.top().second >= h) stk.pop();
        p[i] = (stk.empty()) ? 0 : max(h - stk.top().second, p[stk.top().first]);
        stk.push({i, h});
    }
    sort(p+1, p+n+1);
    while(q--)
    {
        int d;
        scanf(" %d",&d);
        int l=0, r=n;
        while(l != r)
        {
            int mid = (l+r+1)>>1;
            (d >= p[mid]) ? l = mid : r = mid-1;
        }
        printf("%d\n",n-l);
    }
    return 0;
}
