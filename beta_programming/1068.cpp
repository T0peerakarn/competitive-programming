#include <bits/stdc++.h>
using namespace std;

int hori[105][105], vert[105][105];
priority_queue<int> heap;

int compute(int i, int j)
{
	return 3*hori[i][j] + 5*vert[i][j] - 3*hori[i+1][j] - 5*vert[i][j+1];
}

int main()
{
	int n, k, ans = 0;
	scanf(" %d %d",&n,&k);
	for(int i=1 ; i<=n ; i++)
	{
		for(int j=1 ; j<=n ; j++) scanf(" %d",&hori[i][j]);
		for(int j=1 ; j<=n+1 ; j++) scanf(" %d",&vert[i][j]);
	}
	for(int j=1 ; j<=n ; j++) scanf(" %d",&hori[n+1][j]);
	for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=n ; j++) heap.push({-compute(i, j)});
	while(!heap.empty() && k--)
	{
		ans += -heap.top();
		heap.pop();
	}
	printf("%d\n",ans);
	return 0;
}
