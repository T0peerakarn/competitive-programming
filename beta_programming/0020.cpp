#include <bits/stdc++.h>
using namespace std;

int score[6];

int main()
{
	int p = 0;
	for(int i=1 ; i<=5 ; i++)
	{
		for(int j=0 ; j<4 ; j++)
		{
			int d;
			scanf(" %d",&d);
			score[i] += d;
		}
		if(score[i] > score[p]) p = i;
	}
	printf("%d %d\n",p,score[p]);
	return 0;
}
