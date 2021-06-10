#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v(4);
	for(auto &x : v)
		scanf(" %d",&x);
	sort(v.begin(), v.end());
	printf("%d\n",v[0]*v[2]);
	return 0;
}
