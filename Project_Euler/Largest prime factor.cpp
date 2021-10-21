#include <bits/stdc++.h>
using namespace std;

bool prime[500000];

int main()
{
    long long n = 600851475143, ans = 0;
    for(int i=2 ; i<500000 ; i++) prime[i] = true;
    for(long long i=2 ; i<500000 ; i++)
    {
        if(!prime[i]) continue;
        for(int j=i+i ; j<500000 ; j+=i) prime[j] = false;
        if(n%i == 0) ans = i;
    }
    cout << ans << endl;
    return 0;
}

// 6857
