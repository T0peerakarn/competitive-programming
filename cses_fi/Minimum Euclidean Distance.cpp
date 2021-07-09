#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5+5;
 
struct point
{
    long long x, y;
};
 
point p[N];
 
bool sort_x(point a, point b) {return a.x < b.x;}
bool sort_y(point a, point b) {return a.y < b.y;}
 
long long distance(point a, point b) {return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);}
 
long long ClosetPair(int l, int r)
{
    int n = r-l+1;
    if(n <= 3)
    {
        long long mn = 8e18;
        for(int i=l ; i<=r ; i++) for(int j=i+1 ; j<=r ; j++) mn = min(mn, distance(p[i], p[j]));
        return mn;
    }
    int mid = (l+r)>>1;
    long long ret = min(ClosetPair(l, mid), ClosetPair(mid+1, r));
    vector<point> v;
    for(int i=l ; i<=r ; i++) if(p[mid].x-sqrt(ret) <= p[i].x && p[i].x <= p[mid].x+sqrt(ret)) v.push_back(p[i]);
    int sz = v.size();
    sort(v.begin(), v.end(), sort_y);
    for(int i=0 ; i<sz ; i++) for(int j=1 ; j<8 && i+j<sz ; j++) ret = min(ret, distance(v[i], v[i+j]));
    return ret;
}
 
int main()
{
    int n;
    scanf(" %d",&n);
    for(int i=1 ; i<=n ; i++) scanf(" %lld %lld",&p[i].x,&p[i].y);
    sort(p+1, p+n+1, sort_x);
    printf("%lld\n",ClosetPair(1, n));
    return 0;
}
