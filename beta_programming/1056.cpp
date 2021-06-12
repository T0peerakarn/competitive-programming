#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	scanf(" %d %d",&n,&k);
	vector<int> v(n);
	for(auto &x : v) scanf(" %d",&x);
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int ans = 0;
	for(int i=0 ; i<n ; i+=k) ans += v[i];
	printf("%d\n",ans);
	return 0;
}
