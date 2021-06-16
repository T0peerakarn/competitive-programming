#include <bits/stdc++.h>
using namespace std;

int pa[30];
vector<double> dis[30][30];
vector<int> g[30];
map<char, int> mp;
map<int, char> rev;
bool edge[30][30];

int fp(int u) {return (u == pa[u]) ? u : pa[u] = fp(pa[u]);}

void dfs(int u, int p, double w)
{
	if(u == 27)
	{
		printf("%.1lf\n",w);
		return ;
	}
	for(auto x : g[u])
	{
		if(x == p) continue;
		sort(dis[u][x].begin(), dis[u][x].end());
		int sz = dis[u][x].size();
		double nw = (sz%2) ? dis[u][x][sz/2] : (dis[u][x][sz/2-1] + dis[u][x][sz/2])/2;
		printf("%c %c %.1lf\n",rev[u],rev[x],nw);
		dfs(x, u, w+nw);
	}
}

int main()
{
	mp['X'] = 0;
	rev[0] = 'X';
	mp['Y'] = 27;
	rev[27] = 'Y';
	pa[27] = 27;
	for(int i=1 ; i<=26 ; i++)
	{
		pa[i] = i;
		mp['a'+i-1] = i;
		rev[i] = 'a'+i-1;
	}
	int n;
	scanf(" %d",&n);
	while(n--)
	{
		char a, b;
		double v;
		scanf(" %c %c %lf",&a,&b,&v);
		if(!edge[mp[a]][mp[b]])
		{
			edge[mp[a]][mp[b]] = edge[mp[b]][mp[a]] = true;
			g[mp[a]].push_back(mp[b]);
			g[mp[b]].push_back(mp[a]);
		}
		pa[fp(mp[a])] = fp(mp[b]);
		dis[mp[a]][mp[b]].push_back(v);
		dis[mp[b]][mp[a]].push_back(v);
	}
	if(fp(0) != fp(27))
	{
		printf("broken\n");
		return 0;
	}
	dfs(0, -1, 0);
	return 0;
}
