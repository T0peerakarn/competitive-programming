#include "rumors.h"
#include <bits/stdc++.h>
using namespace std;

int dis[2020][2020], dp[2020][2020];

int compute(int i, int j, int k)
{
	if(i > j) swap(i, j);
	return (j-i <= k) ? 0 : ((j-i)%k == 0 ? (j-i-k)/k : (j-i-k)/k + 1);
}

vector<int> analyze_rumors(int N, int K, int Q, vector<int> D, vector<int> X, vector<int> J)
{
	for(int i=0 ; i<N ; i++)
	{
		int reporter = 0;
		for(int j=i+1 ; j<N ; j++)
		{
			reporter += compute(D[j-1], D[j], K);
			dis[i][j] = reporter;
		}
	}
	
	for(int sz=2 ; sz<=N ; sz++)
	{
		deque<pair<int, int>> sw;
		for(int i=0 ; i<N ; i++)
		{
			int j=i+sz	-1;
			while(!sw.empty() && sw.front().first < i) sw.pop_front();
			if(j < N)
			{
				while(!sw.empty() && sw.back().second >= dis[i][j]) sw.pop_back();
				sw.push_back({j, dis[i][j]});
			}
			dp[sz][i] = sw.front().second;
		}
	}

	for(int j=0 ; j<N ; j++)
		for(int i=N-1 ; i>=1 ; i--)
			dp[i][j] = min(dp[i][j], dp[i+1][j]);

	vector<int> ans;
	for(int i=0 ; i<Q ; i++)
	{
		int l=0, r=N;
		while(l != r)
		{
			int mid = (l+r+1)>>1;
			(dp[mid][X[i]] <= J[i]) ? l = mid : r = mid-1;
		}
		ans.push_back(l);
	}
	return ans;
}
