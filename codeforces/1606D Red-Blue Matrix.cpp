#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;

char ans[N];

void solve()
{
    vector<vector<int>> v;
    int n, m;
    scanf(" %d %d",&n,&m);
    for(int i=0 ; i<n ; i++)
    {
        vector<int> tmp;
        for(int j=0 ; j<m ; j++)
        {
            int d;
            scanf(" %d",&d);
            tmp.push_back(d);
        }
        tmp.push_back(i);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    vector<vector<int>> max_tl, min_bl, max_br, min_tr;
    max_tl = min_bl = max_br = min_tr = v;
    for(int j=0 ; j<m ; j++)
    {
        for(int i=0 ; i<n ; i++) 
        {
            if(i-1 >= 0) max_tl[i][j] = max(max_tl[i][j], max_tl[i-1][j]);
            if(j-1 >= 0) max_tl[i][j] = max(max_tl[i][j], max_tl[i][j-1]); 
        }
        for(int i=n-1 ; i>=0 ; i--)
        {
            if(i+1 < n) min_bl[i][j] = min(min_bl[i][j], min_bl[i+1][j]);
            if(j-1 >= 0) min_bl[i][j] = min(min_bl[i][j], min_bl[i][j-1]);
        }
    }
    for(int j=m-1 ; j>=0 ; j--)
    {
        for(int i=0 ; i<n ; i++) 
        {
            if(i-1 >= 0) min_tr[i][j] = min(min_tr[i][j], min_tr[i-1][j]);
            if(j+1 < m) min_tr[i][j] = min(min_tr[i][j], min_tr[i][j+1]); 
        }
        for(int i=n-1 ; i>=0 ; i--)
        {
            if(i+1 < n) max_br[i][j] = max(max_br[i][j], max_br[i+1][j]);
            if(j+1 < m) max_br[i][j] = max(max_br[i][j], max_br[i][j+1]);
        }
    }
    for(int i=1 ; i<n ; i++)
    {
        if(max_tl[i-1][0] >= min_bl[i][0]) continue;
        int k = 0;
        for(int j=0 ; j<m-1 ; j++, k++) if(max_tl[i-1][j] >= min_bl[i][j]) break;
        for(int j=k ; j<m ; j++) if(min_tr[i-1][j] <= max_br[i][j]) goto out;
        for(int j=0 ; j<n ; j++) ans[v[j].back()] = (j < i) ? 'B' : 'R';
        printf("YES\n");
        for(int j=0 ; j<n ; j++) printf("%c",ans[j]);
        printf(" %d\n",k);
        return ; 
        out: ;
    }
    printf("NO\n");
}

int main()
{
    int t;
    scanf(" %d",&t);
    while(t--) solve();
    return 0;
}
