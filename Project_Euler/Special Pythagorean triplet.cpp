#include <bits/stdc++.h>
using namespace std;

int main()
{
    for(int a=1 ; a<=1000 ; a++)
        for(int b=1 ; b<=1000 ; b++)
            for(int c=1 ; c<=1000 ; c++)
                if(a*a + b*b == c*c && a+b+c == 1000)
                {
                    cout << (a*b*c) << endl;
                    return 0;
                }
}

// 31875000
