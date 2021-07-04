#include <bits/stdc++.h>
using namespace std;

const int N = 2e3+5;

bool bipartite;
int col[N], cnt[3];
bool visit[N], possible_sum[N];
vector<int> g[N];

void init()
{
    bipartite = true;
    possible_sum[0] = true;
    for(int i=1 ; i<=2000 ; i++)
    {
        possible_sum[i] = false;
        col[i] = 0;
        visit[i] = false;
        g[i].clear();
    }
}

void paint(int u, int c)
{
    if(col[u])
    {
        if(col[u] != c) bipartite = false;
        return ;
    }
    col[u] = c;
    for(auto v : g[u]) paint(v, 3-c);
}

void dfs(int u)
{
    visit[u] = true;
    cnt[col[u]]++;
    for(auto v : g[u])
    {
        if(visit[v]) continue ;
        dfs(v);
    }
}

void solve()
{
    init();
    int b, c, m;
    scanf(" %d %d %d",&b,&c,&m);
    if(b > c) swap(b, c);
    while(m--)
    {
        int u, v;
        scanf(" %d %d",&u,&v);
        g[u].push_back(v), g[v].push_back(u);
    }
    for(int i=1 ; i<=b+c ; i++) if(!col[i]) paint(i, 1);
    int sum_c1 = 0;
    vector<int> v;
    for(int i=1 ; i<=b+c ; i++)
    {
        if(visit[i]) continue;
        cnt[1] = cnt[2] = 0;
        dfs(i);
        if(cnt[1] > cnt[2]) swap(cnt[1], cnt[2]);
        sum_c1 += cnt[1];
        v.push_back(cnt[2]-cnt[1]);
    }
    for(auto x : v) for(int i=b+c ; i>=0 ; i--) if(possible_sum[i] && i+x <= b+c) possible_sum[i+x] = true;
    printf((bipartite && sum_c1 <= b && possible_sum[b-sum_c1]) ? "yes\n" : "no\n");
}

int main()
{
    int t;
    scanf(" %d",&t);
    while(t--) solve();
    return 0;
}
