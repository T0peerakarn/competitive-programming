#include <bits/stdc++.h>
using namespace std;

struct Matrix{
    long long t[128][128];
};

Matrix m[30], ans, tmp;;

int main()
{
    int n, k;
    scanf(" %d %d",&n,&k);
    n -= k-1;
    for(int i=0 ; i<(1<<k) ; i++)
    {
        long long d;
        scanf(" %lld",&d);
        m[0].t[i][i/2] = m[0].t[i][i/2 + (1<<(k-1))] = d;
    }
    for(int i=1 ; i<30 ; i++)
        for(int a=0 ; a<(1<<k) ; a++)
            for(int b=0 ; b<(1<<k) ; b++)
                for(int c=0 ; c<(1<<k) ; c++)
                    m[i].t[a][b] = max(m[i].t[a][b], m[i-1].t[a][c] + m[i-1].t[c][b]);
    for(int i=0 ; i<30 ; i++) if((1<<i)&n)
    {
        for(int a=0 ; a<(1<<k) ; a++)
            for(int b=0 ; b<(1<<k) ; b++)
            {
                tmp.t[a][b] = 0;
                for(int c=0 ; c<(1<<k) ; c++)
                    tmp.t[a][b] = max(tmp.t[a][b], ans.t[a][c] + m[i].t[c][b]);
            }
        ans = tmp;
    }
    long long mx = 0;
    for(int i=0 ; i<(1<<k) ; i++) for(int j=0 ; j<(1<<k) ; j++) mx = max(mx, ans.t[i][j]);
    printf("%lld\n",mx);
    return 0;
}
