#include <bits/stdc++.h>
using namespace std;

bool destroy[200005], visit_s[100005], visit_e[100005];
pair<int, int> edge[200005];
stack<int> ans;
stack<pair<int, int>> query;
vector<int> g[100005], gt[100005];

void dfs(int u, int p)
{
    visit_s[u] = true;
    for(int v : g[u])
    {
        if(v == p || destroy[v] || visit_s[v]) continue;
        dfs(v, u);
    }
}

void dfst(int u, int p)
{
    visit_e[u] = true;
    for(int v : gt[u])
    {
        if(v == p || destroy[v] || visit_e[v]) continue;
        dfst(v, u);
    }
}

int main()
{
    int n, m, q;
    scanf(" %d %d %d",&n,&m,&q);
    for(int i=1 ; i<=m ; i++)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        g[u].push_back(v);
        gt[v].push_back(u);
        edge[i] = {u, v};
    }
    while(q--)
    {
        int a, b;
        scanf(" %d %d",&a,&b);
        if(a == 1) destroy[b] = true;
        query.push({a, b});
    }
    dfs(1, 0);
    dfst(n, 0);
    while(!query.empty())
    {
        int a, b;
        tie(a, b) = query.top();
        query.pop();
        if(a == 1)
        {
            destroy[b] = false;
            for(int v : gt[b]) if(visit_s[v])
            {
                dfs(v, 0);
                break;
            }
            for(int v : g[b]) if(visit_e[v])
            {
                dfst(v, 0);
                break;
            }
        }
        else ans.push(visit_s[b]&visit_e[b]);
    }
    while(!ans.empty())
    {
        printf("%d\n",ans.top());
        ans.pop();
    }
    return 0;
}
