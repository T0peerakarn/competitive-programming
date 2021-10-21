#include <bits/stdc++.h>
using namespace std;

int main()
{
    for(int i=1 ; true ; i++)
    {
        for(int j=1 ; j<=20 ; j++) if(i%j != 0) goto out;
        cout << i << endl;
        return 0;
        out: ;
    }
    return 0;
}

// 232792560
