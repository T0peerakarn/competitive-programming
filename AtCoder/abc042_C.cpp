#include <bits/stdc++.h>
using namespace std;

bool dislike[10];

bool check(int n)
{
    while(n)
    {
        if(dislike[n%10]) return false;
        n /= 10;
    }
    return true;
}

int main()
{
    int n, k;
    scanf(" %d %d",&n,&k);
    for(int i=0 ; i<k ; i++)
    {
        int d;
        scanf(" %d",&d);
        dislike[d] = true;
    }
    for(int i=n ; true ; i++) if(check(i))
    {
        printf("%d\n",i);
        return 0;
    }
    return 0;
}
