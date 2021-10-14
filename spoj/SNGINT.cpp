#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    scanf(" %d",&n);
    if(n == 0) return void(printf("10\n"));
    if(n < 10) return void(printf("%d\n",n));
    vector<int> v;
    for(int i=9 ; i>=2 ; i--) while(n%i == 0)
    {
        v.push_back(i);
        n /= i;
    }
    if(n == 0 || n != 1) return void(printf("-1\n"));
    sort(v.begin(), v.end());
    for(int x : v) printf("%d",x);
    printf("\n");
}

int main()
{
    int t;
    scanf(" %d",&t);
    while(t--) solve();
}
