#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, x;
	scanf(" %d %d %d",&a,&b,&x);
	printf((a <= x && a+b >= x) ? "YES\n" : "NO\n");
	return 0;
}
