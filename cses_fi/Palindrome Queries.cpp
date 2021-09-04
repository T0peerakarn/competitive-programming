#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

const int N = 2e5;

long long t[N+5], arr[N+5], a[N+5], b[N+5], fw_a[N+5], fw_b[N+5];
char str[N+5];
map<char, long long> mp;

void update_a(int i, long long v)
{
    while(i <= 200000)
    {
        fw_a[i] += v;
        fw_a[i] %= mod;
        fw_a[i] += mod;
        fw_a[i] %= mod;
        i += -i&i;
    }
}

void update_b(int i, long long v)
{
    while(i <= 200000)
    {
        fw_b[i] += v;
        fw_b[i] %= mod;
        fw_b[i] += mod;
        fw_b[i] %= mod;
        i += -i&i;
    }
}

long long query_a(int i)
{
    if(i == 0) return 0;
    long long ret = 0;
    while(i)
    {
        ret += fw_a[i];
        ret %= mod;
        ret += mod;
        ret %= mod;
        i -= -i&i;
    }
    return ret;
}

long long query_b(int i)
{
    if(i == 0) return 0;
    long long ret = 0;
    while(i)
    {
        ret += fw_b[i];
        ret %= mod;
        ret += mod;
        ret %= mod;
        i -= -i&i;
    }
    return ret;
}

long long mop(long long a, long long b)
{
    if(b == 1) return a;
    long long ret = (b%2) ? a : 1, t = mop(a, b/2);
    ret *= t;
    ret %= mod;
    ret *= t;
    ret %= mod;
    return ret;
}

int main()
{
    for(char c = 'a' ; c<='z' ; c++)
        mp[c] = int(c-'a');
    t[0] = 1;
    for(int i=1 ; i<=200000 ; i++)
    {
        t[i] = t[i-1]*26;
        t[i] %= mod;
    }

    int n, q;
    scanf(" %d %d",&n,&q);
    for(int i=1 ; i<=n ; i++)
    {
        scanf(" %c",&str[i]);
        update_a(i, (t[i]*mp[str[i]])%mod);
        update_b(i, (t[n-i+1]*mp[str[i]])%mod);
    }
    while(q--)
    {
        int op;
        scanf(" %d",&op);
        if(op == 2)
        {
            int s, e;
            scanf(" %d %d",&s,&e);
            long long A = ((query_a(e) - query_a(s-1) + mod)%mod * mop(t[s], mod-2))%mod;
            long long B = ((query_b(e) - query_b(s-1) + mod)%mod * mop(t[n-e+1], mod-2))%mod;
            printf((A == B) ? "YES\n" : "NO\n");
        }
        else
        {
            int p;
            char c;
            scanf(" %d %c",&p,&c);
            update_a(p, -(t[p]*mp[str[p]])%mod);
            update_b(p, -(t[n-p+1]*mp[str[p]])%mod);
            str[p] = c;
            update_a(p, (t[p]*mp[str[p]])%mod);
            update_b(p, (t[n-p+1]*mp[str[p]])%mod);
        }
    }
    return 0;
}
