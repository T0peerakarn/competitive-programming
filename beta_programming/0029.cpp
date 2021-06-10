#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	scanf(" %d %d",&a,&b);
	if(a > b) printf("2\n"); 
	for(int i=1 ; true ; i++)
		if(i*a >= b)
		{
			printf("%d\n",i);
			return 0;
		}
	return 0;
}
