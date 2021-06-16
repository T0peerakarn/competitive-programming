#include <bits/stdc++.h>
using namespace std;

char a[130], b[130], c[130];

int main()
{
	int n, m;
	scanf(" %d %d",&n,&m);
	scanf(" %s %s %s",a,b,c);
	for(int i=0 ; i<m ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			vector<char> v = {a[j], b[j], c[i]};
			sort(v.begin(), v.end());
			c[i] = v[1];
		}
		printf("%c",c[i]);
	}
	return 0;
}
