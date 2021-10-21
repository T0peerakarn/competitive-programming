#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a = 0, b = 0;
    for(int i=1 ; i<=100 ; i++)
    {
        a += i*i;
        b += i;
    }
    b *= b;
    cout << abs(a-b) << endl;
    return 0;
}

// 25164150
