#include <bits/stdc++.h>
using namespace std;

char num[1005];

int main()
{
	int n;
	scanf(" %d",&n);
	while(n--)
	{
		scanf(" %s",num);
		int len = strlen(num);
		printf(((num[len-1]-'0')%2 == 1 || (len == 1 && num[0] == '2')) ? "T\n" : "F\n");
	}
	return 0;
}
