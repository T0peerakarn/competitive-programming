#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> dom = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int d, m;
	scanf(" %d %d",&d,&m);
	for(int i=0 ; i<m ; i++) d += dom[i];
	d %= 7;
	if(d == 0) printf("Wednesday\n");
	else if(d == 1) printf("Thursday\n");
	else if(d == 2) printf("Friday\n");
	else if(d == 3) printf("Saturday\n");
	else if(d == 4) printf("Sunday\n");
	else if(d == 5) printf("Monday\n");
	else printf("Tuesday\n");
	return 0;
}
