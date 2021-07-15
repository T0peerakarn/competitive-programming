#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, x, y;
    scanf(" %d %d %d %d",&n,&k,&x,&y);
    printf("%d\n",min(n, k)*x+max(0, n-k)*y);
    return 0;
}
