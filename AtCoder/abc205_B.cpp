#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf(" %d",&n);
	vector<int> v(n);
	for(auto &x : v) scanf(" %d",&x);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	printf((v.size() == n) ? "Yes\n" : "No\n");
	return 0;
}
