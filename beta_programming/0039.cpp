#include <bits/stdc++.h>
using namespace std;

bool food[10], mark[10];
vector<int> ans;

void permute(int now, int n)
{
	if(now == n)
	{
		for(auto x : ans)
			printf("%d ",x);
		printf("\n");
		return ;
	}
	for(int i=1 ; i<=n ; i++)
	{
		if(mark[i]) continue;
		if(now == 0 && food[i]) continue ;
		mark[i] = true;
		ans.push_back(i);
		permute(now+1, n);
		mark[i] = false;
		ans.pop_back();
	}
}

int main()
{
	int n, m;
	scanf(" %d %d",&n,&m);
	while(m--)
	{
		int d;
		scanf(" %d",&d);
		food[d] = true;
	}
	permute(0, n);
	return 0;
}
