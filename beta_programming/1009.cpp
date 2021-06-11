#include <bits/stdc++.h>
using namespace std;

string x, str[6];

int compute(int i, int j)
{
	if(str[i+1][j+2] == '|' && str[i+2][j+2] == ' ') return 2;
	if(str[i+1][j+2] == ' ' && str[i+2][j+2] == '|') return (str[i+2][j] == '|') ? 6 : 5;
	if(str[i+1][j] == '|' && str[i+2][j] == ' ') return (str[i][j+1] == '_') ? 9 : 4;
	if(str[i+1][j] == '|' && str[i+2][j] == '|') return (str[i+1][j+1] == '_') ? 8 : 0;
	if(str[i+1][j+1] == '_') return 3;
	return (str[i][j+1] == '_') ? 7 : 1;
}

int main()
{
	int n, m;
	scanf(" %d %d",&n,&m);
	getline(cin, x);
	for(int i=0 ; i<6 ; i++) getline(cin, str[i]);
	long long a = 0, b = 0;
	for(int i=0 ; i<4*n ; i+=4)
	{
		a *= 10;
		a += compute(0, i);
	}
	for(int i=0 ; i<4*m ; i+=4)
	{
		b *= 10;
		b += compute(3, i);
	}
	printf("%lld\n",a+b);
	return 0;
}
