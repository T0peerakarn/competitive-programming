#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf(" %d",&n);
	vector<int> v(n);
	for(auto &x : v) scanf(" %d",&x);
	sort(v.begin(), v.end());
	int d = v[0];
	for(int i=1 ; i<n-1 ; i++) if(abs(d-(v[n-1]+1)/2) > abs(v[i]-(v[n-1]+1)/2)) d = v[i];
	printf("%d %d\n",v[n-1],d);
	return 0;
}
