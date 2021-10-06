#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

bool ret, visit[N], inq[N];
vector<int> g[N];

bool solve()
{
    int n, m, r;
    ret = true;
    scanf(" %d %d %d",&n,&m,&r);
    while(m--)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        g[u].push_back(v), g[v].push_back(u);
    }
    while(r--)
    {
        int u, k;
        scanf(" %d %d",&u,&k);
        queue<int> q;
        queue<pair<int, int>> bfs;
        q.push(u);
        inq[u] = true;
        bfs.push({u, k});
        while(!bfs.empty())
        {
            int u = bfs.front().first;
            int k = bfs.front().second;
            bfs.pop();
            if(visit[u])
            {
                ret = false;
                continue;
            }
            if(k) for(int v : g[u]) if(!inq[v])
            {
                q.push(v);
                inq[v] = true;
                bfs.push({v, k-1});
            }
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = false;
            visit[u] = true;
        }
    }
    for(int i=1 ; i<=n ; i++)
    {
        if(!visit[i]) ret = false;
        visit[i] = false;
        g[i].clear();
    }
    return ret;
}

int main()
{
    int t;
    scanf(" %d",&t);
    while(t--) printf(solve() ? "Yes\n" : "No\n");
}
