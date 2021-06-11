#include <bits/stdc++.h>
using namespace std;

int qs[1010];

int max(int a, int b, int c)
{
	return max(a, max(b, c));
}

int min(int a, int b, int c)
{
	return min(a, min(b, c));
}

int main()
{
	int n;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++)
	{
		scanf(" %d",&qs[i]);
		qs[i] += qs[i-1];
	}
	int dif = 1e9, a, b;
	for(int i=1 ; i<=n ; i++)
		for(int j=i+1 ; j<=n ; j++)
			if(max(qs[i], qs[j]-qs[i], qs[n]-qs[j]) - min(qs[i], qs[j]-qs[i], qs[n]-qs[j]) < dif)
			{
				dif = max(qs[i], qs[j]-qs[i], qs[n]-qs[j]) - min(qs[i], qs[j]-qs[i], qs[n]-qs[j]);
				a = i, b = j;
			}
	printf("%d %d\n",a+1,b+1);
	return 0;
}
