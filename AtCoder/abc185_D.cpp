#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, last = 0, ans = 0;
    scanf(" %d %d",&n,&m);
    vector<int> pos, range;
    for(int i=0 ; i<m ; i++)
    {
        int d;
        scanf(" %d",&d);
        pos.push_back(d);
    }
    sort(pos.begin(), pos.end());
    for(int i=0 ; i<m ; last = pos[i], i++) if(pos[i] != last+1)range.push_back(pos[i]-last-1);
    if(last != n) range.push_back(n-last);
    sort(range.begin(), range.end());
    if(!range.empty())
    {
        ans = 1;
        for(int i=1 ; i<range.size() ; i++) ans += range[i]/range[0] + (range[i]%range[0] ? 1 : 0);
    }
    printf("%d\n",ans);
    return 0;
}
