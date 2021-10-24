#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5+5;
 
int arr[N];
bool visit[N], same[N], ic[N], dc[N];

// visit[i] -> does number i exist in past
// same[i] -> pair (i, i) DNE
// ic[i] -> pair(i-1, i) DNE , ex pair(2, 3)
// dc[i] -> pair(i+1. i) DNE , ex pair(5, 4)

int main()
{
    int n, k;
    scanf(" %d %d",&n,&k);
    for(int i=1 ; i<=k ; i++)
    {
        scanf(" %d",&arr[i]);
        same[arr[i]] = true;
    }
    for(int i=1 ; i<=k ; i++)
    {
        if(visit[arr[i]-1]) ic[arr[i]] = true;
        if(visit[arr[i]+1]) dc[arr[i]] = true;
        visit[arr[i]] = true;
    }
    int ans = 3*n-2;
    for(int i=1 ; i<=n ; i++)
    {
        ans -= same[i];
        ans -= ic[i];
        ans -= dc[i];
    }
    printf("%d\n",ans);
}

