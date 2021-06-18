#include <bits/stdc++.h>
using namespace std;

int ans[200002];

int main()
{
	int n;
	scanf(" %d",&n);
	vector<pair<int, int>> v;
	for(int i=1 ; i<=n ; i++)
	{
		int d;
		scanf(" %d",&d);
		v.push_back({d, i});
	}
	sort(v.begin(), v.end());
	for(int i=0 ; i<n ; i++) ans[v[i].second] = (i < n/2) ? v[n/2].first : v[n/2-1].first;
	for(int i=1 ; i<=n ; i++) printf("%d\n",ans[i]);
	return 0;
}
