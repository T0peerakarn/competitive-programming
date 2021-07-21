#include <bits/stdc++.h>
using namespace std;

const int N = 4e5+5;

int cnt_id, cnt_scc;
int id[N], low[N], scc[N];
bool onStack[N];
stack<int> stk;
vector<int> g[N];
vector<char> ans;

void dfs(int u, int p)
{
    id[u] = low[u] = ++cnt_id;
    onStack[u] = true;
    stk.push(u);
    for(int v : g[u])
    {
        if(!id[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if(onStack[v]) low[u] = min(low[u], id[v]);
    }
    if(id[u] == low[u])
    {
        cnt_scc++;
        while(true)
        {
            int now = stk.top();
            stk.pop();
            onStack[now] = false;
            scc[now] = cnt_scc;
            if(now == u) break;
        }
    }
}

void solve()
{
    int n, m;
    scanf(" %d %d",&n,&m);
    for(int i=1 ; i<=n ; i++)
    {
        int u, v;
        scanf(" %d %d",&u,&v); 
        g[u].push_back(v+m);
        g[v].push_back(u+m);
    }
    for(int i=1 ; i<=m/2 ; i++)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        g[u+m].push_back(v);
        g[v+m].push_back(u);
    }
    for(int i=1 ; i<=2*m ; i++) if(!id[i]) dfs(i, 0);
    for(int i=1 ; i<=m ; i++) if(scc[i] == scc[i+m])
    {
        ans.push_back('N');
        goto out;
    }
    ans.push_back('Y');
    out: ;
    cnt_id = cnt_scc = 0;
    for(int i=1 ; i<=2*m ; i++)
    {
        id[i] = 0;
        low[i] = 0;
        g[i].clear();
    }
}

int main()
{
    for(int i=1 ; i<=5 ; i++) solve();
    for(char x : ans) printf("%c",x);
    return 0;
}
