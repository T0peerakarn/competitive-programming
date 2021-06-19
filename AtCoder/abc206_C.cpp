#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	v.push_back(2e9);
	int last = 0;
	long long ans = 0;
	for(int i=1 ; i<n ; i++)
		if(v[i] != v[i-1])
		{
			ans += (long long)(i-last) * (long long)(n-i);
			last = i;
		}
	cout << ans;
	return 0;
}
