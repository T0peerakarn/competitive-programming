#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf(" %d",&n);
	vector<int> v(n);
	for(auto &x : v)
		scanf(" %d",&x);
	sort(v.begin(), v.end());
	int f;
	for(auto x : v)
		if(x != 0)
		{
			f = x;
			break;
		}	
	printf("%d",f);
	for(auto x : v)
	{
		if(x == f)
		{
			f = -1;
			continue;
		}
		printf("%d",x);
	}
	return 0;
}
