#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf(" %d",&n);
	int r = n, c = (n%2) ? n : n-1;
	int mid = c/2+1;
	for(int i=1 ; i<=r ; i++)
	{
		int ii = (i <= (r+1)/2) ? i : r - i + 1;
		for(int j=1 ; j<=c ; j++)
		{
			if(j == mid-ii+1 || j == mid+ii-1) printf("*");
			else printf("-");
		}
		printf("\n");
	}
	return 0;
}
