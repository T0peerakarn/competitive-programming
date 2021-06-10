#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main()
{
	int n;
	scanf(" %d",&n);
	while(n--)
	{
		string str;
		cin >> str;
		mp[str] = 1;
	}
	for(auto x : mp)
		cout << x.first << endl;
	return 0;
}
