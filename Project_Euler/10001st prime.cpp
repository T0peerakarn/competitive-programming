#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    for(int i=2 ; i*i<=n ; i++) if(n%i == 0) return false;
    return true;
}

int main()
{
    for(int i=2, cnt=0 ; true ; i++)
    {
        if(isPrime(i)) cnt++;
        if(cnt == 10001)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}

// 104743
