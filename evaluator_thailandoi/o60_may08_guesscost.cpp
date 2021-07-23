#include <bits/stdc++.h>
using namespace std;

int c[303], dp[303][303];

int opt(int i, int j)
{
	if(dp[i][j] != -1) return dp[i][j];
	if(i == j) return dp[i][j] = c[i];
	if(i+1 == j) return dp[i][j] = c[i] + c[j];
	int v = c[i+1] + max(opt(i, i), opt(i+2, j));
	for(int k=i+2 ; k<j ; k++)
		v = min(v, c[k] + max(opt(i, k-1), opt(k+1, j)));
	return dp[i][j] = v;
}

int main()
{
	int n;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++)
		scanf(" %d",&c[i]);
	memset(dp, -1, sizeof dp);
	printf("%d\n",opt(1, n));
	return 0;
}
