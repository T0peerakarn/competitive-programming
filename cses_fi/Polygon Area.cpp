#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

#define x first
#define y second

pair<long long, long long> p[N];

int main()
{
    int n;
    scanf(" %d",&n);
    for(int i=0 ; i<n ; i++) scanf(" %lld %lld",&p[i].x,&p[i].y);
    long long ans = 0;
    for(int i=0 ; i<n ; i++)
    {
        ans += p[i].x * p[(i+1)%n].y;
        ans -= p[i].x * p[(i-1+n)%n].y;
    } 
    printf("%lld\n",abs(ans));
    return 0;
}
