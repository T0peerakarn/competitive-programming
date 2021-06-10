#include <bits/stdc++.h>
using namespace std;

bool sus[9];

int main()
{
	vector<int> v(9);
	int sum = -100;
	for(auto &x : v)
	{
		scanf(" %d",&x);
		sum += x;
	}
	for(int i=0 ; i<9 ; i++)
		for(int j=i+1 ; j<9 ; j++)
			if(v[i] + v[j] == sum)
			{
				sus[i] = sus[j] = true;
				break ;
			}
	for(int i=0 ; i<9 ; i++) if(!sus[i]) printf("%d\n",v[i]);
	return 0;
}
