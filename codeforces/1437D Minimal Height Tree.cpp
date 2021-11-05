#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int arr[N];

void solve()
{
    int n, mx = 0;
    scanf(" %d",&n);
    for(int i=1 ; i<=n ; i++) scanf(" %d",&arr[i]);
    int last = 1;
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int lv = que.front();
        que.pop();
        mx = max(mx, lv);
        if(last == n) continue;
        do
        {
            last++;
            que.push(lv+1);
        } while (last != n && arr[last] < arr[last+1]);
    }
    printf("%d\n",mx);
}
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--) solve();
    return 0;
}
