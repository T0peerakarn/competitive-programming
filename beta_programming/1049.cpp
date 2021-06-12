#include <bits/stdc++.h>
using namespace std;

struct runner
{
	int no, lane, speed;
	bool operator < (const runner & o) const
	{
		return (speed == o.speed) ? lane > o.lane : speed < o.speed;
	}
};

int cnt[10005];
priority_queue<runner> heap[100005];

int main()
{
	int n, m;
	scanf(" %d %d",&n,&m);
	while(n--)
	{
		int a, l, s;
		scanf(" %d %d %d",&a,&l,&s);
		heap[++cnt[l]].push({a, l, s});
	}
	for(int i=1 ; true ; i++)
	{
		if(heap[i].empty()) break;
		printf("%d\n",heap[i].top().no);
	}
	return 0;
}
