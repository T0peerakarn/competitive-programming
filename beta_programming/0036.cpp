#include <bits/stdc++.h>
using namespace std;

long long ncr[30][30];

int main()
{
	for(int i=0 ; i<=25 ; i++)
	{
		ncr[i][0] = 1;
		for(int j=1 ; j<=i ; j++)
			ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
	}
	int n;
	scanf(" %d",&n);
	printf("%lld\n",ncr[n][n/2]*(n%2 ? 2 : 1));
	return 0;
}
