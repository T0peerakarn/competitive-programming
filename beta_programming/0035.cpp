#include <bits/stdc++.h>
using namespace std;

double x[110], y[110];

double area(int i, int j, int k)
{
	double ret = 0;
	ret += x[i]*y[j];
	ret += x[j]*y[k];
	ret += x[k]*y[i];
	ret -= y[i]*x[j];
	ret -= y[j]*x[k];
	ret -= y[k]*x[i];
	ret = abs(ret);
	ret /= 2;
	return ret;
}

int main()
{
	int n;
	scanf(" %d",&n);
	double ans = 0;
	for(int i=1 ; i<=n ; i++)
		scanf(" %lf %lf",&x[i],&y[i]);
	for(int i=1 ; i<=n ; i++)
		for(int j=i+1 ; j<=n ; j++)
			for(int k=j+1 ; k<=n ; k++)
				ans = max(ans, area(i, j, k));
	printf("%.3lf\n",ans);
	return 0;
}
