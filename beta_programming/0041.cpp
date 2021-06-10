#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	double ans = 0;
	scanf(" %d",&n);
	if(n == 1) ans = 2;
	else if(n == 3) ans = 2 + sqrt(3);
	else if(n%2 == 0) ans = n;
	else
	{
		n -= 5;
		ans = 2*(1+sqrt(3))+n;
	}
	printf("%lf\n",ans);
	return 0;
}
