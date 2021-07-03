#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

pair<long long, long long> p[5];

int main()
{
    int q;
    scanf(" %d",&q);
    while(q--)
    {
        for(int i=1 ; i<=3 ; i++) scanf(" %lld %lld",&p[i].x,&p[i].y);
        long long v = (p[1].y-p[2].y)*(p[2].x-p[3].x) - (p[2].y-p[3].y)*(p[1].x-p[2].x);
        if(v > 0) printf("RIGHT\n");
        else if(v == 0) printf("TOUCH\n");
        else printf("LEFT\n");
    }
    return 0;
}
