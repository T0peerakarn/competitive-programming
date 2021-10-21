#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n)
{
    vector<int> v;
    while(n)
    {
        v.push_back(n%10);
        n /= 10;
    }
    for(int i=0 ; i<v.size() ; i++) if(v[i] != v[v.size()-i-1]) return false;
    return true;
}

int main()
{
    int ans = 0;
    for(int i=100 ; i<1000 ; i++) for(int j=100 ; j<1000 ; j++) if(isPalindrome(i*j)) ans = max(ans, i*j);
    cout << ans << endl;
    return 0;
}

// 906609
