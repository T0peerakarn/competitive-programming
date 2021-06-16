#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf(" %d",&n);
	vector<int> v(n);
	for(auto &x : v) scanf(" %d",&x);
	sort(v.begin(), v.end());
	if(n >= 3 && v[0] + v[1] <= v[n-1])
	{
		printf("yes\n");
		return 0;
	}
	printf("no\n");
	return 0;
}
