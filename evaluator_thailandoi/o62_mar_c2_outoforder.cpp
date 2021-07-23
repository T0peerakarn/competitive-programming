#include <bits/stdc++.h>
using namespace std;

#define N 100005

struct DATA
{
	int h, i, l, r;
	bool operator < (const DATA & o) const
	{
		return h < o.h;
	}
};

int h[N], d[N];
long long fw[N];
vector<DATA> v;

void update(int i, int n, long long v)
{
	while(i <= n)
	{
		fw[i] += v;
		i += -i&i;
	}
}

long long query(int i)
{
	long long ret = 0;
	while(i)
	{
		ret += fw[i];
		i -= -i&i;
	}
	return ret;
}

void fill_fenwick(int n)
{
	for(int i=1 ; i<=n ; i++)
		update(i, n, 1);
}

int main()
{
	int n;
	long long ans = 0;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++)
		scanf(" %d",&h[i]);
	for(int i=1 ; i<=n ; i++)
	{
		int d;
		scanf(" %d",&d);
		v.push_back({h[i], i, max(1, i-d), min(n, i+d)});
	}

	fill_fenwick(n);
	sort(v.begin(), v.end());
	for(int i=0 ; i<n ; i++)
	{
		update(v[i].i, n, -1);
		ans += query(v[i].i) - query(v[i].l-1);
	}

	fill_fenwick(n);
	reverse(v.begin(), v.end());
	for(int i=0 ; i<n ; i++)
	{
		update(v[i].i, n, -1);
		ans += query(v[i].r) - query(v[i].i);
	}

	printf("%lld\n",ans);
	return 0;
}
