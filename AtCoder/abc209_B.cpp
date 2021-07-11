#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    scanf(" %d %d",&n,&x);
    for(int i=0 ; i<n ; i++)
    {
        int d;
        scanf(" %d",&d);
        d -= (i%2);
        x -= d;
    }
    printf((x >= 0) ? "Yes\n" : "No\n");
    return 0;
}
