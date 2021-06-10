#include <bits/stdc++.h>
using namespace std;
int main()
{
	int A, B, C;
	scanf(" %d %d %d",&A,&B,&C);
	for(int a=1 ; a<=100 ; a++)
	{
		if(A%a) continue;
		int c = A/a;
		for(int b=-10000 ; b<=10000 ; b++)
		{
			if(b == 0 || C%b) continue;
			int d = C/b;
			if(a*d + b*c == B)
			{
				printf("%d %d %d %d\n",a,b,c,d);
				return 0;
			}
		}
	}
	printf("No Solution\n");
	return 0;
}
