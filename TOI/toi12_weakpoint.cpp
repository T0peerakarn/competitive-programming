#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;

int deg[N], sub[N], pa[N];
bool cycle[N];
vector<int> g[N];

int main()
{
    int n, m;
    scanf(" %d %d",&n,&m);
    for(int i=1 ; i<=n ; i++)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        g[u].push_back(v), g[v].push_back(u);
        deg[u]++, deg[v]++;
        sub[i] = 1;
        cycle[i] = true;
    }
    queue<int> topo;
    for(int i=1 ; i<=n ; i++) if(deg[i] == 1)
    {
        cycle[i] = false;
        topo.push(i);
    }
    while(!topo.empty())
    {
        int u = topo.front();
        topo.pop();
        for(int v : g[u])
        {
            if(!cycle[v]) continue;
            pa[u] = v;
            sub[v] += sub[u];
            if(--deg[v] == 1)
            {
                cycle[v] = false;
                topo.push(v);
            }
        }
    }
    int u = 0;
    if(cycle[m])
    {
        for(int i=1 ; i<=n ; i++) if(i != m && cycle[i] && sub[i]-1 > sub[u]-1) u = i;
        for(int v : g[m]) if(!cycle[v] && (sub[v]-1 > sub[u]-1 || (sub[v]-1 == sub[u]-1 && u > v))) u = v;
        printf("%d\n%d\n",u,sub[u]-1);
    }
    else
    {
        for(int v : g[m]) if(v != pa[m] && (sub[v]-1 > sub[u]-1 || (sub[v]-1 == sub[u]-1 && u > v))) u = v;
        if(n-sub[m]-1 > sub[u]-1 || (n-sub[m]-1 == sub[u]-1 && u > pa[m])) printf("%d\n%d\n",pa[m],n-sub[m]-1);
        else printf("%d\n%d\n",u,sub[u]-1);
    }
    return 0;
}
