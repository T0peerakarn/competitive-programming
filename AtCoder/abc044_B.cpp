#include <bits/stdc++.h>
using namespace std;

int cnt[26];
char str[110];

int main()
{
    scanf(" %s",str);
    int n = strlen(str);
    for(int i=0 ; i<n ; i++) cnt[str[i]-'a']++;
    for(int i=0 ; i<26 ; i++) if(cnt[i]%2)
    {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    return 0;
}
