#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    scanf(" %d",&q);
    while(q--)
    {
        long long d;
        scanf(" %lld",&d);
        vector<int> v;
        while(d)
        {
            v.push_back(d%3);
            d/=3;
        }
        v.push_back(0);
        int last_two = -1;
        for(int i=0 ; i<v.size() ; i++) if(v[i] == 2) last_two = i;
        if(last_two != -1)
        {
            for(int i=0 ; i<=last_two ; i++) v[i] = 0;
            for(int i=last_two+1 ; i<v.size() ; i++)
            {
                v[i]++;
                if(v[i] == 2)
                {
                    v[i] = 0;
                    continue;
                }
                break;
            } 
        }
        long long ans = 0;
        for(int i=v.size()-1 ; i>=0 ; i--)
        {
            ans *= 3;
            ans += v[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
