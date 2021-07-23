#include <bits/stdc++.h>
using namespace std;

int size_shop[120005], size_customer[120005], profit[120005], sum[120005];
vector<int> shop[120005], customer[120005];
bool wait[120005];

int main()
{
	int n, m, q;
	scanf(" %d %d %d",&n,&m,&q);
	for(int i=1 ; i<=m ; i++)
	{
		scanf(" %d",&size_shop[i]);
		for(int j=0 ; j<size_shop[i] ; j++)
		{
			int d;
			scanf(" %d",&d);
			size_customer[d]++;
			shop[i].push_back(d);
			customer[d].push_back(i);
		}
		if(size_shop[i] > 800) wait[i] = true;
	}
	for(int i=1 ; i<=n ; i++)
	{
		vector<int> tmp;
		for(auto x : customer[i])
			if(wait[x]) tmp.push_back(x);
		customer[i] = tmp;
	}
	while(q--)
	{
		int op;
		scanf(" %d",&op);
		if(op == 1)
		{
			int a, b;
			scanf(" %d %d",&a,&b);
			if(!wait[a])
			{
				for(auto x : shop[a])
				{
					sum[x] -= profit[a];
					sum[x] += b;
				}
			}
			profit[a] = b;
		}
		else
		{
			int a;
			scanf(" %d",&a);
			int ans = sum[a];
			for(auto x : customer[a])
				ans += profit[x];
			printf("%d\n",ans);
		}
	}
	return 0;
}
