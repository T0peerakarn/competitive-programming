#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+5;

int pa[N], col[N];
vector<pair<int, int>> g[N];

int fp(int u) { return (u == pa[u]) ? u : pa[u] = fp(pa[u]); }

void dfs(int u, int p, int c)
{
    col[u] = c;
    for(pair<int, int> x : g[u])
    {
        if(x.first == p || col[x.first] != -1) continue;
        dfs(x.first, u, (c+x.second+3)%3);
    }
}

int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n, q, ans = 0;
        vector<tuple<int, int, int>> query;
        scanf(" %d %d",&n,&q);
        for(int i=1 ; i<=n ; i++)
        {
            pa[i] = i;
            col[i] = -1;
        }
        while(q--)
        {
            int op, u, v;
            scanf(" %d %d %d",&op,&u,&v);
            if(u > n || v > n || (op == 2 && u == v))
            {
                ans++;
                continue;
            }
            int uu = fp(u), vv = fp(v);
            if(uu != vv)
            {
                pa[uu] = vv;
                if(op == 1)
                {
                    g[u].push_back({v, 0});
                    g[v].push_back({u, 0});
                }
                else
                {
                    g[u].push_back({v, 1});
                    g[v].push_back({u, -1});
                }
            }
            else query.push_back({op, u, v});
        }
        for(int i=1 ; i<=n ; i++) if(col[i] == -1) dfs(i, 0, 0);
        for(tuple<int, int, int> x : query)
        {
            if(get<0>(x) == 1) ans += (col[get<1>(x)] != col[get<2>(x)]);
            else ans += ((col[get<1>(x)]+1)%3 != col[get<2>(x)]);
        }
        printf("%d\n",ans);
        for(int i=1 ; i<=n ; i++) g[i].clear();
    }
    return 0;
}
