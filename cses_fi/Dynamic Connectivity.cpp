#include <bits/stdc++.h>
using namespace std;

#define N 100005

int component;
int pa[N], sz[N], u[N<<2], v[N<<2], o[N<<2], ans[N<<2];
stack<int> rb;
map<pair<int, int>, int> mp;

int Find(int u)
{
	while(u != pa[u]) u = pa[u];
	return u;
}

void Union(int u, int v)
{
	u = Find(u), v = Find(v);
	if(u == v) return ;
	if(sz[u] > sz[v]) swap(u, v);
	sz[v] += sz[u];
	pa[u] = v;
	component--;
	rb.push(u);
}

void Rollback(int init)
{
	int now = rb.size();
	while(now > init)
	{
		int u = rb.top();
		rb.pop();
		now--;
		sz[pa[u]] -= sz[u];
		pa[u] = u;
		component++;
	}
}

void Solve(int l, int r)
{
	if(l == r)
	{
		if(l < o[l]) Union(u[l], v[l]);
		ans[l] = component; 
		return ;
	}
	int mid = (l+r)>>1, now = rb.size();
	for(int i=mid+1 ; i<=r ; i++) if(o[i] < l) Union(u[i], v[i]);
	Solve(l, mid);
	Rollback(now);
	for(int i=l ; i<=mid ; i++) if(r < o[i]) Union(u[i], v[i]);
	Solve(mid+1, r);
	Rollback(now);
}

int main()
{
	int n, m, q;
	scanf(" %d %d %d",&n,&m,&q);
	component = n;
	for(int i=1 ; i<=n ; i++)
	{
		pa[i] = i;
		sz[i] = 1;
	}
	for(int i=1 ; i<=m ; i++)
	{
		scanf(" %d %d",&u[i],&v[i]);
		if(u[i] > v[i]) swap(u[i], v[i]);
		if(mp.count({u[i], v[i]}))
		{
			o[i] = mp[{u[i], v[i]}];
			o[o[i]] = i;
			mp.erase({u[i], v[i]});
		}
		else mp[{u[i], v[i]}] = i;
	}
	for(int i=m+1 ; i<=m+q ; i++)
	{
		int tmp;
		scanf(" %d %d %d",&tmp,&u[i],&v[i]);
		if(u[i] > v[i]) swap(u[i], v[i]);
		if(mp.count({u[i], v[i]}))
		{
			o[i] = mp[{u[i], v[i]}];
			o[o[i]] = i;
			mp.erase({u[i], v[i]});
		}
		else mp[{u[i], v[i]}] = i;
	}
	int qq = m+q;
	for(auto it : mp)
	{
		qq++;
		tie(u[qq], v[qq]) = it.first;
		o[it.second] = qq;
		o[qq] = it.second;
	}
	Solve(1, qq);
	for(int i=m ; i<=m+q ; i++) printf("%d ",ans[i]);
	return 0;
}
