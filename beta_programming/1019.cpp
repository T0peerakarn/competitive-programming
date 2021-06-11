#include <bits/stdc++.h>
using namespace std;

int dp[205][205], bt[205][205];
char a[205], b[205];

int main()
{
	scanf(" %s %s",a+1,b+1);
	int la = strlen(a+1), lb = strlen(b+1), mx = 0;
	for(int i=1 ; i<=la ; i++)
		for(int j=1 ; j<=lb ; j++)
			if(a[i] == b[j])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
				mx = max(mx, dp[i][j]);
			}
	for(int i=1 ; i<=la ; i++)
		for(int j=1 ; j<=lb ; j++)
			if(dp[i][j] == mx)
			{
				for(int k=i-mx+1 ; k<=i ; k++) printf("%c",a[k]);
				return 0;
			}
	return 0;
}
