#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<char, char>> A[110], C[110];
bool state[20], ans;

void Init()
{
	for(int i=1 ; i<=100 ; i++)
	{
		A[i].clear();
		C[i].clear();
	}
	ans = true;
}

bool compute_A()
{
	for(int i=1 ; i<=n ; i++)
	{
		for(auto x : A[i])
		{
			bool now = state[x.second - 'a'];
			if(x.first == '-') now ^= true;
			if(now) goto out;
		}
		return false;
		out: ;
	}
	return true;
}

bool compute_C()
{
	for(int i=1 ; i<=m ; i++)
	{
		for(auto x : C[i])
		{
			bool now = state[x.second - 'a'];
			if(x.first == '-') now ^= true;
			if(now) goto out;
		}
		return false;
		out: ;
	}
	return true;
}

void gen(int now, int des)
{
	if(now == des)
	{
		bool sA = compute_A(), sC = compute_C();
		if(sA && !sC) ans = false;
		return ;
	}
	state[now] = false;
	gen(now+1, des);
	state[now] = true;
	gen(now+1, des);
}

int main()
{
	int q;
	scanf(" %d",&q);
	while(q--)
	{
		Init();
		scanf(" %d %d",&n,&m);
		for(int i=1 ; i<=n ; i++)
		{
			int d;
			scanf(" %d",&d);
			while(d--)
			{
				char a, b;
				scanf(" %c %c",&a,&b);
				A[i].push_back({a, b});
			}
		}
		for(int i=1 ; i<=m ; i++)
		{
			int d;
			scanf(" %d",&d);
			while(d--)
			{
				char a, b;
				scanf(" %c %c",&a,&b);
				C[i].push_back({a, b});
			}
		}
		gen(0, 16);
		printf((ans) ? "YES\n" : "NO\n");
	}
	return 0;
}
