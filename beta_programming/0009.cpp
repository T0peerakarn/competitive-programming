#include <bits/stdc++.h>
using namespace std;

map<char, int> mp;

int main()
{
	vector<int> v(3);
	for(auto &x : v)
		scanf(" %d",&x);
	sort(v.begin(), v.end());
	for(int i=0 ; i<3 ; i++)
		mp['A'+i] = v[i];
	for(int i=0 ; i<3 ; i++)
	{
		char c;
		scanf(" %c",&c);
		printf("%d ",mp[c]);
	}
	return 0;
}
