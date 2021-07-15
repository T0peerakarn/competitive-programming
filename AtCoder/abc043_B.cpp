#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<char> ans;
    string str;
    getline(cin, str);
    for(char c : str)
    {
        if(c == 'B') {if(!ans.empty()) ans.pop_back();}
        else ans.push_back(c);
    }
    while(!ans.empty())
    {
        printf("%c",ans.front());
        ans.pop_front();
    }
    return 0;
}
