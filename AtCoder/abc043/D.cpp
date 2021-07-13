#include <bits/stdc++.h>
using namespace std;

int sz[26];
char str[100005];
vector<int> idx[26];

bool Check(int n)
{
    for(int i=0 ; i<26 ; i++)
    {
        if(sz[i] < n) continue;
        for(int j=n-1 ; j<sz[i] ; j++) if(n*2 > idx[i][j] - idx[i][j-n+1] + 1) return true;
    }
    return false;
}

int main()
{
    scanf(" %s",str+1);
    int n = strlen(str+1);
    for(int i=1 ; i<=n ; i++) idx[str[i]-'a'].push_back(i), sz[str[i]-'a']++;
    int l = 1, r = n;
    while(l != r)
    {
        int mid = (l+r+1)>>1;
        (Check(mid)) ? l = mid : r = mid-1;
    }  
    if(l == 1) printf("-1 -1\n");
    else
    {
        for(int i=0 ; i<26 ; i++)
        {
            if(sz[i] < l) continue;
            for(int j=l-1 ; j<sz[i] ; j++) if(l*2 > idx[i][j] - idx[i][j-l+1] + 1)
            {
                printf("%d %d\n",idx[i][j-l+1],idx[i][j]);
                return 0;
            }
        }
    }
    return 0;
}
