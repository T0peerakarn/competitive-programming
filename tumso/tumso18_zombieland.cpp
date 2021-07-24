#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

struct DJK
{
    int node;
    long long weight;
    bool operator < (const DJK & o) const {return weight > o.weight;}
};

long long dis[N];
bool visit[N], dangerous[N];
vector<DJK> g[N];
priority_queue<DJK> djk;

int main()
{
    int n, m, s, e;
    scanf(" %d %d %d %d",&n,&m,&s,&e);
    while(m--)
    {
        int u, v;
        long long w;
        scanf(" %d %d %lld",&u,&v,&w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for(int i=1 ; i<=n ; i++) dis[i] = 1e18;
    djk.push({s, 0});
    dis[s] = 0;
    while(!djk.empty())
    {
        int nown = djk.top().node;
        djk.pop();
        if(visit[nown]) continue;
        visit[nown] = true;
        for(auto x : g[nown]) if(dis[x.node] > dis[nown] + x.weight)
        {
            dis[x.node] = dis[nown] + x.weight;
            djk.push({x.node, dis[x.node]});
        }
    }
    queue<int> backtrack;
    backtrack.push(e);
    dangerous[e] = true;
    while(!backtrack.empty())
    {
        int nown = backtrack.front();
        backtrack.pop();
        for(auto x : g[nown]) if(dis[nown] == dis[x.node] + x.weight && !dangerous[x.node])
        {
            dangerous[x.node] = true;
            backtrack.push(x.node);
        }
    }
    for(int i=1 ; i<=n ; i++)
    {
        dis[i] = 1e18;
        visit[i] = false;
        if(dangerous[i])
        {
            dis[i] = 0;
            djk.push({i, 0});
        }
    }
    while(!djk.empty())
    {
        int nown = djk.top().node;
        djk.pop();
        if(visit[nown]) continue;
        visit[nown] = true;
        for(auto x : g[nown]) if(dis[x.node] > dis[nown] + x.weight)
        {
            dis[x.node] = dis[nown] + x.weight;
            djk.push({x.node, dis[x.node]});
        }
    }
    int q;
    scanf(" %d",&q);
    while(q--)
    {
        int u;
        scanf(" %d",&u);
        printf("%lld\n",dis[u]);
    }
    return 0;
}
