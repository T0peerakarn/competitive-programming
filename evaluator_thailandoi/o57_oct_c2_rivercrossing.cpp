#include <bits/stdc++.h>
using namespace std;

#define N 50005
#define mod 30011

int nl[N], sl[N], nr[N], sr[N], dpl[15][N], dpr[15][N];
vector<int> lh[N], rh[N];

void update_r(int k, int i, int v, int n)
{
	while(i <= n)
	{
		dpr[k][i] += v;
		dpr[k][i] %= mod;
		dpr[k][i] += mod;
		dpr[k][i] %= mod;
		i += -i&i;
	}
}

void update_l(int k, int i, int v, int n)
{
	while(i <= n)
	{
		dpl[k][i] += v;
		dpl[k][i] %= mod;
		dpl[k][i] += mod;
		dpl[k][i] %= mod;
		i += -i&i;
	}
}

int query_r(int k, int i)
{
	int ret = 0;
	while(i)
	{
		ret += dpr[k][i];
		ret %= mod;
		ret += mod;
		ret %= mod;
		i -= -i&i;
	}
	return ret;
}

int query_l(int k, int i)
{
	int ret = 0;
	while(i)
	{
		ret += dpl[k][i];
		ret %= mod;
		ret += mod;
		ret %= mod;
		i -= -i&i;
	}
	return ret;
}

int main()
{
	int n, m, k, l, ans = 0;
	scanf(" %d %d %d %d",&n,&m,&k,&l);
	for(int i=0 ; i<l ; i++)
	{
		int u, v;
		scanf(" %d %d",&u,&v);
		lh[u].push_back(v);
		rh[v].push_back(u);
	}

	for(int i=1 ; i<=n ; i++)
		sort(lh[i].begin(), lh[i].end());
	for(int i=1 ; i<=m ; i++)
		sort(rh[i].begin(), rh[i].end());

	for(int i=1 ; i<=n ; i++)
		scanf(" %d %d",&nl[i],&sl[i]);
	for(int i=1 ; i<=m ; i++)
		scanf(" %d %d",&nr[i],&sr[i]);

	update_l(0, 1, 1, n);
	for(int kk=0 ; kk<=k ; kk++)
	{
		if(kk%2)
		{
			// r -> l
			for(int i=1 ; i<=m ; i++)
			{
				int s = sr[i], lft = nr[i], v = query_r(kk, i);
				ans += v;
				ans %= mod;
				ans += mod;
				ans %= mod;
				for(auto x : rh[i])
				{
					if(x < s) continue;
					if(x - s <= lft)
					{
						lft -= (x-s);
						update_l(kk+1, s, v, n);
						update_l(kk+1, x, -v, n);
						s = x+1;
					}
					else
					{
						update_l(kk+1, s, v, n);
						update_l(kk+1, s+lft, -v, n);
						lft = 0;
						break;
					}
				}
				if(lft)
				{
					update_l(kk+1, s, v, n);
					update_l(kk+1, s+lft, -v, n);
				}
			}
		}
		else
		{
			// l -> r
			for(int i=1 ; i<=n ; i++)
			{
				int s = sl[i], lft = nl[i], v = query_l(kk, i);
				for(auto x : lh[i])
				{
					if(x < s) continue;
					if(x - s <= lft)
					{
						lft -= (x-s);
						update_r(kk+1, s, v, m);
						update_r(kk+1, x, -v, m);
						s = x+1;
					}
					else
					{
						update_r(kk+1, s, v, m);
						update_r(kk+1, s+lft, -v, m);
						lft = 0;
						break;
					}
				}
				if(lft)
				{
					update_r(kk+1, s, v, m);
					update_r(kk+1, s+lft, -v, m);
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
