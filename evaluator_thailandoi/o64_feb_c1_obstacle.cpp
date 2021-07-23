#include "obstacle.h"
#include <bits/stdc++.h>
using namespace std;

int _N;
vector<vector<int>> st, ts, dp;

void initialize(int N, int M, int Q, vector<vector<int>>& rowlen, vector<vector<int>>& collen)
{
	_N = N;
	for(int i=0 ; i<N ; i++)
	{
		vector<int> row;
		if(!i)
		{
			for(int j=0 ; j<M ; j++)
			{
				if(!j)
				{
					row.push_back(0);
				}
				else
				{
					row.push_back(row.back() + rowlen[0][j-1]);
				}
			}
		}
		else
		{
			for(int j=0 ; j<M ; j++)
			{
				if(!j)
				{
					row.push_back(st[i-1][0] + collen[i-1][0]);
				}
				else
				{
					row.push_back(min(st[i-1][j] + collen[i-1][j], row.back() + rowlen[i][j-1]));
				}
			}

		}
		st.push_back(row);
	}
	for(auto &x : rowlen)
		reverse(x.begin(), x.end());
	reverse(rowlen.begin(), rowlen.end());
	for(auto &x : collen)
		reverse(x.begin(), x.end());
	reverse(collen.begin(), collen.end());
	for(int i=0 ; i<N ; i++)
	{
		vector<int> row;
		if(!i)
		{
			for(int j=0 ; j<M ; j++)
			{
				if(!j)
				{
					row.push_back(0);
				}
				else
				{
					row.push_back(row.back() + rowlen[0][j-1]);
				}
			}
		}
		else
		{
			for(int j=0 ; j<M ; j++)
			{
				if(!j)
				{
					row.push_back(ts[i-1][0] + collen[i-1][0]);
				}
				else
				{
					row.push_back(min(ts[i-1][j] + collen[i-1][j], row.back() + rowlen[i][j-1]));
				}
			}

		}
		ts.push_back(row);
	}
	for(auto &x : ts)
		reverse(x.begin(), x.end());
	reverse(ts.begin(), ts.end());
	for(int i=0 ; i<N ; i++)
	{
		vector<int> row;
		for(int j=0 ; j<M ; j++)
			row.push_back(st[i][j] + ts[i][j]);
		dp.push_back(row);
	}
	for(int i=0 ; i<N ; i++)
		for(int j=1 ; j<M ; j++)
			dp[i][j] = min(dp[i][j], dp[i][j-1]);
	for(int j=0 ; j<M ; j++)
		for(int i=N-2 ; i>=0 ; i--)
			dp[i][j] = min(dp[i][j], dp[i+1][j]);
}

int ask(int r, int c)
{
	return (r == _N-1 || c == 0) ? -1 : dp[r+1][c-1];
}
