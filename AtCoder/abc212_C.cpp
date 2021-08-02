#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, ans = 1e9;
    scanf(" %d %d",&n,&m);
    vector<int> a(n), b(m);
    for(int &x : a) scanf(" %d",&x);
    for(int &x : b) scanf(" %d",&x);
    sort(b.begin(), b.end());
    for(int x : a)
    {
        int l=0, r=m-1;
        while(l != r)
        {
            int mid = (l+r+1)>>1;
            (b[mid] <= x) ? l = mid : r = mid-1;
        }
        for(int i=max(0, l-1) ; i<=min(l+1, m-1) ; i++) ans = min(ans, abs(b[i]-x));
    }
    printf("%d\n",ans);
    return 0;
}
