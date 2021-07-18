#include <bits/stdc++.h>
using namespace std;

typedef complex<double> CD;
const double PI = acos(-1);

char str[200005];

void fft(vector<CD> &p, bool inv)
{
    int n = p.size();

    for(int i=1, j=0 ; i<n ; i++)
    {
        int bit = n>>1;
        for( ; j&bit ; bit>>=1) j ^= bit;
        j ^= bit;
        if(i < j) swap(p[i], p[j]); 
    }

    for(int len=2 ; len<=n ; len*=2)
    {
        double ang = 2 * PI / len * (inv ? -1 : 1);
        CD t(cos(ang), sin(ang));
        for(int i=0 ; i<n ; i+=len)
        {
            CD w(1);
            for(int j=0 ; j<len/2 ; j++)
            {
                CD even = p[i+j], odd = w * p[i+j+len/2];
                p[i+j] = even + odd;
                p[i+j+len/2] = even - odd;
                w *= t;
            }
        }
    }

    if(inv) for(CD &x : p) x /= n;
}

int main()
{
    scanf(" %s",str+1);
    int n = strlen(str+1), sz = 1;
    while(sz < 2*n+1) sz *= 2;
    sz *= 2;
    vector<CD> p1(sz), p2(sz);
    for(int i=1 ; i<=n ; i++) if(str[i] == '1')
    {
        p1[n+i] = 1;
        p2[n-i] = 1;
    }
    fft(p1, false), fft(p2, false);
    for(int i=0 ; i<sz ; i++) p1[i] *= p2[i];
    fft(p1, true);
    for(int i=n+n+1 ; i<n+n+n ; i++) cout << (long long)(p1[i].real() + 0.5) << ' ';
    return 0;
}
