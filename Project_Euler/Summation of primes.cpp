#include <bits/stdc++.h>
using namespace std;

bool prime[2000005];

int main()
{
    long long ans = 0;
    for(int i=2 ; i<=2000000 ; i++) prime[i] = true;
    for(int i=2 ; i<=2000000 ; i++)
    {
        if(!prime[i]) continue;
        ans += i;
        for(int j=i+i ; j<=2000000 ; j+=i) prime[j] = false;
    }
    cout << ans;
}

// 142913828922
