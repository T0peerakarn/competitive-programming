#include <bits/stdc++.h>
using namespace std;

int main()
{
	int sum = 0;
	for(int i=0 ; i<3 ; i++)
	{
		int d;
		scanf(" %d",&d);
		sum += d;
	}
	if(sum >= 80) printf("A\n");
	else if(sum >= 75) printf("B+\n");
	else if(sum >= 70) printf("B\n");
	else if(sum >= 65) printf("C+\n");
	else if(sum >= 60) printf("C\n");
	else if(sum >= 55) printf("D+\n");
	else if(sum >= 50) printf("D\n");
	else printf("F\n");
	return 0;
}
