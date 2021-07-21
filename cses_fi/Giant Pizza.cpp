#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int cnt_id, cnt_scc;
int id[N], low[N], scc[N], ans[N];
bool OnStack[N];
stack<int> stk;
vector<int> g[N];

int neg(int u, int n) {return (u <= n) ? u+n : u-n;}

void dfs(int u)
{
    id[u] = low[u] = ++cnt_id;
    stk.push(u);
    OnStack[u] = true;
    for(int v : g[u])
    {
        if(!id[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(OnStack[v]) low[u] = min(low[u], id[v]);
    }
    if(id[u] == low[u])
    {
        cnt_scc++;
        while(true)
        {
            int now = stk.top();
            stk.pop();
            OnStack[now] = false;
            scc[now] = cnt_scc;
            if(now == u) break;
        }
    }
}

int main()
{
    int m, n;
    scanf(" %d %d",&m,&n);
    while(m--)
    {
        char pu, pv;
        int u, v;
        scanf(" %c %d %c %d",&pu,&u,&pv,&v);
        if(pu == '-') u += n;
        if(pv == '-') v += n;
        g[neg(u, n)].push_back(v);
        g[neg(v, n)].push_back(u);
    }
    for(int i=1 ; i<=2*n ; i++) if(!id[i]) dfs(i);
    for(int i=1 ; i<=n ; i++) if(scc[i] == scc[i+n])
    {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    for(int i=1 ; i<=n ; i++) printf((scc[i] < scc[i+n]) ? "+ " : "- ");
    return 0;
}
