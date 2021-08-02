#include <bits/stdc++.h>
using namespace std;

int cnt[1000005];

int get_dis(int x, int y, pair<int, int> fire) {return abs(x-fire.first) + abs(y-fire.second);}

int main()
{
    int n, m, ans = 0;
    scanf(" %d %d",&n,&m);
    vector<pair<int, int>> fire(n);
    for(int i=0 ; i<n ; i++) scanf(" %d %d",&fire[i].first,&fire[i].second);
    for(int i=0 ; i<m ; i++)
    {
        int x, y, dis = 1e9;
        scanf(" %d %d",&x,&y);
        for(int j=0 ; j<n ; j++) dis = min(dis, get_dis(x, y, fire[j]));
        cnt[dis]++;
    }
    for(int i=1 ; i <=1000000 ; i++) ans = max(ans, cnt[i]);
    printf("%d\n",ans);
    return 0;
}
