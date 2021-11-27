#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int pa[N*2];

int fp(int u) {return pa[u] = (u == pa[u]) ? u : fp(pa[u]);}

int main()
{
    while(true)
    {
        int n;
        scanf(" %d",&n);
        if(n == 0) return 0;
        for(int i=1 ; i<=n*2 ; i++) pa[i] = i;
        for(int i=1 ; i<=n ; i++)
        {
            int u;
            char opr[10];
            scanf(" %d %s",&u,&opr);
            if(opr[0] == 't')
            {
                pa[fp(i)] = fp(u);
                pa[fp(i+n)] = fp(u+n);
            }
            else
            {
                pa[fp(i)] = fp(u+n);
                pa[fp(i+n)] = fp(u);
            }
        }
        for(int i=1 ; i<=n ; i++) if(fp(i) == fp(i+n))
        {
            printf("PARADOX\n");
            goto out;
        }
        printf("NOT PARADOX\n");
        out: ;
    }
    return 0;
}
