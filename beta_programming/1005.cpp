#include <bits/stdc++.h>
using namespace std;

int arr[3000];

int main()
{
	int n;
	bool valid = false;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++)
	{
		scanf(" %d",&arr[i]);
		if(arr[i] > 0) valid = true;
	}
	if(!valid) printf("Empty sequence\n");
	else
	{
		int mx = 0, l, r;
		for(int i=1 ; i<=n ; i++)
		{
			int sum = 0;
			for(int j=i ; j<=n ; j++)
			{
				sum += arr[j];
				if(sum > mx)
				{
					mx = sum;
					l = i, r = j;
				}
			}
		}
		for(int i=l ; i<=r ; i++)
			printf("%d ",arr[i]);
		printf("\n%d\n",mx);
	}
	return 0;
}
