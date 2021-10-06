#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

long long fw[1010];

long long query(int i)
{
    long long ret = 0;
    while(i)
    {
        ret += fw[i];
        i -= -i&i;
    }
    return ret;
}

void update(int i)
{
    while(i <= 1000)
    {
        fw[i] += 1;
        i += -i&i;
    }
}

long long solve()
{
    int n, m, k;
    scanf(" %d %d %d",&n,&m,&k);
    vector<pair<int, int>> v;
    for(int i=1 ; i<=k ; i++)
    {
        int a, b;
        scanf(" %d %d",&a,&b);
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    long long ret = 0;
    for(int i=0 ; i<k ; i++)
    {
        ret += i - query(v[i].second);
        update(v[i].second);
    }
    memset(fw, 0, sizeof fw);
    return ret;
}

int main()
{
    int t;
    scanf(" %d",&t);
    for(int i=1 ; i<=t ; i++) printf("Test case %d: %lld\n",i,solve());
}
