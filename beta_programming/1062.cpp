#include <bits/stdc++.h>
using namespace std;

char a[130], b[130];

int main()
{
	int n, m;
	scanf(" %d %d",&n,&m);
	scanf(" %s %s",a,b);
	for(int i=0 ; i<m ; i++)
	{
		char c;
		scanf(" %c",&c);
		for(int j=0 ; j<n ; j++)
		{
			vector<char> v = {a[j], b[j], c};
			sort(v.begin(), v.end());
			c = v[1];
		}
		printf("%c",c);
	}
	return 0;
}
