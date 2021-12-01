#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

struct DIJKSTRA
{
    int node, weight;
    bool operator < (const DIJKSTRA & o) const
    {
        return weight > o.weight;
    }
};

int cnt_id, cnt_scc;
int deg[N], id[N], low[N], scc[N], scc_sz[N], dis[N];
bool visit[N];
stack<int> node;
vector<pair<int, int>> g[N];
vector<tuple<int, int, int>> edge;
priority_queue<DIJKSTRA> dijkstra;

void dfs_scc(int u, int p)
{
    id[u] = low[u] = ++cnt_id;
    node.push(u);
    for(auto x : g[u])
    {
        if(x.first == p) continue;
        if(!id[x.first])
        {
            dfs_scc(x.first, u);
            low[u] = min(low[u], low[x.first]);
        }
        else low[u] = min(low[u], id[x.first]);
    }
    if(low[u] == id[u])
    {
        cnt_scc++;
        int now;
        do
        {
            now = node.top();
            node.pop();
            scc[now] = cnt_scc;
            scc_sz[cnt_scc]++;
        } while (now != u);  
    }
}

void sssp(int s, int n)
{
    for(int i=1 ; i<=n ; i++)
    {
        dis[i] = 1e9;
        visit[i] = false;
    }
    dis[s] = 0;
    dijkstra.push({s, 0});
    while(!dijkstra.empty())
    {
        int nown = dijkstra.top().node;
        int noww = dijkstra.top().weight;
        dijkstra.pop();
        if(visit[nown]) continue;
        visit[nown] = true;
        for(auto x : g[nown]) if(dis[x.first] > noww + x.second)
        {
            dis[x.first] = noww + x.second;
            dijkstra.push({x.first, dis[x.first]});
        }
    }
}

bool Check(tuple<int, int, int> a, tuple<int, int, int> b)
{
    if(get<0>(a) == get<0>(b)) return false;
    if(get<0>(a) == get<1>(b)) return false;
    if(get<1>(a) == get<0>(b)) return false;
    if(get<1>(a) == get<1>(b)) return false;
    return true;
}

int main()
{
    int n, m, ans = 0;
    scanf(" %d %d",&m,&n);
    for(int i=0 ; i<m ; i++)
    {
        int u, v, w;
        scanf(" %d %d %d",&u,&v,&w);
        u++, v++;
        edge.push_back({u, v, w});
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs_scc(1, 0);
    for(int i=0 ; i<m ; i++)
    {
        if(scc[get<0>(edge[i])] == scc[get<1>(edge[i])])
        {
            ans += get<2>(edge[i]);
            deg[get<0>(edge[i])]++, deg[get<1>(edge[i])]++;
        }
        else ans += 2*get<2>(edge[i]);
    }
    vector<int> s_node;
    for(int i=1 ; i<=n ; i++) if(deg[i] == 3) s_node.push_back(i);
    vector<tuple<int, int, int>> special_edge;
    for(int i=0 ; i<s_node.size() ; i++)
    {
        sssp(s_node[i], n);
        for(int j=i+1 ; j<s_node.size() ; j++) special_edge.push_back({i, j, dis[s_node[j]]});
    }
    int mn = (special_edge.size() == 0) ? 0 : (special_edge.size() == 1) ? get<2>(special_edge[0]) : 1e9;
    for(int i=0 ; i<special_edge.size() ; i++) for(int j=i+1 ; j<special_edge.size() ; j++) if(Check(special_edge[i], special_edge[j])) mn = min(mn, get<2>(special_edge[i]) + get<2>(special_edge[j]));
    ans += mn;
    printf("%d\n",ans);
    return 0;
}
