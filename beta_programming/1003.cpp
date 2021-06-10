#include <bits/stdc++.h>
using namespace std;

bool mark[110];

int main()
{
	vector<int> v = {6, 9, 20};
	mark[0] = true;
	for(int i=1 ; i<=100 ; i++)
		for(int j=0 ; j<3 ; j++)
			if(i >= v[j] && mark[i-v[j]]) mark[i] = true;
	int n;
	bool ch = false;
	scanf(" %d",&n);
	for(int i=1 ; i<=n ; i++) if(mark[i]) ch = true, printf("%d\n",i);
	if(!ch) printf("no\n");
	return 0;
}
