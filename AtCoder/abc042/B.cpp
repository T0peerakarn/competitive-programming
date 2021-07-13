#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l;
    scanf(" %d %d",&n,&l);
    vector<string> v(n);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    for(auto x : v) cout << x;
    return 0;
}
