#include <bits/stdc++.h>
using namespace std;

char num[1000005];

int main()
{
	scanf(" %s",num);
	int n = strlen(num);
	int s3 = 0, s11 = 0;
	for(int i=0 ; i<n ; i++)
	{
		s3 *= 10;
		s3 += (num[i] - '0');
		s3 %= 3;
		s11 *= 10;
		s11 += (num[i] - '0');
		s11 %= 11;
	}
	printf("%d %d\n",s3,s11);
	return 0;
}
