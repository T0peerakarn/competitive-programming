#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;
	scanf(" %d %d %d",&a,&b,&c);
	if(c%2 == 0) a = abs(a), b = abs(b);
	if(a == b) printf("=\n");
	else printf((a < b) ? "<\n" : ">\n");
	return 0;
}
