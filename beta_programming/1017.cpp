#include <bits/stdc++.h>
using namespace std;

int arr[15][15];
bool mark[100];

int main()
{
	int n, total = 0, sum;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=n ; j++)
		{
			scanf(" %d",&arr[i][j]);
			if(mark[arr[i][j]])
			{
				printf("No\n");
				return 0;
			}
			mark[arr[i][j]] = true;
			total += arr[i][j];
		}

	if(total%n)
	{
		printf("No\n");
		return 0;
	}
	total /= n;

	for(int i=1; i<=n ; i++)
	{
		sum = 0;
		for(int j=1 ; j<=n ; j++) sum += arr[i][j];
		if(sum != total)
		{
			printf("No\n");
			return 0;
		}

		sum = 0;
		for(int j=1 ; j<=n ; j++) sum += arr[j][i];
		if(sum != total)
		{
			printf("No\n");
			return 0;
		}
	}

	sum = 0;
	for(int i=1 ; i<=n ; i++) sum += arr[i][i];
	if(sum != total)
	{
		printf("No\n");
		return 0;
	}

	sum = 0;
	for(int i=1 ; i<=n ; i++) sum += arr[i][n-i+1];
	if(sum != total)
	{
		printf("No\n");
		return 0;
	}
	
	printf("Yes\n");
	return 0;
}
