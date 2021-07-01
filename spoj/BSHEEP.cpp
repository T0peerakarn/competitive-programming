#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

struct point
{
	int x, y, no;
};

point p[N], stk[N];

int direction(point a, point b, point c)
{
	// -1 -> left
	//  0 -> linear
	//  1 -> right
	return (b.y-a.y)*(c.x-b.x) - (c.y-b.y)*(b.x-a.x);
}

double distance(point a, point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

bool compare(point a, point b)
{
	int di = direction(p[1], a, b);
	return (di == 0) ? distance(p[1], a) < distance(p[1], b) : di < 0;
}

void solve()
{
	int n, cnt = 0;
	scanf(" %d",&n);
	map<pair<int, int>, int> mp;
	for(int i=1 ; i<=n ; i++)
	{
		int x, y;
		scanf(" %d %d",&x,&y);
		if(mp.count({x, y})) continue;
		mp[{x, y}] = 1;
		p[++cnt] = {x, y, i};
	}
	for(int i=2 ; i<=cnt ; i++)
	{
		if(p[i].y < p[1].y) swap(p[i], p[1]);
		else if(p[i].y == p[1].y && p[i].x < p[1].x) swap(p[i], p[1]);
	}
	sort(p+2, p+cnt+1, compare);
	stk[1] = p[1];
	int sz = 1;
	for(int i=2 ; i<=cnt ; i++)
	{
		while(sz >= 2 && direction(stk[sz-1], stk[sz], p[i]) >= 0) sz--;
		stk[++sz] = p[i];
	}
	double tot = distance(stk[1], stk[sz]);
	for(int i=2 ; i<=sz ; i++) tot += distance(stk[i-1], stk[i]);
	printf("%.2lf\n",tot);
	for(int i=1 ; i<=sz ; i++) printf("%d ",stk[i].no);
	printf("\n");
}

int main()
{
	int q;
	scanf(" %d",&q);
	while(q--) solve();		
	return 0;
}
