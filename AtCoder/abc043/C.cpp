#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = 1e9;
    scanf(" %d",&n);
    vector<int> v(n);
    for(auto &x : v) scanf(" %d",&x);
    for(int i=-100 ; i<=100 ; i++)
    {
        int sum = 0;
        for(int j=0 ; j<n ; j++) sum += (i-v[j])*(i-v[j]);
        ans = min(ans, sum);
    }
    printf("%d\n",ans);
    return 0;
}
