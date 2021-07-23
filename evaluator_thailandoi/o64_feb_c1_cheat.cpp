#include "cheat.h"
#include <bits/stdc++.h>
using namespace std;

int weight = 0;
int sz[200005];
pair<int, int> pa[200005];
bool init = false;

void Initial()
{
	init = true;
	for(int i=1 ; i<=200000 ; i++)
	{
		sz[i] = 1;
		pa[i] = {i, 0};
	}
}

int fp(int u)
{
	while(u != pa[u].first) u = pa[u].first;
	return u;
}

void cheat(int person1, int person2)
{
	if(!init) Initial();
	weight++;
	int p1 = fp(person1), p2 = fp(person2);
	if(p1 == p2) return;
	if(sz[p1] > sz[p2]) swap(p1, p2);
	pa[p1] = {p2, weight};
	sz[p2] += sz[p1];
}

int investigate(int person1, int person2)
{
	if(!init) Initial();
	int l = 0, r = weight+1;
	while(l != r)
	{
		int mid = (l+r)>>1;
		int p1 = person1, p2 = person2;
		while(pa[p1].second != 0 && pa[p1].second <= mid) p1 = pa[p1].first;
		while(pa[p2].second != 0 && pa[p2].second <= mid) p2 = pa[p2].first;
		(p1 == p2) ? r = mid : l = mid+1;
	}
	return (l == weight+1) ? -1 : l;
}
