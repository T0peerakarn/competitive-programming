#include <bits/stdc++.h>
using namespace std;

int val[1010];
bool mark[1010];

int main()
{
	int n, ans = 0;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++) scanf(" %d",&val[i]);
	for(int i=1 ; i<=n/2 ; i++)
	{
		vector<pair<int, int>> v;
		for(int j=1 ; j<=n ; j++) if(!mark[j]) v.push_back({j, val[j]});
		int mx = 0, a, b, sz = v.size();
		for(int j=1 ; j<sz ; j++)
			if(abs(v[j].second - v[j-1].second) > mx)
			{
				mx = abs(v[j].second - v[j-1].second);
				a = v[j-1].first, b = v[j].first;
			}
		ans += mx;
		mark[a] = mark[b] = true;
	}
	printf("%d\n",ans);
	return 0;
}
