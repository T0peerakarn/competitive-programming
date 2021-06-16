#include <bits/stdc++.h>
using namespace std;

struct frame
{
	int si, sj, ei, ej;
};

int main()
{
	int n, m;
	scanf(" %d %d",&n,&m);
	vector<frame> v(n);
	for(auto &x : v) scanf(" %d %d %d %d",&x.si,&x.ej,&x.ei,&x.sj);
	while(m--)
	{
		int si, sj, ei, ej, ans = 0;
		scanf(" %d %d %d %d",&si,&ej,&ei,&sj);
		for(auto x : v)
		{
			if(x.ei <= si || ei <= x.si) continue;
			if(x.ej <= sj || ej <= x.sj) continue;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
