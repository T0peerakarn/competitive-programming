#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

struct Dijkstra
{
    int node, weight, turn;
    bool operator < (const Dijkstra & o) const
    {
        return weight > o.weight;
    }  
};

int arr[N], dis[2][N];
bool visit[2][N];

void solve()
{
    int n;
    scanf(" %d",&n);
    dis[1][0] = visit[1][0] = 0;
    for(int i=1 ; i<=n ; i++)
    {
        scanf(" %d",&arr[i]);
        arr[i] += arr[i-1];
        dis[0][i] = dis[1][i] = 1e9;
        visit[0][i] = visit[1][i] = false;
    }
    priority_queue<Dijkstra> pq;
    pq.push({0, 0, 1});
    while(!pq.empty())
    {
        int nown = pq.top().node;
        int noww = pq.top().weight;
        int nowt = pq.top().turn;
        pq.pop();
        if(nown == n)
        {
            printf("%d\n",noww);
            return;
        }
        if(visit[nowt][nown]) continue;
        visit[nowt][nown] = true;
        for(int i=1 ; i<=2 && nown+i<=n ; i++) if(dis[nowt^1][nown+i] > noww + nowt*(arr[nown+i]-arr[nown]))
        {
            dis[nowt^1][nown+i] = noww + nowt*(arr[nown+i]-arr[nown]);
            pq.push({nown+i, dis[nowt^1][nown+i], nowt^1});
        }
    }
}

int main()
{
    int t;
    scanf(" %d",&t);
    while(t--) solve();
    return 0;
}
