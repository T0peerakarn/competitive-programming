#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n, k, past = 0;
    cin >> n >> k;
    for(int i=0 ; i<n ; i++)
    {
        cout << (i^past) << endl;
        int ret;
        cin >> ret;
        if(ret == 1) return ;
        past = i;
    }
}
 
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
