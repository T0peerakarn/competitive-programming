#include <bits/stdc++.h>
using namespace std;

struct computer
{
	int id, x;
	bool operator < (const computer & o) const
	{
		return x < o.x;
	}
};

int pa[100100];
computer arr[100100];

int fp(int u) {return (u == pa[u]) ? u : pa[u] = fp(pa[u]);}

int main()
{
	int n;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++)
	{
		int d;
		scanf(" %d",&d);
		arr[i] = {i, d};
		pa[i] = i;
	}
	sort(arr+1, arr+n+1);
	for(int i=1 ; i<=n-2 ; i++)
	{
		int u, v;
		scanf(" %d %d",&u,&v);
		pa[fp(u)] = fp(v);
	}
	int ans = 1e9;
	for(int i=2 ; i<=n ; i++)
		if(fp(arr[i-1].id) != fp(arr[i].id)) ans = min(ans, arr[i].x - arr[i-1].x);
	printf("%d\n",ans);
	return 0;
}
