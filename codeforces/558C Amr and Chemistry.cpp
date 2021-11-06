#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5+5;
 
int opr[N], visit[N], tmp_opr[N], tmp_visit[N];
 
int main()
{
    int n;
    scanf(" %d",&n);
    for(int i=0 ; i<n ; i++)
    {
        int d;
        scanf(" %d",&d);
        queue<int> cleaner;
        for(int i=0, j=d ; j>0 ; i+=1, j/=2)
        {
            int tmp = j, cnt = i;
            while(tmp <= 100000)
            {
                
                if(tmp_visit[tmp]) tmp_opr[tmp] = min(tmp_opr[tmp], cnt);
                else
                {
                    cleaner.push(tmp);
                    tmp_visit[tmp] = true;
                    tmp_opr[tmp] = cnt;
                }
                tmp *= 2;
                cnt += 1;
            }
        }
        while(!cleaner.empty())
        {
            int v = cleaner.front();
            cleaner.pop();
            opr[v] += tmp_opr[v];
            visit[v] += 1;
            tmp_opr[v] = tmp_visit[v] = 0;
        }
    }
    int mn = 1e9;
    for(int i=1 ; i<=100000 ; i++) if(visit[i] == n) mn = min(mn, opr[i]);
    printf("%d\n",mn);
    return 0;
}
