#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+5;

struct DJK
{
    int node, weight, state;
    bool operator < (const DJK & o) const
    {
        return weight > o.weight;
    }
};

int dis[2][N];
bool visit[2][N];
vector<DJK> g[N];
priority_queue<DJK> djk;

void solve()
{
    int n, m, k, s, t;
    scanf(" %d %d %d %d %d",&n,&m,&k,&s,&t);
    for(int i=1 ; i<=n ; i++)
    {
        dis[0][i] = dis[1][i] = 1e9;
        visit[0][i] = visit[1][i] = false;
        g[i].clear();
    }
    while(m--)
    {
        int u, v, w;
        scanf(" %d %d %d",&u,&v,&w);
        g[u].push_back({v, w, 0});
    }
    while(k--)
    {
        int u, v, w;
        scanf(" %d %d %d",&u,&v,&w);
        g[u].push_back({v, w, 1});
        g[v].push_back({u, w, 1});
    }
    dis[1][s] = 0;
    djk.push({s, 0, 1});
    while(!djk.empty())
    {
        int nown = djk.top().node;
        int noww = djk.top().weight;
        int nows = djk.top().state;
        djk.pop();
        if(visit[nows][nown]) continue;
        visit[nows][nown] = true;
        for(auto x : g[nown]) if(nows >= x.state && dis[nows-x.state][x.node] > noww + x.weight)
        {
            dis[nows-x.state][x.node] = noww + x.weight;
            djk.push({x.node, dis[nows-x.state][x.node], nows-x.state});
        }
    }
    printf((visit[0][t] or visit[1][t]) ? "%d\n" : "-1\n", min(dis[0][t], dis[1][t]));
}

int main()
{
    int t;
    scanf(" %d",&t);
    while(t--) solve();
}
