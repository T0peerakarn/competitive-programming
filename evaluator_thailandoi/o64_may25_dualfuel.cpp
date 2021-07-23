#include <bits/stdc++.h>
#include "dual.h"
using namespace std;

long long dual_fuel(int n,int v, vector<int> &a, vector<int> &b)
{
	long long sa = 0, sb = 0;
	deque<pair<long long, int>> swa, swb;
	for(int i=0 ; i<n ; i++)
	{
		while(!swa.empty() && swa.front().second < i) swa.pop_front();
		while(!swa.empty() && swa.back().first >= a[i]) swa.pop_back();
		swa.push_back({a[i], i+v-1});
		sa += swa.front().first;

		while(!swb.empty() && swb.front().second < i) swb.pop_front();
		while(!swb.empty() && swb.back().first >= b[i]) swb.pop_back();
		swb.push_back({b[i], i+v-1});
		sb += swb.front().first;
	}
	return sa + sb;
}
