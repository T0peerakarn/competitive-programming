#include <bits/stdc++.h>
using namespace std;

int pa[200005], a[200005], b[200005];

int fp(int u) {return (u == pa[u]) ? u : pa[u] = fp(pa[u]);}

int main()
{
	for(int i=1 ; i<=200000 ; i++) pa[i] = i;
	int n;
	scanf(" %d",&n);
	for(int i=1 ; i<=n/2 ; i++) scanf(" %d",&a[i]);
	if(n&1) scanf(" %d",&b[1]);
	for(int i=n/2 ; i>=1 ; i--) scanf(" %d",&b[i]);
	int ans = 0;
	for(int i=1 ; i<=n/2 ; i++)
	{
		int u = fp(a[i]), v = fp(b[i]);
		if(u != v)
		{
			ans++;
			pa[u] = v;
		}
	}
	printf("%d\n",ans);
	return 0;
}
