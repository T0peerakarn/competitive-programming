#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long ans = 2;
    long long f[3] = {0, 1, 2};
    for(int i=3 ; true ; i++)
    {
        f[i%3] = f[(i+2)%3] + f[(i+1)%3];
        if(f[i%3] > 4000000) break;
        if(f[i%3]%2 == 0) ans += f[i%3];
    }
    cout << ans << endl;
    return 0;
}

// 4613732
