#include "guess.h"
#include <bits/stdc++.h>
using namespace std;

char qry[1030];
bool mark[1030];

int find_answer(int N, int K)
{
	if(K == 1)
	{
		if(N == 1024)
		{
			int l=0, r=N-1;
			while(l != r)
			{
				int mid = (l+r)>>1;
				vector<pair<int, char>> v;
				for(int i=0 ; i<=mid ; i++)
					v.push_back({i, 'R'});
				(ask(v) == 'R') ? r = mid : l = mid+1;
			}
			return l;
		}
		else
		{
			int sz = 729;
			while(sz != 1)
			{
				int nr = sz/3, nc = sz/3;
				for(int i=0 ; i<729 ; i++)
				{
					if(mark[i]) continue;
					if(nr == 0 && nc == 0) qry[i] = 'X';
					else if(nr == nc) nr--, qry[i] = 'R';
					else nc--, qry[i] = 'C';
				}
				vector<pair<int, char>> v;
				for(int i=0 ; i<729 ; i++)
				{
					if(mark[i]) continue;
					if(qry[i] == 'R') v.push_back({i, 'R'});
					else if(qry[i] == 'C') v.push_back({i-1, 'R'});
				}
				sort(v.begin(), v.end());
				v.resize(unique(v.begin(), v.end()) - v.begin());
				char ret = ask(v);
				for(int i=0 ; i<729 ; i++)
				{
					if(mark[i]) continue;
					if(qry[i] != ret) mark[i] = true;
				}
				sz /= 3;
			}
			for(int i=0 ; i<729 ; i++)
				if(!mark[i]) return i;
		}
	}
	else
	{
		if(N == 1024)
		{
			int sz = 1024;
			while(sz != 1)
			{
				int nr = sz/4, nb = sz/4, nc = sz/4;
				for(int i=0 ; i<1024 ; i++)
				{
					if(mark[i]) continue;
					if(nr == 0 && nb == 0 && nc == 0) qry[i] = 'X';
					else if(nr) nr--, qry[i] = 'R';
					else if(nb == nc) nb--, qry[i] = 'B';
					else nc--, qry[i] = 'C';
				}
				vector<pair<int, char>> v;
				for(int i=0 ; i<1024 ; i++)
				{
					if(mark[i]) continue;
					if(qry[i] == 'R') v.push_back({i, 'R'});
					else if(qry[i] == 'B') v.push_back({i, 'B'});
					else if(qry[i] == 'C') v.push_back({i-1, 'B'});
				}
				sort(v.begin(), v.end());
				v.resize(unique(v.begin(), v.end()) - v.begin());
				char ret = ask(v);
				for(int i=0 ; i<1024 ; i++)
				{
					if(mark[i]) continue;
					if(qry[i] != ret) mark[i] = true;
				}
				sz /= 4;
			}
			for(int i=0 ; i<1024 ; i++)
				if(!mark[i]) return i;
		}
		else
		{
			int l=0, r=728;
			while(l != r)
			{
				vector<pair<int, char>> v;
				int sz = (r-l+1)/3;
				for(int i=l ; i<l+sz ; i++)
					v.push_back({i, 'R'});
				for(int i=l+sz ; i<l+sz+sz ; i++)
					v.push_back({i, 'B'});
				char ret = ask(v);
				if(ret == 'R') r = l+sz-1;
				else if(ret == 'B') l = l+sz, r = l+sz-1;
				else l = l+sz+sz;
			}
			return l;
		}
	}
	return 0;
}
