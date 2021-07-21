#include <bits/stdc++.h>
using namespace std;

int deg[100005];
bool buildable[100005], builded[100005];
vector<int> g[100005], gt[100005], lv[10005];

void CheckBuildable(int n)
{
    queue<int> topo;
    for(int i=1 ; i<=n ; i++) if(deg[i] == 0) topo.push(i);
    while(!topo.empty())
    {
        int now = topo.front();
        topo.pop();
        buildable[now] = true;
        for(int nxt : gt[now])
        {
            deg[nxt]--;
            if(!deg[nxt]) topo.push(nxt);
        }
    }
}

int Solve(int n, int mid)
{
    int ret = 0;
    queue<int> topo;
    for(int i=1 ; i<=n ; i++) builded[i] = false;
    for(int i=1 ; i<=mid ; i++) for(int j : lv[i])
    {
        if(!buildable[j]) return 1e9;
        topo.push(j);
        builded[j] = true;
        ret++;
    }
    while(!topo.empty())
    {
        int now = topo.front();
        topo.pop();
        for(int nxt : g[now]) if(!builded[nxt])
        {
            topo.push(nxt);
            builded[nxt] = true;
            ret++;
        }
    }
    return ret;
}

int main()
{
    int n, m, k;
    scanf(" %d %d %d",&n,&m,&k);
    for(int i=1 ; i<=n ; i++)
    {
        int l, p;
        scanf(" %d %d",&l,&p);
        lv[l].push_back(i);
        while(p--)
        {
            int j;
            scanf(" %d",&j);
            g[i].push_back(j);
            gt[j].push_back(i);
            deg[i]++;
        }
    }
    CheckBuildable(n);
    int l=0, r=m;
    while(l != r)
    {
        int mid = (l+r+1)>>1;
        (Solve(n, mid) <= k) ? l = mid : r = mid-1;
    }
    printf((l) ? "%d\n" : "-1\n",l);
    return 0;
}
