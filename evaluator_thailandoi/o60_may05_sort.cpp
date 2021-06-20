#include "sort_weight.h"
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<int> tmp;
int cnt[5][5];
bool mark[5], error[130];

void permute(int now, int n)
{
	if(now == n)
	{
		v.push_back(tmp);
		return;
	}
	for(int i=0 ; i<n ; i++)
	{
		if(mark[i]) continue;
		mark[i] = 1;
		tmp.push_back(i);
		permute(now+1, n);
		mark[i] = 0;
		tmp.pop_back();
	}
}

void Count()
{
	memset(cnt, 0, sizeof cnt);
	for(int i=0 ; i<120 ; i++)
	{
		if(error[i]) continue;
		for(int j=0 ; j<5 ; j++)
			for(int k=j+1 ; k<5 ; k++)
				cnt[v[i][j]][v[i][k]]++;
	}
}

void Search(int &a, int &b, int del)
{
	for(int i=0 ; i<5 ; i++)
		for(int j=0 ; j<5 ; j++)
		{
			if(i == j) continue;
			if(cnt[i][j] + cnt[j][i] == 120-del && abs(cnt[i][j] - cnt[j][i])<=1)
			{
				a = i, b = j;
				return;
			}
		}
}

void Update(int a, int b, int &del)
{
	for(int i=0 ; i<120 ; i++)
	{
		if(error[i]) continue;
		for(auto x : v[i])
		{
			if(x == b)
			{
				error[i] = true;
				del++;
				break;
			}
			if(x == a) break;
		}
	}
}

int main()
{
	permute(0, 5);
	int t = get_case();
	while(t--)
	{
		sort_init();
		memset(error, false, sizeof error);
		int del = 0;
		for(int i=0 ; i<7 ; i++)
		{
			Count();
			int a, b;
			Search(a, b, del);
			if(sort_weight(a, b) == -1) swap(a, b);
			Update(a, b, del);
		}
		vector<int> now;
		for(int i=0 ; i<120 ; i++)
			if(!error[i]) now = v[i];
		sort_answer(now[4], now[3], now[2], now[1], now[0]);
	}
	return 0;
}
